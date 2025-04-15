#include <iostream>
using namespace std;

class PaymentMethod {
public:
    PaymentMethod() {
        cout << "Constructor of Payment Method" << endl;
    }

    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;

public:
    CreditCard(string c) : cardNumber(c) {
        cout << "Constructor of CreditCard" << endl;
    }

    void processPayment(double amount) override {
        if (cardNumber == "0030") {
            cout << "Card Number " << cardNumber << " Making Payment of $" << amount << endl;
        } else {
            cout << "Failed, Invalid Card Number" << endl;
        }
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;

public:
    DigitalWallet(double b) : balance(b) {
        cout << "Constructor of DigitalWallet" << endl;
    }

    void processPayment(double amount) override {
        if (balance >= amount) {
            cout << "Can Make Payment of $" << amount << endl;
            balance -= amount;
            cout << "$" << amount << " deducted from your account. Remaining balance: $" << balance << endl;
        } else {
            cout << "Failed: Insufficient Balance" << endl;
        }
    }
};

int main() {
    PaymentMethod* ptr;

    CreditCard c("0030");
    DigitalWallet w(200);

    ptr = &c;
    ptr->processPayment(50);  

    ptr = &w;
    ptr->processPayment(150); 

    return 0;
}
