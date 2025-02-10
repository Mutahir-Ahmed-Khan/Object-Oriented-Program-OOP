#include <iostream>
using namespace std;

class Car{
	public:
	int carID;
	string Model;
	int year;
	bool isRented;
	
	//Constructor 01
	Car() : isRented(false) {}
	
	//Constructor 02
	Car(int carID, string Model, int year, bool isRented){
		this -> carID = carID;
		this -> Model = Model;
		this -> year = year; 
		this -> isRented = isRented;
	}
	
	//rentCar
	void rentCar(){
		if(isRented == false){
			isRented = true;
			cout << Model << " : "<< "Car is Reneted SuccessFully" << endl;
		}
		else{
			cout << Model << " : "<< "Car Cannot be Rented" << endl;
		}
	}
	
	//returnCar
	int returnCar(){
		if(isRented == false){
			cout << Model << " : " << "Car Retruned Successfully" << endl;
			return 1;
		}
		else{
			cout << Model << " : " << "Car is not returned yet" << endl;
		}
	}
	
	//isVintage
	int isVintage(){
		if(year < 2000){
			cout << Model << " : " << "Car is too Old!" << endl;
			return 1;
		}
		else{
			cout << Model << " : " << "Car is not Old" << endl;
		}
	}
	
	
};

int main(){
Car car01(63,"Amg C63",1999, false);
car01.isVintage();
car01.isRented();
car01.returnCar();

}
