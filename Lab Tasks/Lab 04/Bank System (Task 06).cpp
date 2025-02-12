#include <iostream>
using namespace std;

class Bank{
    public:
    int accNum;
    string name;
    double balance;

    //Initial Balance Would be Zero
    Bank() : balance(0) {};

    Bank(int A, string N, double b) : accNum(A), name(N), balance(b) {};

    //Deposit Money 
    void Deposit(double amount){
        balance += amount;
    }

    //Withdraw
    void withdraw(double amount){
        balance -= amount ;
    }

    //Display Acc Details
    void Display(){
        cout << "-------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accNum << endl;
        cout << "Balance:$ " << balance << endl;
        cout << "-------------------" << endl;
    }

};

int main(){
    Bank bank01(1910101,"Mutahir",1000);
    //To test the Construtor

    bank01.Display();

    //Deposit
    bank01.Deposit(1000);
    bank01.Display();

    //Withdraw
    bank01.withdraw(500);
    bank01.Display();


return 0;
}
