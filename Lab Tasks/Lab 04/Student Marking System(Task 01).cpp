#include <iostream>
using namespace std;

class student{
	public:
	int studentID;
	string name;
	int age;
	char grade;
	
	//Construtor 01
	student() : grade('N') {}
	
	//Constructor 02
	student(int studentID, string name, int age, char grade){
		this -> studentID = studentID;
		this -> name = name;
		this -> age = age;
		this -> grade = grade;
	}
	
	//Upgarding Student 
	void promoteStudent(){
		if (grade == 'A'){
			cout << "Student at Highest Grade" << endl;
		}
		else{
			grade--;
			cout << "The Student's Grade is Upgraded" << endl;
		}
	}
	
	//isEgligibleForScholarship
	int isEgligibleForScholarship(){
		if(grade == 'A'){
			return 1;
		}
		else {
			return 0;
		}
	}
	
	void displayDetails(){
		cout << "--------------------" << endl;
		cout << "Student ID: " << studentID << endl;
		cout << "Student Name: " << name << endl;
		cout << "Age: " << endl;
		cout << "Grade: " << grade << endl;
		cout << "--------------------" << endl;
		
	}
};


int main(){
	//Test Cases
	student student01(240030,"Mutahir",18,'B');
	student student02(245557,"Faraz",18,'B');
	
	student01.displayDetails();
	
	if(student01.isEgligibleForScholarship() == 1){
		cout << "Egligible for the Scholrship" << endl;
	}
	else {
		cout << "Not Egligible for ScholarShip" << endl;
	}

	//Promoting
	student02.promoteStudent();
	student02.displayDetails();
;}
