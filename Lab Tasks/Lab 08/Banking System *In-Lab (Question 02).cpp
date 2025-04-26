#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string accNum, string holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}

    Account operator+(const Account &other) {
        double combinedBalance = this->balance + other.balance;
        return Account("TEMP", "Combined", combinedBalance); 
    }
    Account& operator=(double amount) {
        this->balance = amount; 
        return *this;
    }
    bool operator>(const Account &other) {
        return this->balance > other.balance;
    }
    friend ostream& operator<<(ostream &os, const Account &acc) {
        os << "Account Number: " << acc.accountNumber << "\n"
           << "Account Holder: " << acc.accountHolder << "\n"
           << "Balance: $" << acc.balance << "\n";
        return os;
    }
    void transferTo(Account &recipient, double amount) {
        if (this->balance >= amount) {
            this->balance -= amount;
            recipient.balance += amount;
            cout << "Transferred $" << amount << " to " << recipient.accountHolder << "\n";
        } else {
            cout << "Insufficient balance for transfer!\n";
        }
    }
    string getAccountNumber() const { return accountNumber; }
    string getAccountHolder() const { return accountHolder; }
    double getBalance() const { return balance; }
};

int main() {

    Account acc1("ACC123", "Alice", 1000.0);
    Account acc2("ACC456", "Bob", 500.0);

    cout << "--- Initial Balances ---\n";
    cout << acc1 << acc2;

    Account combined = acc1 + acc2;
    cout << "\n--- Combined Balance ---\n";
    cout << "Total: $" << combined.getBalance() << "\n";

    acc1.transferTo(acc2, 200.0);
    cout << "\n--- After Transfer ---\n";
    cout << acc1 << acc2;

    cout << "\n--- Balance Comparison ---\n";
    if (acc1 > acc2) {
        cout << acc1.getAccountHolder() << " has a higher balance.\n";
    } else {
        cout << acc2.getAccountHolder() << " has a higher balance.\n";
    }
    return 0;
}
