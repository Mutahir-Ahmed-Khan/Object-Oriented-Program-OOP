#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Global Function of Hash
string GenHash(string pass) {
    int hash = 5381;
    string hashed = "";  
    int sizeOfPass = pass.length();

    for (int i = 0; i < sizeOfPass; i++) {
        hash = hash * 33 + pass[i]; 
        hashed += char(hash % 128);  
    }
    return hashed;
}

class User {
private:
    string name;
    int ID;
    string email;
    string* permissions; 
    string Pass;
    string finalHashPass;
    int size;
public:
    // Constructor
    User(string n, int id, string e, int tempSize, string p) 
        : name(n), ID(id), email(e), Pass(p) {
        size = tempSize;
        permissions = new string[size];
        finalHashPass = GenHash(p);  

        for(int i = 0; i < size; i++) {
            permissions[i] = "---";
        }
        cout << right << setw(30) << "*---(User Created)---*" << endl;
    }
    // Destructor
    ~User() {
        delete[] permissions;
    }
    // Display Function
    void display() {
        cout << right << setw(30) << "*********************************************" << endl;
        cout << right << setw(19) << "NAME: " << name << endl;
        cout << right << setw(20) << "EMAIL: " << email << endl;
        cout << right << setw(17) << "ID: " << ID << endl;
        cout << right << setw(30) << "PASSWORD (Hash): " << finalHashPass << endl;
        for (int i = 0; i < size; i++) {
            cout << right << setw(25) << "Permission #" << i + 1 << ": " << permissions[i] << endl;
        }
        cout << right << setw(30) << "*********************************************" << endl;
    }
    // Authentication Function
    void authenticate() {
        string enterPass;
        cout << "Enter the Password: ";
        getline(cin, enterPass);  

        if (GenHash(enterPass) == finalHashPass) {
            cout << "Verified" << endl;
        } else {
            cout << "Not Verified" << endl;
        }
    }
    // Getter for permissions
    string* getPermission() {
        return permissions;
    }
};

class Student : public User {
public:
    int status = 0;
    // Constructor
    Student(string n, int id, string e, string p) : User(n, id, e, 1, p) {
        getPermission()[0] = "Only Allowed to submit Assignments";
        cout << right << setw(29) << "----- Students -----" << endl;
    }
    // List of Assignments
    void listOfAssignments(int assignNum) {
        string assignments[assignNum];
        int num;

        for (int i = 0; i < assignNum; i++) {
            assignments[i] = "Not Submitted";
        }

        for (int i = 0; i < assignNum; i++) {
            cout << "Assignment #" << i + 1 << ": " << assignments[i] << endl;
        }
        cout << right << setw(30) << "*********************************************" << endl;
        cout << "\n";

        cout << "Submit Assignment: " << endl;
        do {
            cout << "Enter Assignment # to Submit (or -1 to quit): ";
            cin >> num;
            cin.ignore(); 

            if (num > assignNum || num < -1) {
                cout << "Invalid Assignment Number" << endl;
                if(num == -1){
                    status--;
                }
            }
            else if (num >= 1 && num <= assignNum) {
                assignments[num - 1] = "Submitted";
                if(status < assignNum){
                    status++;
                }
            }
        } while (num != -1);

        cout << "\n";

        cout << right << setw(30) << "*********************************************" << endl;
        cout << "Updated Assignments List:" << endl;
        for (int i = 0; i < assignNum; i++) {
            cout << "Assignment #" << i + 1 << ": " << assignments[i] << endl;
        }
        cout << right << setw(30) << "*********************************************" << endl;
    }
};

int main() {
    Student s1("Mutahir", 1020, "MutahirHere18@gmail.com", "MAK000");
    s1.display();
    s1.listOfAssignments(3);  

    return 0;
}
