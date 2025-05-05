#include <iostream>
#include <fstream>
using namespace std;

int  main(){
	char buffer[9] ={0};
	ofstream file;
	file.open("info.txt",ios::out);
	file <<"C++ is a powerful programming language.\n";
	file.close();
	fstream file1;
	file1.open("info.txt",ios::in|ios::out);
	streampos pos = file1.tellg();
	cout <<"get Pointer position : "<<pos<<endl;
	pos = file1.tellp();
	cout <<"Put Pointer Position : "<<pos <<endl;
	file1.seekg(9);
	file1.read(buffer,8);
	cout <<buffer<<endl;
	file1.seekp(9);
	file1.write("Dynamicc",8);
	
	pos = file1.tellg();
	cout <<"Updated Get Pointer Position : "<<pos<<endl;
	pos = file1.tellg();
	cout <<"Updated Put Pointer Position: "<<pos <<endl;
	cout <<endl;
	cout <<"updated File Content:" <<endl;
	string line;
	cout <<endl;
	file1.seekp(0,ios::beg);
	while (getline(file1,line)){
		cout <<line<<endl;
	}
	file1.close();
	
}
