
#include <iostream>
using namespace std;

class User{
    public:
    int Age;
    string licenseType;
    string contactInfo;
    int userID;

    //Constructor
    User(int a, string l,string c, int id) : Age(a), licenseType(l), contactInfo(c), userID(id) {}

    void update(int Age, string licenseType, string contactInfo, int userID){
        cout << "Updated the Info of user........." << endl;
        this -> Age = Age;
        this -> licenseType = licenseType;
        this -> contactInfo = contactInfo;
        this -> userID = userID;
    };
};

class Car{
    public:
    string model;
    float price;
    string eligibility;

    //Constructor 
    Car(string m, float p,string e) : model(m), price(p), eligibility(e){}

    void checkRequirements(User user){
        static int flag = 0;
        if(user.licenseType == eligibility){
            cout << "Eligibile for the car" << endl; 
            flag = 1;
        }
        else{
            cout << "Not Eligible" << endl;
        }
    }

};

int main(){
    User user1(25, "B", "user@example.com", 101);
    Car car1("Toyota", 20000, "B");
    // user1.update(25,"A","Falana",101);
    car1.checkRequirements(user1);
    return 0;
}
