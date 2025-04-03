#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle{
    public: 
    int uniqueID; 
    float capacity;  
    float energyEfficiency;

    static int activeDeliveries;
    float distance;
    float speed; 
 
    Vehicle() : uniqueID(0), capacity(0), energyEfficiency(0) {
        cout << right << setw(22) << "(Vehicle)" << endl; 
    }

    friend bool resolveConflict(const Vehicle& v1, const Vehicle& v2);

    int getUniqueID(){
        return uniqueID;
    }
    void setUniqueID(int uniqueID){
        this-> uniqueID = uniqueID;
    }

    bool operator==(const Vehicle& other) const {
        return (speed == other.speed) && 
               (capacity == other.capacity) && 
               (energyEfficiency == other.energyEfficiency);
    }
     
    float calcEstimatedTime(){
        return distance / speed;
    }

    void calcOptimalDelivery(){ 
       cout << "Selecting " << endl;
    }

    virtual void movement() = 0;
    virtual void command(string delivery, int packageID) = 0; 
    virtual void command(string delivery, int packageID,int urgencyLevel) = 0;
};

bool resolveConflict(const Vehicle& v1, const Vehicle& v2) {
    if (v1.speed > v2.speed) {
        cout << "Vehicle 1 (faster) chosen for delivery." << endl;
        return true;  
    } else if (v1.speed < v2.speed) {
        cout << "Vehicle 2 (faster) chosen for delivery." << endl;
        return false;  
    }
    
   
    if (v1.energyEfficiency > v2.energyEfficiency) {
        cout << "Vehicle 1 (more efficient) chosen for delivery." << endl;
        return true;  
    } else if (v1.energyEfficiency < v2.energyEfficiency) {
        cout << "Vehicle 2 (more efficient) chosen for delivery." << endl;
        return false;  
    }
    
    
    if (v1.capacity > v2.capacity) {
        cout << "Vehicle 1 (larger capacity) chosen for delivery." << endl;
        return true;  
    } else {
        cout << "Vehicle 2 (larger capacity) chosen for delivery." << endl;
        return false;  
    }
}

class RamzanDrone : public Vehicle {
    private:
    const int tempDis = 100;
    int speed = 50; 

    public:
    RamzanDrone() : Vehicle() {
        activeDeliveries++;
        capacity = 10;  
        energyEfficiency = 15;
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
        capacity = 10;  
        energyEfficiency = 15;
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

    void command(string delivery, int packageID, int urgencyLevel) override {
        setUniqueID(packageID);

        if (urgencyLevel > 10) {
            int year;
            cout << "This package is marked as urgent and historically sensitive." << endl;
            cout << "Please validate the year of the package: ";
            cin >> year;

            if (year < 1900) {
                cout << "Historical Consistency Not Verified." << endl;
                activeDeliveries--; 
            } else {
                cout << "Historical Consistency Verified for urgent package." << endl;
            }
        } else {
            cout << "Package is not urgent" << endl;
        }
    }
};

class RamzanHyperPod : public Vehicle{
    public: 
    RamzanHyperPod() : Vehicle() {
        activeDeliveries++;
        capacity = 10;  
        energyEfficiency = 15;
        cout << right << setw(30) << "----- Ramzan Hyper Pod -----" << endl;
    }

    void movement() override {
        float tunnelDistance;
        cout << "Enter Tunnel Distance (in Km): ";
        cin >> tunnelDistance;

        int speed = 300; 

        cout << "Navigating Underground Tunnel Network..." << endl;
        cout << "Tunnel Distance: " << tunnelDistance << " Km" << endl;
        cout << "Speed: " << speed << " Km/h" << endl;
        cout << "Estimated Time: " << tunnelDistance / speed << " hours" << endl;
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
    int opt, id, lvl;

    string sen2;
    Vehicle* veh2 = NULL; 
    int opt2, id2, lvl2;

    cout << "**************" << endl;
    cout << "Date: 4/3/2025" << endl;
    cout << "**************" << endl;

    // Vehicle 01 Selection
    cout << right << setw(30) << "-Options (Vehicle 01)-" << endl;
    cout << right << setw(22) << "Bulk" << endl;
    cout << right << setw(27) << "Back in Time" << endl;
    cout << right << setw(22) << "Air" << endl;
    cout << right << setw(30) << "-------------------" << endl;
    cout << "Mode Of Transport: ";
    getline(cin, sen);

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

    // Vehicle 02 Selection
    cout << right << setw(30) << "-Options (Vehicle 02)-" << endl;
    cout << right << setw(22) << "Bulk" << endl;
    cout << right << setw(27) << "Back in Time" << endl;
    cout << right << setw(22) << "Air" << endl;
    cout << right << setw(30) << "-------------------" << endl;
    cout << "Mode Of Transport: ";
    cin.ignore();
    getline(cin, sen2);

    if(sen2 == "Bulk" || sen2 == "bulk"){
        veh2 = new RamzanHyperPod();
    }
    else if(sen2 == "Back in Time" || sen2 == "back in time"){
        veh2 = new RamzanTimeShip();
    }
    else if(sen2 == "Air" || sen2 == "air"){
        veh2 = new RamzanDrone();
    }
    else{
        cout << "Incorrect Option" << endl;
        return  0;
    }

    if (veh && veh2) {
        resolveConflict(*veh, *veh2);
    } else {
        cout << "One of the vehicles is not initialized correctly." << endl;
        return 0;
    }

    // Command Panel for Vehicle 01
    cout << "Command Panel Vehicle 01" << endl;
    cout << "1. Delivery" << endl;
    cout << "2. Fast Delivery" << endl;
    cout << "Enter the Option: ";
    cin >> opt;

    switch(opt){
        case 1:
            cout << "command(" << constant << ",----)" << endl;
            cout << "Enter the PackageID: ";
            cin >> id;
            veh->command(constant, id);
            cout << "Package ID = " << veh->getUniqueID() << endl;
            veh->movement();
            break;
        case 2:
            cout << "command(" << constant << ",----,-----)" << endl;
            cout << "Enter the PackageID: ";
            cin >> id;
            cout << "Enter the Urgency Level (1-20): ";
            cin >> lvl;
            veh->command(constant, id, lvl);
            cout << "Package with ID = " << veh->getUniqueID() << " is being delivered" << endl;
            break;
        default: 
            cout << "Wrong Option" << endl;
            break;
    }

    // Command Panel for Vehicle 02
    cout << "Command Panel Vehicle 02" << endl;
    cout << "1. Delivery" << endl;
    cout << "2. Fast Delivery" << endl;
    cout << "Enter the Option: ";
    cin >> opt2;

    switch(opt2){
        case 1:
            cout << "command(" << constant << ",----)" << endl;
            cout << "Enter the PackageID: ";
            cin >> id2;
            veh2->command(constant, id2);
            cout << "Package ID = " << veh2->getUniqueID() << endl;
            veh2->movement();
            break;
        case 2:
            cout << "command(" << constant << ",----,-----)" << endl;
            cout << "Enter the PackageID: ";
            cin >> id2;
            cout << "Enter the Urgency Level (1-20): ";
            cin >> lvl2;
            veh2->command(constant, id2, lvl2);
            cout << "Package with ID = " << veh2->getUniqueID() << " is being delivered" << endl;
            break;
        default: 
            cout << "Wrong Option" << endl;
            break;
    }

    cout <<"(" << "Vehicle Active: " << Vehicle::activeDeliveries << ")" << endl;

    return 0;
}
