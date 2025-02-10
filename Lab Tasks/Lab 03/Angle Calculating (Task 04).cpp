#include <iostream>
#include <iomanip>

using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    // Constructor
    Angle(int deg, float min, char dir) : degrees(deg), minutes(min), direction(dir) {}
    
    // Function to get angle input from user
    void getAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
    }
    
    // Function to display angle in the required format
    void displayAngle() const {
        cout << fixed << setprecision(1);
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};

int main() {
    Angle initialAngle(149, 34.8, 'W');
    cout << "Initial angle: ";
    initialAngle.displayAngle();
    
    while (true) {
        Angle userAngle(0, 0.0, 'N');
        cout << "\nEnter a new angle value (or Ctrl+C to exit):\n";
        userAngle.getAngle();
        cout << "You entered: ";
        userAngle.displayAngle();
    }
    
    return 0;
}
