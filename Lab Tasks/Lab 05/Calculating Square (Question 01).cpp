#include <iostream>
using namespace std; 

class Square{
	public:
	float sideLength; 
	float area;
	static float allAreas;
	
	//Constructor
	Square() {}
	
	Square(float s) : sideLength(s) {}
	
	//Function to calculate Area
	void calcArea(){
		area = sideLength * sideLength;
		allAreas += area;
	}
	
	//Getter and Setter 
	void setSideLength(float sideLength){
		this -> sideLength = sideLength;
	}
	float getSideLength(){
		return sideLength;
	}
	
	void setArea(float area){
		this -> area = area;
	}
	float getArea(){
		return area;
	}
	
	static float getAllAreas(){
		return allAreas;
	}
};

float Square :: allAreas = 0.0f;

int main(){
	Square s1(2);
	Square s2(3);
	Square s3(4);
	
	s1.calcArea();
	cout << "The Area of the First Square: " << s1.getArea() << " All Areas: " << s1.getAllAreas() << endl;
	
	s2.calcArea();
	cout << "The Area of the First Square: " << s2.getArea() << " All Areas: " << s2.getAllAreas() << endl;
	
	s3.calcArea();
	cout << "The Area of the First Square: " << s3.getArea() << " All Areas: " << s3.getAllAreas() << endl;
	
	
	return 0;
}
