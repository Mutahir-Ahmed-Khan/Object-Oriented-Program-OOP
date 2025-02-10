#include <iostream>
using namespace std;

class Account{
	public:
	string accountNumber;
	string accountHolderName;
	double balance;
	
	//Constructor 01
	Account() : balance(0.0) {}
	
	//Constructor 02
	Account(string accountNumber, string accountHolderName, double balance){
		this -> accountNumber = accountNumber;
		this -> accountHolderName = accountHolderName;
		this -> balance = balance;
	}
	
	//Deposit Function
	void deposit(double amount){
		balance = amount + balance;
	}
	
	//Withdraw
	void withdraw(double amount){
		balance = balance - amount;
	}
	
	//CheckBalance
	void checkBalance(){
		cout << "--------------------" << endl;
		cout << "Account Number: " << accountNumber << endl;
		cout << "Account Holder's Name: " << accountHolderName << endl;
		cout << "Balance:$" << balance << endl;
		cout << "--------------------" << endl;	
	}
	
};

int main(){
	//Checking Constructor 01
	Account Account02;
	Account02.checkBalance();
	
	Account Account01("827362891", "Mutahir", 150);
	
	//Deposit 
	Account01.deposit(100);
	
	//Withdraw 
	Account01.withdraw(100);
	
	//Checking Balance
	Account01.checkBalance();
	}
