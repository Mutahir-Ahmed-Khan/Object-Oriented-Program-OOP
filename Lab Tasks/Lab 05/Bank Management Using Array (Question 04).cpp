#include <iostream>
using namespace std;

class BankAccount{
    private: 
        int accountNumber;
        string accountHolderName;
        float balance;

    public:
        //Parameterised Constructor
        BankAccount(int a, string n, float b) : accountNumber(a) , accountHolderName(n) , balance(b) {}

        //Functions
        void deposit(double amount){ 
            balance = balance + amount;
        }

        void withdraw(double amount){
            if(amount < balance){
                balance = balance - amount;
            }
            else{
                cout << "Not suffiecent Balance" << endl;
            }
        }

        void display(){
            cout << "Holder's Name: " << accountHolderName << endl;
            cout << "Account Number: " << accountNumber << endl; 
            cout << "Balance: $" << balance << endl;
            cout << "\n";
        }
};

int main(){
    BankAccount bank[3] = {BankAccount(1020,"Mutahir Ahmed Khan", 1000), BankAccount(1024, "Syed Burair Hyder", 1500), BankAccount(9012, "Syed Faraz Ahmed", 2000)};

    for (int i = 0; i < 3; i++){
        cout << "-------------------" << endl;
        bank[i].display();
        bank[i].deposit(500);
        bank[i].withdraw(200);
        bank[i].display();
        cout << "-------------------" << endl;
    }

    return 0;
}
