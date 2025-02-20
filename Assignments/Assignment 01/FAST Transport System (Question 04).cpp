#include <iostream>
using namespace std;

class Students {
public:
    int studentID;
    string name;
    string Active;
    int fee;

    // Constructor 
    Students(int id, string n, string a, int f) 
        : studentID(id), name(n), Active(a), fee(f) {}

    //Displaying to Check wether the codes run or not
    void displayInfo() {
        cout << "Student ID: " << studentID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Status: " << Active << "\n";
        cout << "Fee Paid: " << fee << "\n\n";
    }
};

class Transport {
    const float actualFee = 40000; 
public:
    void isFee(Students* st) { 
        if (st->fee >= actualFee) {
            cout << "Student " << st->name << " has cleared the transport fee" << endl;
            st->Active = "Active";
        } else {
            cout << "Student " << st->name << " has not cleared the fee" << endl;
            st->Active = "Inactive";
        }
    }
};

class Bus{

};

int main() {
    Students student1(1030, "Mutahir", "Inactive", 50000);
    Transport transport;
  
    student1.displayInfo();
    transport.isFee(&student1);
    student1.displayInfo();

    return 0;
}
