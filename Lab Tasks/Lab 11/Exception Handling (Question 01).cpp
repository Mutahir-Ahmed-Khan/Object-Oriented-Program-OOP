#include <iostream>
#include <exception>
using namespace std;

class InvalidValueException : public exception{
    public: 
    const char* what() const noexcept override {
        return "Invalid age: Age must be between 0 and 120.";
    }
};

void validateAge(int age){
    if(age < 0 || age > 120){
        throw InvalidValueException();
    }
    else{
        cout << "Age is Correct: " << age << endl;
    }
}

int main(){
    int a;

    try{
        cout << "Enter the Age: ";
        cin >> a;
        validateAge(a);
    }
    catch(const InvalidValueException &e){
        cout << "Exception Caught: " << e.what() << endl;
    }
    return 0;
}
