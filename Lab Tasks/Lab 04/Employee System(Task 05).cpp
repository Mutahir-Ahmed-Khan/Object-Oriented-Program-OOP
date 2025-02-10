#include <iostream>
using namespace std;

class Employee{
	public:
	int employeeID;
	string name;
	string department;
	double salary;
	
	//Constructor 01
	Employee() : salary(0.0) {}
	
	//Constructor 02
	Employee(int employeeID, string name, string department, double salary){
		this -> employeeID = employeeID;
		this -> name = name;
		this -> department = department ;
		this -> salary = salary;
	}
	
	//Give Bonus 
	void giveBonus(double amount){
		salary += amount;
	}
	
	//isManager
	int isManager(){
		if(department == "Management" || department == "management"){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	//displayDetails
	void displayDetails(){
		cout << "--------------------" << endl;
		cout << "Name: " << name << endl; 
		cout << "Employee ID: " << employeeID << endl; 
		cout << "Department: " << department << endl;
		cout << "Salary: " << salary << endl;
		cout << "--------------------" << endl;
	}
};

int main(){
	Employee employee;
	employee.displayDetails();
}
