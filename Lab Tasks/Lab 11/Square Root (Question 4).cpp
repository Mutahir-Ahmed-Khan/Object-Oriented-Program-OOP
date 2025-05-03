#include <iostream>
#include <exception>
#include <type_traits>
#include <string>
using namespace std;

//GPTed as the concept of checking the data type is not taught

class NegativeException : public exception {
public:
    const char* what() const noexcept override {
        return "Negative Exception: Number is Negative";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Type Exception: T is a string";
    }
};

template <typename T>
void squareRoot(T num) {
    if constexpr (is_same<T, string>::value) {
        throw InvalidTypeException();
    }
    if (num < 0) {
        throw NegativeException();
    }

    cout << "Result: " << num * num << endl;
}

int main() {
    try {
        int num;
        cout << "Enter the Num: ";
        cin >> num;
        squareRoot(num);
    }
    catch (InvalidTypeException &e) {
        cout << e.what() << endl;
    }
    catch (NegativeException &e) {
        cout << e.what() << endl;
    }

    return 0;
}
