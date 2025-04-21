#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    float amount;
    string currencyCode;
    string currencySymbol;
    float exchangeRate;

public:
    Currency() {}

    void convertToBase() {
        cout << "Converting amount to base currency.\n";
    }

    void convertTo(string targetCurrency) {
        cout << "Converting to target currency: " << targetCurrency << endl;
    }

    void displayCurrency() {
        cout << "Displaying generic currency details.\n";
    }
};

class Dollar : public Currency {
public:
    void convertToBase() {
        cout << "Converting Dollar to base currency using exchange rate.\n";
    }

    void displayCurrency() {
        cout << "Displaying Dollar currency format.\n";
    }
};

class Euro : public Currency {
public:
    void convertToBase() {
        cout << "Converting Euro to base currency using exchange rate.\n";
    }

    void displayCurrency() {
        cout << "Displaying Euro currency format.\n";
    }
};

class Rupee : public Currency {
public:
    void convertToBase() {
        cout << "Converting Rupee to base currency using exchange rate.\n";
    }

    void displayCurrency() {
        cout << "Displaying Rupee currency format.\n";
    }
};
