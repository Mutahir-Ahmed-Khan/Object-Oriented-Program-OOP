#include<iostream>
using namespace std; 

class Vehicle{
	private:
		string model;
		double rate;
	
	public:
		Vehicle(string m, double r) : model(m), rate(r) {}
		
		virtual double getDailyRate() = 0;
		virtual void displayDetails() = 0;
		
		//Getter and Setter
		string getModel(){
			return model;
		} 
		double getRate(){
			return rate;
		}
};

class Car : public Vehicle{
	public:
		Car(string m, double r) : Vehicle(m,r) {}
		
		double getDailyRate() override{
			cout << "Presenting Daily Rates of Car" << endl;
		}
		
		void displayDetails() override{
			cout << "Model: " << getModel() << endl;
			cout << "Rate: " << getRate() << endl;
		}
};
class Bike:public Vehicle{
	public:
		Bike(string m, double r) : Vehicle(m,r) {}
		double getDailyRate() override{
			cout << "Presenting Daily Rates of Bike" << endl;
		}
		
		void displayDetails() override{
			cout << "Model: " << getModel() << endl;
			cout << "Rate: " << getRate() << endl;
		}
		
};
int main(){
	Vehicle *ptr;
	Car obj1("mercedes",500005);
	Bike obj2("BMW",768686);
	ptr=&obj1;
	ptr->getDailyRate();
	ptr->displayDetails();
	ptr=&obj2;
	ptr->getDailyRate();
	ptr->displayDetails();
	return 0;
}

