#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
using namespace std;

// Composition in Students, if a student object is deleted, fee pickup and drop-off would be deleted too
//Aggrigation in bus, if a bus object is deleted the students would remain
//Comments are for own Understanding

//-----------NEW ------------------------
class Person{
    public:
    string name;
    int ID; 

    Person(){
        cout << right << setw(30)<< "I am the constructor of Person " << endl;
    }

    ~Person(){
        cout <<"I am the Destructor of Person" << endl;
    }
    virtual void Pay(int fee) = 0;

    
    virtual int login() = 0;

    //----------------------------------------------------------------------------------------------- FILING -----------------------------------------------------------------//
    void saveAdmin(Person* p) {
        ofstream out("admin.bin", ios::binary | ios::out | ios::trunc);
    
        int count = 1; 
        out.write((char*)&count, sizeof(count));
        out.write((char*)p, sizeof(*p)); 
        cout << "Saved to File" << endl;
        out.close();
    }
    
    void loadAdmin(Person* &p) {
        ifstream in("admin.bin", ios::binary | ios::in);
    
        if (!in) {
            cout << "No admin file found!" << endl;
            return;
        }
    
        int count;
        in.read((char*)&count, sizeof(count));
        in.close();
    }
    //----------------------------------------------------------------------------------------------- FILING -----------------------------------------------------------------//
};

class Students {
private:
    int studentID;
    string name;
    string department;
    string isActive;
    string pickUp;
    string dropOff;
    int fee;
    const int actualFee = 40000; 
   
    public:
  
    Students() : 
        studentID(0), name(""), department(""), isActive("Inactive"), pickUp(""), dropOff("") ,fee(0) {}

    
    void setID(int studentID){
        this -> studentID = studentID;
    }
    int getID(){
        return studentID;
    }

    void setName(string name){
        this-> name = name;
    }
    string getName(){
        return name;
    }

    void setDepartment(string department){
        this -> department = department;
    }
    string getDepartment(){
        return department;
    }

    string getIsActive(){
        return isActive;
    }

   
    void makePayment(int fee){
        this -> fee = fee;
        if(this-> fee >= actualFee){
            cout << "Cleared the Transport Fee" << endl;
            isActive = "Active";
        }
        else{
            isActive = "InActive";
            cout << "Fee is Not Cleared" << endl;
        }
    }
    
    
    void setPickUp(string pickUp){
        this -> pickUp = pickUp;
    }
    void setDropOff(string dropOff){
        this -> dropOff = dropOff;
    }
    string getPickUp(){
        return pickUp;
    }
    string getDropOff(){
        return dropOff;
    }

    //----------------------------------------------------------------------------------------------- FILING -----------------------------------------------------------------//
    void saveToFile() {
        ofstream out("students.bin", ios::binary | ios::out | ios::trunc);

        if (out.fail() || out.bad()) {
            cout << "File write failed!" << endl;
        }

        int count = 1; 
        out.write((char*)&count, sizeof(count)); 

        out.write((char*)this, sizeof(*this)); 
        cout << "Saved to File" << endl; 
        out.close();
        
    }

    void loadFromFile() {
        ifstream in("students.bin", ios::binary | ios::in);

        if (!in) {
            cout << "No student file found!" << endl;
            return;
        }

        if (in.fail()) {
            cout << "Logical error on input operation" << endl;
        }
        if (in.bad()) {
            cout << "Read/writing error on input operation" << endl;
        }

        int count;
        in.read((char*)&count, sizeof(count));

        if (count > 0) {
            in.read((char*)this, sizeof(*this));
        }

        in.close();
    }
    //----------------------------------------------------------------------------------------------- FILING -----------------------------------------------------------------//

};

class Attendance{
    public:
    string* attendance;

    public:
    
    Attendance(){
        try {
            attendance = new string[30];
            for (int i = 0; i < 30; i++) {
                attendance[i] = "*";
            }
        } catch (bad_alloc &e) {
            cout << "Memory allocation failed in Attendance constructor: " << e.what() << endl;
        }
    } 
    
    ~Attendance() {
        delete[] attendance;
    }

    
    void setAttendance(int Date,string status){
        if(Date >= 1 && Date <= 31){
            this -> attendance[Date - 1] = status;
        }
        else{
            cout << "Re-Enter Day is Not Corrrect";
        }
    }

    string getAttendance(int Date) {
        if (Date >= 1 && Date <= 30) {
            return attendance[Date - 1];
        } else {
            return "Invalid Date!";
        }
    }
    
    //----------------------------------------------------------------------------------------------- FILING -----------------------------------------------------------------//
    void saveAttendance(Attendance& att) {
        ofstream out("attendance.bin", ios::binary | ios::out | ios::trunc);
        int days = 30;
        out.write((char*)&days, sizeof(days));
        for (int i = 0; i < 30; i++) {
            int len = att.attendance[i].length();
            out.write((char*)&len, sizeof(len));
            out.write(att.attendance[i].c_str(), len);
        }
        out.close();

        cout << "Saved to File" << endl;
    }
    
    void loadAttendance(Attendance& att) {
        ifstream in("attendance.bin", ios::binary | ios::in);
        if (!in) {
            cout << "No attendance file found!" << endl;
            return;
        }
        int days;
        in.read((char*)&days, sizeof(days));
        for (int i = 0; i < days; i++) {
            int len;
            in.read((char*)&len, sizeof(len));
            char* temp = new char[len + 1];
            in.read(temp, len);
            temp[len] = '\0';
            att.attendance[i] = temp;
            delete[] temp;
        }
        in.close();
    }
    
    //----------------------------------------------------------------------------------------------- FILING -----------------------------------------------------------------//
};

class Bus {
    private:
        string busID;
        string routeID;
        int capacity;
        int assignedStudents[10];
        int studentCount;
    
    public:
    
        Bus(string id, string route, int cap) : busID(id), routeID(route), capacity(cap), studentCount(0) {
            for (int i = 0; i < 10; i++) {
                assignedStudents[i] = 0;
            }
        }
    
        void assignStudent(int studentID) {
            if (studentCount < capacity) {
                assignedStudents[studentCount++] = studentID;
                cout << "Student " << studentID << " assigned to Bus " << busID << endl;
            } else {
                cout << "Bus " << busID << " is full! Cannot assign more students." << endl;
            }
        }
    
        void displayBusInfo() {
            cout << "----------------------------------" << endl;
            cout << "Bus ID: " << busID << endl;
            cout << "Route ID: " << routeID << endl;
            cout << "Capacity: " << capacity << endl;
            cout << "Assigned Students: " << (studentCount > 0 ? "" : "None") << endl;
            
            for (int i = 0; i < studentCount; i++) {
                cout << "- " << assignedStudents[i] << endl;
            }
    
            cout << "----------------------------------" << endl;
        }
    };

//------------------------------------------------------- NEW ----------------------------------------------------------------
class teacher : public Person{
    private: 
    string subject;
    int teacherFee = 7000;

    public:

    teacher() : Person() {
        cout << right  << setw(30)<<"I am the constructor of Teacher" << endl;
    }

    ~teacher(){
        cout << "I am the Destructor of the " << name << endl;
    }

    
    void setSubject(string subject){
        this-> subject = subject;
    }
    string getSubject(){
        return subject;
    }

    void Pay(int fee) override {
        if (fee >= teacherFee) {
            cout << "Teacher's : Payment Cleared" << endl;
        } 
        else {
            cout << "Insufficient amount. Payment Pending" << endl;
        }
    }

    int login() override{
        int pass;
        cout << "Enter the Password: ";
        cin >> pass;

        return pass;
    }

};

class staff: public Person{
    public: 
    string Area;
    const int staffFee = 5000;

    public: 

    staff() : Person(){
        cout <<"I am the Constructor of Staff" << endl;
    }

    ~staff(){
        cout << "I am the Destructor of the " << name << endl;
    }

    void setArea(string Area){
        this -> Area = Area;
    }
    string getArea(){
        return Area;
    }

    void Pay(int fee) override {
        if (fee >= staffFee) {
            cout << "Staff : Payment Cleared" << endl;
        } 
        else {
            cout << "Insufficient amount. Payment Pending" << endl;
        }
    }

    int login() override{
        int otp;
        cout << "Enter the OTP: ";
        cin >> otp;

        return otp;
    }
    
};

void routine (Students std, Attendance att){
    std.loadFromFile();
    att.loadAttendance(att);
}
    

int main() {
    Bus bus1("B001", "Route A", 5);
    Bus bus2("B002", "Route B", 7);
    Bus bus3("B003", "Route C", 6);
    Students student01;
    Attendance attendance;
    int id,opt,f,date,busChoice,adminChoice,pay,fee,Id;
    string n,d,drop,pick,att;
    bool end = true;
    Person *ptr = nullptr;

    routine(student01,attendance);

    while(end){
        cout << "-------------------" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Register for the Bus" << endl;
        cout << "3. Make Payment" << endl;
        cout << "4. Set Drop Off and Pick Up" << endl;
        cout << "5. Record The Attendance" << endl;
        cout << "6. Display Student's Info" << endl;
        cout << "7. For Admin" << endl; 
        cout << "8. Make Payments for Staff and Teachers" << endl;
        cout << "(-1) to Exit the system" << endl;
        cout << "-------------------" << endl;
        cout << "Enter the Option: ";
        cin >> opt;

        switch(opt){
            case 1:
                cout << "*********************" << endl;
                cout << "Enter the Student ID: ";
                cin >> id;
                student01.setID(id);

                cout << "Enter the Name: ";
                cin.ignore();
                getline(cin,n);
                student01.setName(n);

                cout << "Enter the Department: ";
                getline(cin,d);
                student01.setDepartment(d);
                cout << "*********************" << endl;

                student01.saveToFile();  
                break;
            case 2:
                bus1.displayBusInfo();
                bus2.displayBusInfo();
                bus3.displayBusInfo();
                cout << "Select Bus (1, 2, or 3): ";
                cin >> busChoice;

                if (busChoice == 1) {
                    bus1.assignStudent(id);
                }
                else if (busChoice == 2){
                    bus2.assignStudent(id);
                }
                else if (busChoice == 3) {
                    bus3.assignStudent(id);
                }
                else {
                    cout << "Invalid Bus Selection" << endl;
                }
                break;
            case 3:
                cout << "Enter the Fee: ";
                cin >> f;
                student01.makePayment(f);
                cout << student01.getName() << "'s" <<" ("<< student01.getID() << ") "<< "Card: " << student01.getIsActive() << endl;

                break;
            case 4:
                if(student01.getIsActive() == "Active"){
                    cout << "Enter the Pick Up: ";
                    cin.ignore();
                    getline(cin,pick);
                    student01.setPickUp(pick);

                    cout << "Enter the Drop Off: ";
                    cin.ignore();
                    getline(cin,drop);
                    student01.setDropOff(drop);

                    student01.saveToFile(); 
                }
                else{
                    cout << "Clear Payment First" << endl;
                }
                break;
            case 5:
                cout << "Enter the Date: ";
                cin >> date;
                cout << "(Present/Absent): ";
                cin >> att;
                attendance.setAttendance(date,att);
                cout << "Attendance recorded for Day " << date << ": " << attendance.getAttendance(date) << endl;

                attendance.saveAttendance(attendance);
                break;
            case 6:
                cout << "****************************************" << endl;
                cout << "Name: " << student01.getName() << endl;
                cout << "Roll No: " << student01.getID() << endl;
                cout << "Department: " << student01.getDepartment() << endl;
                cout << "Card Status: " << student01.getIsActive() << endl;
                cout << "While Going-- "<<"Pick Up:" << student01.getPickUp() << " :: " << "Drop Off:" << student01.getDropOff() << endl;
                cout << "While Coming Back-- " <<"Pick Up:" << student01.getDropOff() << " :: " << "Drop Off:" << student01.getPickUp() << endl;
                cout << "----------- Attendace ----------" << endl;
                    for(int i = 0; i < 30; i++){
                        cout << "Day " << i+1 << ":" << attendance.getAttendance(i+1) << endl;
                    }
                cout << "--------------------------------" << endl;
                cout << "****************************************" << endl;
                end = false;
                break;
            case 7:
                    if (ptr){
                        delete ptr;
                        ptr = nullptr;
                    }
                    cout << "-------------------" << endl;
                    cout << "1. Teacher " << endl;
                    cout << "2. Staff " << endl;
                    cout << "-------------------" << endl;
                    cout << "Enter the Choice: " ;
                    cin >> adminChoice;

                    switch(adminChoice){
                        case 1: 
                            ptr = new teacher();

                            if(ptr->login() == 123){
                                cout << "Enter the Name: ";
                                cin.ignore();
                                getline(cin, ptr->name);

                                cout << "Enter the ID: ";
                                cin >> ptr->ID;
                                ptr->saveAdmin(ptr);
                            }
                            else{
                                cout << "Wrong Password" << endl;
                            }
                            break;
                        case 2: 
                            ptr = new staff();

                            if(ptr->login() == 112233){
                                cout << "Enter the Name: ";
                                cin.ignore();
                                getline(cin, ptr->name);

                                cout << "Enter the ID: ";
                                cin >> ptr->ID;
                                ptr->saveAdmin(ptr);
                            }
                            else{
                                cout << "Wrong OTP" << endl;
                            }
                            break;
                        }
                break;
            case 8:
            if (ptr) {
                cout << "Enter Fee Amount: ";
                cin >> fee;
                ptr->Pay(fee);
            } else {
                cout << "No person registered yet" << endl;
            }
            break;
            break;
            case -1:
                cout << "Exiting the System...." << endl;
                end = false;
                break;
            default:
                    cout << "See the Menu Again and Choose The Option Again" << endl;  
        }
    }

    return 0;

}
