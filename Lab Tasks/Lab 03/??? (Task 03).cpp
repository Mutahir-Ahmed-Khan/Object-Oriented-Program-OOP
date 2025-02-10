#include <iostream>

class SerialNumbered {
private:
    static int count; 
    int serialNumber; 

public:
    SerialNumbered() {
        serialNumber = ++count; 
    }

    void reportSerialNumber() const {
        std::cout << "I am object number " << serialNumber << std::endl;
    }
};

int SerialNumbered::count = 0;

int main() {
    SerialNumbered obj1, obj2, obj3;

    obj1.reportSerialNumber();
    obj2.reportSerialNumber();
    obj3.reportSerialNumber();
    
    return 0;
}

//Static Keyword wouold be used to count the Number of objects of Classs 
