#include <iostream>
#include <fstream>
using namespace std;

class telemetryData {
private:
    double amountConsumed;
    double fuelConsumption;
    double currentSpeed;
    bool vehicleStatus;

public:
    telemetryData(double amt = 0, double fuel = 0, double speed = 0, bool status = false)
        : amountConsumed(amt), fuelConsumption(fuel), currentSpeed(speed), vehicleStatus(status) {}

    void display() const {
        cout << "Fuel Consumed: " << amountConsumed << " L" << endl;
        cout << "Fuel Consumption: " << fuelConsumption << " L/hr" << endl;
        cout << "Speed: " << currentSpeed << " km/hr" << endl;
        cout << "Engine Status: " << (vehicleStatus ? "Running" : "Stopped") << endl;
    }
};

class Vehicle {
private:
    string ID;
    string model;
    string fuelType;
    string currentLoc;
    telemetryData obj;

public:
    Vehicle() {}
    Vehicle(string id, string m, string fuel, string loc)
        : ID(id), model(m), fuelType(fuel), currentLoc(loc) {}

    virtual void display() {
        cout << "ID: " << ID << endl;
        cout << "Model: " << model << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Current Location: " << currentLoc << endl;
        obj.display();
    }

    void updateLocation(const string& newLoc) {
        currentLoc = newLoc;
        cout << "Location Changed to: " << newLoc << endl;
    }

    string getVehicleID() const {
        return ID;
    }

    string getCurrentLocation() const {
        return currentLoc;
    }

    friend class VehicleManager;
};

class VehicleManager {
public:
    VehicleManager() {}

    void trackVehicleLocation(const Vehicle& vehicle) {
        cout << "Current Location is: " << vehicle.currentLoc
             << " | Vehicle ID: " << vehicle.ID << endl;
    }

    void writeToFile(Vehicle* arr, int size) {
        ofstream file("vehicle_Info.txt");
        if (!file) {
            cout << "Error Opening The File" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            file << "Vehicle ID: " << arr[i].ID << endl;
            file << "Model: " << arr[i].model << endl;
            file << "Fuel Type: " << arr[i].fuelType << endl;
            file << "Current Location: " << arr[i].currentLoc << endl;
            file << "------------------------" << endl;
        }

        file.close();
        cout << "Vehicle details written to vehicle_Info.txt" << endl;
    }

    void ReadFromFile() {
        ifstream file("vehicle_info.txt");
        string id, loc;
        while (getline(file, id, ',') && getline(file, loc)) {
            if (loc == "Karachi")
                cout << "Vehicle ID: " << id << " in Karachi" << endl;
        }
        file.close();
    }
};

class MeterReadingVehicle : public Vehicle{
    private: 
    int readingCapacity;

    public: 
    MeterReadingVehicle(int r,string id, string m, string fuel, string loc) 
        :readingCapacity(r), Vehicle(id,m,fuel,loc) {}

    void display() override{
        Vehicle::display();
        cout << "Displaying Inspection Range: " << readingCapacity << endl;
    }
};

int main() {
    Vehicle v1("V1234", "Toyota Corolla 2022", "Petrol", "Karachi");
    Vehicle v2("V5678", "Suzuki Bolan", "CNG", "Lahore");
    Vehicle v3("V9101", "Honda Civic", "Diesel", "Karachi");

    Vehicle vehicles[3] = { v1, v2, v3 };

    VehicleManager manager;

    for (int i = 0; i < 3; i++) {
        manager.trackVehicleLocation(vehicles[i]);
    }

    manager.writeToFile(vehicles, 3);

    vehicles[1].updateLocation("Islamabad");
    manager.trackVehicleLocation(vehicles[1]);

    return 0;
}
