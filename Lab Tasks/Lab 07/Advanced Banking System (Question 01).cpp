#include <iostream>
#include <iomanip>
using namespace std;

class Account {
protected:
    int accNumber;
    double balance;
    string accName;
    string type;

public:
    // Constructor
    Account(int accNumber, string accName, string type, double balance = 0) 
        : accNumber(accNumber), accName(accName), type(type), balance(balance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient Balance" << endl;
        }
    }

    void getInfo() {
        cout << right << setw(30) << "-----------------------------";
        cout << "Details";
        cout << left << setw(30) << "--------------------------------" << endl;
        cout << right << setw(30) << "Name: " << accName << endl;
        cout << right << setw(30) << "Account Number: " << accNumber << endl;
        cout << right << setw(30) << "Balance: " << balance << endl;
        cout << right << setw(30) << "Type: " << type << endl;
        cout << left << setw(30) << "--------------------------------";
        cout << right << setw(30) << "--------------------------------" << endl;
    }

    virtual void computeInterest() {}
    virtual void printStatement() {}
};


class SavingsAccount : public Account {
private:
    float interestRate;
    double minBalance;

public:
    SavingsAccount(int accNumber, string accName, double balance, float interestRate, double minBalance)
        : Account(accNumber, accName, "Savings", balance), interestRate(interestRate), minBalance(minBalance) {}

    void computeInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest Added: " << interest << " New Balance: " << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNumber, string accName, double balance)
        : Account(accNumber, accName, "Checking", balance) {}
};

class FixedDepositAccount : public Account {
private:
    string maturityDate;
    float fixedInterestRate;

public:
    FixedDepositAccount(int accNumber, string accName, double balance, string maturityDate, float fixedInterestRate)
        : Account(accNumber, accName, "Fixed Deposit", balance), maturityDate(maturityDate), fixedInterestRate(fixedInterestRate) {}

    void computeInterest() override {
        double interest = balance * fixedInterestRate / 100;
        cout << "Fixed Deposit Interest: " << interest << " (Maturity Date: " << maturityDate << ")" << endl;
    }
};

int main() {
    SavingsAccount sa(1001, "Burair", 5000, 5, 1000);
    sa.getInfo();
    sa.deposit(2000);
    sa.withdraw(1000);
    sa.computeInterest();

    CheckingAccount ca(1002, "Jane Doe", 3000);
    ca.getInfo();
    ca.deposit(1500);
    ca.withdraw(500);

    FixedDepositAccount fda(1003, "Mutahir", 10000, "2026-12-31", 7);
    fda.getInfo();
    fda.computeInterest();
    
    return 0;
}

