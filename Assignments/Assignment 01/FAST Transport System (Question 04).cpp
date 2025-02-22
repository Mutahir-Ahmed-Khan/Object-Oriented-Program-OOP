#include <iostream>
using namespace std;

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
    //Constructor
    Students() : 
        studentID(0), name(""), department(""), isActive("Inactive"), pickUp(""), dropOff("") ,fee(0) {}

    //Getter and Setters
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

    //Make Payment
    void makePayment(int fee){
        this -> fee = fee;
        if(this-> fee >= actualFee){
            cout << "Cleared the Transport Fee" << endl;
            isActive = "Active";
        }
        else{
            isActive = "Not Active";
            cout << "Fee is Not Cleared" << endl;
        }
    }
    
    //Assigning Stops
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

};

class Attendance{
    public:
    string* attendance;

    public:
    //DMA
    Attendance(){
        attendance = new string[30];
        for (int i = 0; i < 30; i++) {
            attendance[i] = "*"; 
        }
    } 
    // Destructor 
    ~Attendance() {
        delete[] attendance;
    }

    //Recording Attendance
    void setAttendance(int Date,string status){
        if(Date >= 1 && Date <= 31){
            this -> attendance[Date - 1] = status;
        }
        else{
            cout << "Re-Enter Day is Not Corrrect";
        }
    }

    string getAttendance(int Date) {
            return attendance[Date - 1];
    }
    
    
};
// class Bus{
// };





int main() {
    Students student01;
    Attendance attendance;
    int id,opt,f,date;
    string n,d,drop,pick,att;
    bool end = true;

    while(end){
        cout << "-------------------" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Make Payment" << endl;
        cout << "3. Set Drop Off and Pick Up" << endl;
        cout << "4. Display Student's Info" << endl;
        cout << "5. Record The Attendance" << endl;
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
                break;
            case 2:
                cout << "Enter the Fee: ";
                cin >> f;
                student01.makePayment(f);
                cout << student01.getName() << "'s" <<" ("<< student01.getID() << ") "<< "Card: " << student01.getIsActive() << endl;
                break;
            case 3:
                if(student01.getIsActive() == "Active"){
                    cout << "Enter the Pick Up: ";
                    cin.ignore();
                    getline(cin,pick);
                    student01.setPickUp(pick);

                    cout << "Enter the Drop Off: ";
                    cin.ignore();
                    getline(cin,drop);
                    student01.setDropOff(drop);
                }
                else{
                    cout << "Clear Payment First" << endl;
                }
                break;
            case 4:
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
                break;
            case 5:
                cout << "Enter the Date: ";
                cin >> date;
                cout << "(Present/Absent): ";
                cin >> att;
                attendance.setAttendance(date,att);
                cout << "Attendance recorded for Day " << date << ": " << attendance.getAttendance(date) << endl;
                break;
            case -1:
                cout << "Exiting the System...." << endl;
                end = false;
                break;
        }
    }

}
