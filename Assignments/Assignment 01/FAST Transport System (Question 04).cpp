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

// class Bus{
// };

// class attendance{
// };



int main() {
    Students student01;
    int id,opt,f;
    string n,d,drop,pick;
    bool end = true;

    while(end){
        cout << "-------------------" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Make Payment" << endl;
        cout << "3. Set Drop Off and Pick Up" << endl;
        cout << "(-1) to exit the system" << endl;
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
                cin.ignore();
                getline(cin,n);
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
            case -1:
                cout << "Exiting the System...." << endl;
                end = false;
                break;
        }
    }

}
