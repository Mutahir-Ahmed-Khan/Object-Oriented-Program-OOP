#include <iostream>
#include <exception>
using namespace std;

class suffBalance : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient Balance";
    }
};

template <typename T>
class bankAccount {
public:
    T balance;

    bankAccount(T initialBalance) {
        balance = initialBalance;
    }

    void withdraw(T amount) {
        if (amount > balance) {
            throw suffBalance();
        }
        balance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << balance << endl;
    }
};

int main() {
    int am;
    bankAccount<int> b1(500);  

    try {
        cout << "Enter the amount: ";
        cin >> am;
        b1.withdraw(am);
    }
    catch (suffBalance &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
