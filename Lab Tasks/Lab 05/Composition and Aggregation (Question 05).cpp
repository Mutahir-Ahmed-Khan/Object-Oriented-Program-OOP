#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    string type;
public:
    Engine(string type) : type(type) {}  
    void display() const {
        cout << "Engine Type: " << type << endl;
    }
};

class Wheel {
private:
    int size;
public:
    Wheel(int size) : size(size) {}  
    void display() const {
        cout << "Wheel Size: " << size << " inches" << endl;
    }
};

class Headlight {
private:
    string brightness;
public:
    Headlight(string brightness) : brightness(brightness) {}  
    void display() const {
        cout << "Headlight Brightness: " << brightness << endl;
    }
};

class Steering {
private:
    string type;
public:
    Steering(string type) : type(type) {}  
    void display() const {
        cout << "Steering Type: " << type << endl;
    }
};

class Car {
private:
    Engine* engine;
    Wheel* wheels[4];
    Headlight headlights[2];
    Steering steering;

public:
    Car(Engine* eng, Wheel* w1, Wheel* w2, Wheel* w3, Wheel* w4, string light1, string light2, string steerType)
        : engine(eng), headlights{Headlight(light1), Headlight(light2)}, steering(steerType) {
        wheels[0] = w1;
        wheels[1] = w2;
        wheels[2] = w3;
        wheels[3] = w4;
    }

    ~Car() {
        cout << "Destroying Car object..." << endl;
    }

    void display() const {
        cout << "Car Details:\n";
        engine->display();
        for (int i = 0; i < 4; i++) {
            wheels[i]->display();
        }
        for (int i = 0; i < 2; i++) {
            headlights[i].display();
        }
        steering.display();
    }
};

int main() {
    Engine myEngine("V8");
    Wheel wheel1(18), wheel2(18), wheel3(18), wheel4(18);

    Car myCar(&myEngine, &wheel1, &wheel2, &wheel3, &wheel4, "Bright", "Dim", "Power Steering");

    myCar.display();

    return 0;
}
