#include <iostream>
#include <fstream>
using namespace std;

class Student{
    public:
    int id; 
    string name;
    float gpa;

    Student() {}

    void Enter(){
            cout << "Enter the Id of the Student: ";
            cin >> id;
            cout << "Enter the Name: ";
            cin.ignore();
            getline(cin,name);
            cout << "Enter the GPA: ";
            cin >> gpa;
    }
};

class FileHandler{
    private:
    ofstream file;
    string fileName;

    public:
    Student students[5];
    FileHandler(string fname) : fileName(fname){
        file.open(fileName, ios::app);
        if(!file){
            cout << "Error" << endl;
        }
    }

    void EnterStudents() {
        for (int i = 0; i < 5; i++) {
            cout << "\nEnter data for student " << i + 1 << ":\n";
            students[i].Enter();
        }
    }

    void writingInFile(){
        for(int i = 0; i < 5; i++){
            file << "Roll No: "<< students[i].id << endl;
            file << "Name: "<< students[i].name << endl;
            file << "GPA: " << students[i].gpa << endl;
            cout << endl;
        }
    }

    ~FileHandler(){
        if(file.is_open()){
            file.close();
        }
    }
};

class FileReader{
    private: 
    ifstream read;
    string fname;

    public:
    string line;
    FileReader(string fname) : fname(fname) {
        read.open(fname);
        if(!read){
            cout << "Error" << endl;
        }
    }

    void reading(){
        while(getline(read,line)){
            cout << line << endl;
        }
    }

    ~FileReader(){
        if(read.is_open()){
            read.close();
        }
    }
};

int main(){
    FileHandler test("Student.txt");
    test.EnterStudents();
    test.writingInFile();

    FileReader Reading("Student.txt");
    Reading.reading();

    return 0;
}
