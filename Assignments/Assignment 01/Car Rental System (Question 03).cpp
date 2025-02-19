\#include <iostream>
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

class Vehicle{
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

class Rent{
    public: 
    Vehicle **vehicle;
    int Count;

    //Constructor
    Rent(int s){
        Count = s;
        vehicle = new Vehicle*[Count];
    }

    //Adding the Cars
    void addCar(int i,string model, string eligibility, float price){
        if(i > Count){
            cout << "Index is not right" << endl;
        }
        else{
            vehicle[i] = new Vehicle(model, price , eligibility);
        }
    }

    

};

int main(){

}
