#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global Function of Hash
string GenHash(string pass) {
    int hash = 5381;
    string hashed = "";  
    int sizeOfPass = pass.length();

    for (int i = 0; i < sizeOfPass; i++) {
        hash = hash * 33 + pass[i]; 
        hashed += char(hash % 128);  
    }

    return hashed;
}

class User{
    private:
    string name;
    int ID;
    string email;
    string* permissions; 
    string Pass;
    string finalHashPass;
    int size;

    public:
    //Constructor
    User(string n, int id, string e,int tempSize,string p) 
        : name(n), ID(id), email(e),Pass(p){
            size = tempSize;
            permissions = new string[size];
            finalHashPass = GenHash(p);
            for(int i = 0; i < size; i++){
                permissions[i] = "---";
            }
            cout << right << setw(30) << "*---(User)---*" << endl;
        }
    //Destructor
        ~User() {
            delete[] permissions;
        }
    //Display Function
    void display(){
        cout << right << setw(30) << "*********************************************" << endl;
        cout << right << setw(19) << "NAME: " << name << endl;
        cout << right << setw(20) << "EMAIL: " << email <<endl;
        cout << right << setw(17) << "ID: " << ID <<endl;
        cout << right << setw(23) << "PASSWORD: " << finalHashPass <<endl;
        for(int i = 0; i < size; i++){
            cout << right << setw(25) << "Permission #" << i + 1 << ": " << permissions[i] << endl;
        }
        cout << right << setw(30) << "*********************************************" << endl;  
    }
};


int main(){
    User user01("Mutahir",1020,"MutahirHere18@gmail.com",3,"MAK000");
    user01.display();
    return 0;
}
