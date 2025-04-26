#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    ifstream chapter01("Chapter01.txt");
    ifstream chapter02("Chapter02.txt");
    ofstream book("book.txt", ios::app);
    string line;

    if(!chapter01 || !chapter02){
        cout << "ERROR!" << endl;
    }
    if(!book){
        cout << "ERROR!" << endl;
    }

    book << left << setw(30) << "---------- Chapter 01 (Mercedes) ----------" << endl;
    while(getline(chapter01,line)){
        book << line << endl;
    }

    book << endl;

    book << left << setw(30) << "--------- Chapter 02 (BMW) ----------" << endl;
    while(getline(chapter02,line)){
        book << line << endl;
    }

    chapter01.close();
    chapter02.close();
    book.close();

    ifstream Finalbook("book.txt");
    while(getline(Finalbook,line)){
        cout << line << endl;
    }

    Finalbook.close();

}
