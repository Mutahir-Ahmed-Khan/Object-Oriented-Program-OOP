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

class Vehicle{
    public:
    string model;
    float price;
    string eligibility;
    
    //Constructor 
    Vehicle(string m, float p,string e) : model(m), price(p), eligibility(e){}

    //Vehicle Display (learned from Debugging)
    void display() {
        cout << "Model: " << model << ", Price per day: $" << price 
             << ", License Required: " << eligibility << endl;
    }

    void checkRequirements(User user){
        static int flag = 0;
        if(user.licenseType == eligibility){
            cout << "Eligibile For The Car" << endl; 
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
    void addCar(int i,string model, float price, string eligiblity){
        vehicle[i] = new Vehicle(model, price , eligiblity);
    }

    void display(){
        cout << "------------------------------- Vehicle ---------------------------" << endl;
        for(int i = 0; i < Count; i++){
            cout << i + 1 << "- ";
            vehicle[i]->display();
        }

        cout << "-------------------------------------------------------------------" << endl;
    }

    //Checking the eligiblity
    void checkEligibility(User user, int i){
        if(i < -1 || i >= Count){
            cout << "Invalid" << endl;

        }

        if(user.licenseType == vehicle[i]->eligibility){
            cout << "you can Successfully Rent the " << vehicle[i] -> model << endl;
        }
        else{
            cout << "Unable to rent a Car " << vehicle[i] -> model << endl;
        }
    }

    //Destructor
    ~Rent(){
        for(int i = 0; i < Count ; i++){
            delete vehicle[i];
        }
    
        delete[] vehicle;
    }

};

int main(){
   User user1(25, "Full", "Mutahir", 101);

   Rent system(3);
   system.addCar(0, "C63", 30.0, "Full");
   system.addCar(1, "M5", 25.0, "Intermediate");
   system.addCar(2, "911 GT3 RS", 40.0, "Learner");

  
   system.display();

   
   int choice;
   while(1){
    cout << "Enter the vehicle number you want to rent: (-1 to exit) ";
    cin >> choice;

    if(choice == -1){
        cout << "System Shut Down....." << endl;
        break;
    }
    
    system.checkEligibility(user1, choice - 1);
    cout << "\n";
   }

    return 0;
}
