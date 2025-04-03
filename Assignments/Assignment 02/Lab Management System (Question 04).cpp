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

        for (int i = 0; i < size; i++) {
            permissions[i] = "---";
        }
        cout << right << setw(30) << "*---(User Created)---*" << endl;
    }
    
    // Destructor
    ~User() {
        delete[] permissions;
    }
    
    // Display Function
    virtual void display() {
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
        cout << right << setw(28) << "----- Student -----" << endl;
    }

    // List of Assignments
    void listOfAssignments(int assignNum) {
        string assignments[assignNum];
        int num;

        for (int i = 0; i < assignNum; i++) {
            assignments[i] = "Not Submitted";
        }
        
        // Display the assignments
        for (int i = 0; i < assignNum; i++) {
            cout << "Assignment #" << i + 1 << ": " << assignments[i] << endl;
        }
        cout << right << setw(30) << "*********************************************" << endl;

        cout << "\nSubmit Assignment: " << endl;
        do {
            cout << "Enter Assignment # to Submit (or -1 to quit): ";
            cin >> num;
            cin.ignore(); 
        
            if (num == -1) {
                break; 
            }
            if (num > assignNum || num < 1) {
                cout << "Invalid Assignment Number" << endl;
            }
            else {
                assignments[num - 1] = "Submitted";
                if (status < assignNum) {
                    status++;
                }
            }
        } while (true);

        for (int i = 0; i < assignNum; i++) {
            cout << "Assignment #" << i + 1 << ": " << assignments[i] << endl;
        }
        cout << right << setw(30) << "*********************************************" << endl;
    }
};

class TA : public Student {
private:
    Student* assignedStudents[10]; 
    string projects[2]; 
    int studentCount = 0;

public:
    // Constructor
    TA(string n, int id, string e, string p) : Student(n, id, e, p) {
        cout << right << setw(28) << "----- TA -----" << endl;
        for (int i = 0; i < 2; i++) {
            projects[i] = "No Project Assigned";
        }
    }

    // Function to assign students to the TA
    bool assignStudent(Student* student) {
        if (studentCount < 10) {
            assignedStudents[studentCount] = student;
            studentCount++;
            return true;
        } else {
            cout << "TA has reached the maximum number of students (10)." << endl;
            return false;
        }
    }

    // Function to start a project
    bool startProject(string projectName) {
        for (int i = 0; i < 2; i++) {
            if (projects[i] == "No Project Assigned") {
                projects[i] = projectName;
                return true;
            }
        }
        cout << "Cannot start more than 2 projects." << endl;
        return false;
    }

    // Function to view current projects
    void viewProjects() {
        cout << "Current Projects: " << endl;
        for (int i = 0; i < 2; i++) {
            cout << "Project #" << i + 1 << ": " << projects[i] << endl;
        }
    }

    // Overriding the display function
    void display() override {
        Student::display();
        cout << right << setw(30) << "Assigned Students: " << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << right << setw(30) << "Student #" << i + 1 << ": " << assignedStudents[i]->getPermission()[0] << endl;
        }
        viewProjects();
    }
};

class Professor : public User {
private:
    TA* taList[5];
    int taCount = 0;

public:
    // Constructor
    Professor(string n, int id, string e, string p) : User(n, id, e, 1, p) {
        cout << right << setw(28) << "----- Professor -----" << endl;
    }

    // Function to assign TAs
    bool assignTA(TA* ta) {
        if (taCount < 5) {
            taList[taCount] = ta;
            taCount++;
            return true;
        } else {
            cout << "Professor has reached the maximum number of TAs (5)." << endl;
            return false;
        }
    }

    // Overriding the display function
    void display() override {
        User::display();
        cout << right << setw(30) << "Assigned TAs: " << endl;
        for (int i = 0; i < taCount; i++) {
            taList[i]->display();
        }
    }
};

int main() {
    Student s1("Mutahir", 1020, "MutahirHere18@gmail.com", "MAK000");
    s1.display();
    s1.listOfAssignments(3);

    TA ta1("John", 2001, "JohnDoe@gmail.com", "TA123");
    ta1.startProject("Project 1");
    ta1.startProject("Project 2");
    ta1.assignStudent(&s1);
    ta1.display();

    Professor prof1("Dr. Smith", 3001, "DrSmith@gmail.com", "ProfPass");
    prof1.assignTA(&ta1);
    prof1.display();

    return 0;
}
