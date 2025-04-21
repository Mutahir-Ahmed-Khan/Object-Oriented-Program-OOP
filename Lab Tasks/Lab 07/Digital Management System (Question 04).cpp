#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person() {}

    void displayInfo() {
        cout << "Displaying personal details of the person.\n";
    }

    void updateInfo() {
        cout << "Updating personal details of the person.\n";
    }
};

class Student : public Person {
private:
    string coursesEnrolled;
    float GPA;
    int enrollmentYear;

public:
    void displayInfo() {
        cout << "Displaying student academic records.\n";
    }
};

class Professor : public Person {
private:
    string department;
    string coursesTaught;
    float salary;

public:
    void displayInfo() {
        cout << "Displaying professor's faculty-specific details.\n";
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    float salary;

public:
    void displayInfo() {
        cout << "Displaying administrative staff details.\n";
    }
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    void registerStudent(Student student) {
        cout << "Registering a student in the course.\n";
    }

    void calculateGrades() {
        cout << "Calculating grades for the course.\n";
    }
};
