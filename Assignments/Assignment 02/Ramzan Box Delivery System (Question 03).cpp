#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle{
    private: 
    int uniqueID; 

    public:
    static int activeDeliveries;
    float distance;
    float speed; 
 
    Vehicle() : uniqueID(0) {
        cout << right << setw(22) << "(Vehicle)" << endl; 
    }

    int getUniqueID(){
        return uniqueID;
    }
    void setUniqueID(int uniqueID){
        this-> uniqueID = uniqueID;
    }
     
    float calcEstimatedTime(){
        return distance / speed;
    }

    void calcOptimalDelivery(){
        //Logic to be Implemented 
    }

    virtual void movement() = 0;
    virtual void command(string delivery, int packageID) = 0; 
    virtual void command(string delivery, int packageID,int urgencyLevel) = 0;
};

class RamzanDrone : public Vehicle {
    private:
    const int tempDis = 100;
    int speed = 50; 

    public:
    RamzanDrone() : Vehicle() {
        activeDeliveries++;
        cout << right << setw(30) << "----- Ramzan Drone -----" << endl;
    }

    void movement() override {
        string des;
        cout << "Enter the Destination: ";
        cin.ignore();
        getline(cin,des);
        cout << "Aerial Route: " << tempDis << "Km" << endl;
        cout << "Estimated Time: " << tempDis / speed << "Hours" << endl;
    }

    void command(string delivery, int packageID) override{
        setUniqueID(packageID);
    }

    void command(string delivery, int packageID,int urgencyLevel) override{
        setUniqueID(packageID);

        if(urgencyLevel >= 10){
            speed = 100;
            cout << "Speed: " << speed << endl;
            cout << "New Estimated Time: " << tempDis / speed << "Hours" << endl;
        } 
        else if(urgencyLevel < 10){
            speed = 75;
            cout << "Speed: " << speed << endl;
            cout << "New Estimated Time: " << tempDis / speed << "Hours" << endl;
        } 
    }

};

class RamzanTimeShip : public Vehicle{
    public: 
    RamzanTimeShip() : Vehicle() {
        activeDeliveries++;
        cout << right << setw(30) << "----- Ramzan Time Ship -----" << endl;
    }

    void movement() override {
        int year;

        cout << "Enter the Year: ";
        cin >> year;

        if(year < 1900){
            cout << "Historical Consistency Not Verified" << endl;
            activeDeliveries--;
        }
        else{
            cout << "Historical Consistency Verified" << endl;
            cout << "Traveling Back ..." << endl;
            cout << "Date: 4/3/" << year << endl;
        }
    }

    void command(string delivery, int packageID) override{
        setUniqueID(packageID);
    }

    void command(string delivery, int packageID,int urgencyLevel) override{ 
    }
};

class RamzanHyperPod : public Vehicle{
    public: 
    RamzanHyperPod() : Vehicle() {
        activeDeliveries++;
        cout << right << setw(30) << "----- Ramzan Hyper Pod -----" << endl;
    }

    void movement() override {
        int tunnelDistance;
        cout << "Enter Tunnel Distance (in Km): ";
        cin >> tunnelDistance;

        int speed = 300; 
        float estimatedTime = static_cast<float>(tunnelDistance) / speed;

        cout << "Navigating Underground Tunnel Network..." << endl;
        cout << "Tunnel Distance: " << tunnelDistance << " Km" << endl;
        cout << "Speed: " << speed << " Km/h" << endl;
        cout << "Estimated Time: " << estimatedTime << " hours" << endl;
    }

    void command(string delivery, int packageID) override{
        setUniqueID(packageID);
    }

    void command(string delivery, int packageID,int urgencyLevel) override{}
};

int Vehicle::activeDeliveries = 0;

int main(){
    string sen;
    const string constant = "Deliver";
    Vehicle* veh = NULL; 
    int opt,id,lvl;

    cout << "**************" << endl;
    cout << "Date: 4/3/2025" << endl;
    cout << "**************" << endl;
    cout << right << setw(30) << "------Options------" << endl;
    cout << right << setw(22) << "Bulk" << endl;
    cout << right << setw(27) << "Back in Time" << endl;
    cout << right << setw(22) << "Air" << endl;
    cout << right << setw(30) << "-------------------" << endl;
    cout << "Mode Of Transport: ";
    getline(cin,sen);

    if(sen == "Bulk" || sen == "bulk"){
        veh = new RamzanHyperPod();
    }
    else if(sen == "Back in Time" || sen == "back in time"){
        veh = new RamzanTimeShip();
    }
    else if(sen == "Air" || sen == "air"){
        veh = new RamzanDrone();
    }
    else{
        cout << "Incorrect Option" << endl;
        return  0;
    }
    
    cout << "Command Panel" << endl;
    cout << "1. Delivery" << endl;
    cout << "2. Fast Delivery" << endl;
    cout << "Enter the Option: ";
    cin >> opt;

    switch(opt){
        case 1:
            cout << "command(" << constant << ",----)" << endl;
            cout << "Enter th PackageID: ";
            cin >> id;
            cout << "command(" << constant << "," << id << ")" << endl;
            veh->command(constant,id);
            cout << "Package with ID " << veh->getUniqueID() << " is being delivered" << endl;
            veh->movement();
            break;
        case 2:
            cout << "command(" << constant << ",----,-----)" << endl;
            cout << "Enter th PackageID: ";
            cin >> id;
            cout << "command(" << constant << "," << id << ",-----)" << endl;
            cout << "Enter the Urgency Level (1-20): ";
            cin >> lvl;
            cout << "command(" << constant << "," << id << "," << lvl <<")" << endl; 
            veh->command(constant,id,lvl);
            cout << "Package with ID " << veh->getUniqueID() << " is being delivered" << endl;
            break;
        default: 
            cout << "Wrong Option" << endl;
            break;
    }
    

    cout <<"(" << "Vehicle Active: " << Vehicle::activeDeliveries << ")"<< endl;

    return 0;
}
