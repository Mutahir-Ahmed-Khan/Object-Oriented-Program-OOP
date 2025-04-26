#include <iostream>
#include <fstream>
using namespace std;

class Resume{
    public:
    string name;
    string email; 
    int yearsOfExperience;
    string summary;
     
    Resume() {}

    void enterData(){
        cout << "Name: " ;
        getline(cin,name);

        cout << "Email: " ;
        cin.ignore();
        getline(cin,email);

        cout << "Years of Experience: " ;
        cin>> yearsOfExperience;

        cout << "Summary: ";
        cin.ignore();
        getline(cin,summary);
    }
};

class FileWriter{
    private: 
    ofstream file;
    string fileName;
    Resume resume;

    public:
    FileWriter(string fname) : fileName(fname){
        file.open(fname, ios::trunc);
        if(!file){
            cout << "ERROR!!" << endl;
        }
    }

    void Enter(){
        resume.enterData();
    }

    void writingInFile(){
        file << "Name: " << resume.name << endl;
        file << "Email: " << resume.email << endl;
        file << "Years of Experience: " << resume.yearsOfExperience << endl;
        file << "Summary: " << resume.summary << endl;
    }

    ~FileWriter(){
        if(file.is_open()){
            file.close();
        }
    }
};

class FileReader{
    private: 
    ifstream read;
    string fname;
    string line;

    public: 
    FileReader(string fname) : fname(fname){
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
    FileWriter test("Resume.txt");
    test.Enter();
    test.writingInFile();

    cout << endl;
    FileReader Read("Resume.txt");
    cout << "LAST ENTRY" << endl;
    Read.reading();

    return 0;
}
