You are tasked with implementing a simple Student Registration System in C++. Define two structures,
Register and Student, where Register contains attributes courseId and courseName, and Student inherits
from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and
email. Your goal is to create an array of Student structures to store information for five students. Write a
C++ program that accomplishes the following tasks:
 Implement the Register and Student structures.
 Inherit the Register structure in the Student structure.
 Create an array of Student structures to store information for 5 students.
 Take input for each student, including their courseId, courseName, studentId, firstName,
lastName, cellNo, and email.
 Display the information for all 5 students.


  
#include <iostream>
#include <string>
using namespace std;

struct Register {
    int courseID;
    string courseName;
};

struct Student {
    int studentID;
    string firstName;
    string lastName;
    long cellNo;
    string email;
    Register s1;
};

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();  

    Student arr[numStudents];  

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter the Information of Student " << i + 1 << endl;

        cout << "Enter the courseID: ";
        cin >> arr[i].s1.courseID;
        cin.ignore(); 
        
        cout << "Enter your Course Name: ";
        getline(cin, arr[i].s1.courseName);  

        cout << "Enter your Student ID: ";
        cin >> arr[i].studentID;
        cin.ignore();

        cout << "Enter your First Name: ";
        getline(cin, arr[i].firstName);

        cout << "Enter your Last Name: ";
        getline(cin, arr[i].lastName);

        cout << "Enter your cell Number: ";
        cin >> arr[i].cellNo;
        cin.ignore(); 

        cout << "Enter your Email: ";
        getline(cin, arr[i].email);
    }

    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << " Information: " << endl;
        cout << "Course ID: " << arr[i].s1.courseID << endl;
        cout << "Course Name: " << arr[i].s1.courseName << endl;
        cout << "Student ID: " << arr[i].studentID << endl;
        cout << "First Name: " << arr[i].firstName << endl;
        cout << "Last Name: " << arr[i].lastName << endl;
        cout << "Cell Number: " << arr[i].cellNo << endl;
        cout << "Email: " << arr[i].email << endl;
    }

    return 0;
}
