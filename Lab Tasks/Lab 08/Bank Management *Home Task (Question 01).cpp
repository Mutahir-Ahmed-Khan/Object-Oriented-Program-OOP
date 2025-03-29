#include <iostream>
#include <iomanip>
using namespace std;

class savingAccount;
class currentAccount;

class bankAccount{
    private: 
    int accNum; 
    double balance;
    const double interest = 0.05;

    public: 
    bankAccount(int a, double b) : accNum(a) , balance(b) {}

    //Getter and setter 
    int getAccNum(){
        return accNum;
    }
    void setBalance(double balance){
        this-> balance = balance;
    }
    double getBalance(){
        return balance;
    }

    //Withdraw 
    virtual void withdraw(double amount){
        balance -= amount;
    }

    //Calc Interest
    virtual void calcInterest(){
        balance += (balance * interest);
    }

    //----------------------------------------------Operations---------------------------------------------//
    bankAccount + (bankAccount &obj){
        return (balance + obj.balance);
    }

};

class savingAccount : public bankAccount{
    private: 
    const double interest = 0.05;

    public: 
    //Constructor
    savingAccount(int a, double b) : bankAccount(a,b){
        cout << right << setw(30) << "----- Saving Account -----" << endl;;
    }

    //----------------------------------------------Interest-----------------------------------------------//

    void calcInterest() override {
        setBalance(getBalance() + (getBalance() * interest));
    }  

    //----------------------------------------------Interest-----------------------------------------------//
    
    //----------------------------------------------Deposit-----------------------------------------------//
    void deposit(double amount){
        setBalance(getBalance() + amount);
        cout <<"$"<< amount << " Have been depsoited via Cash in " << getAccNum() <<  endl;
    }

    void deposit(double amount,string isSign) {
        if (isSign == "Yes"){ //Checking for the Sign on the Check
            setBalance(getBalance() + amount);
            cout <<"$"<< amount << " Have been depsoited via Check in " << getAccNum() <<  endl;
        }
        else if(isSign == "No" ){
            cout << "Check Not Signed! " << endl;
        }
    } 

    void deposit(double amount,string num, string name){
        setBalance(getBalance() + amount);
        cout <<"$"<< amount << " Have been depsoited via Online Transfer in " << getAccNum() << 
        " through "<< num << "("<< name <<")" << endl;
    }

    //----------------------------------------------Deposit-----------------------------------------------//

    //----------------------------------------------Withdraw----------------------------------------------//
    void withdraw(double amount) override {
        if(getBalance() >= 500){
            bankAccount :: withdraw(amount);
            cout << "$" << amount << " Have been withdrawn from " << getAccNum() << endl;
        }
        else{
            cout << "Cannot Withdraw as Balance is Less than $500" << endl;
        }
    }
    //----------------------------------------------Withdraw----------------------------------------------//

    //----------------------------------------------Display-----------------------------------------------//
    void displayBalance(){
        cout << "Balance: " <<"$" << getBalance() << endl;
    }
    //----------------------------------------------Display-----------------------------------------------//

};

class currentAccount : public bankAccount{
    public:
    int res;

    currentAccount(int a, double b) : bankAccount(a,b){
        cout << right << setw(30) << "----- Current Account -----" << endl;
    }

   //----------------------------------------------Deposit-----------------------------------------------//
    void deposit(double amount){
        setBalance(getBalance() + amount);
        cout <<"$"<< amount << " Have been depsoited via Cash in " << getAccNum() <<  endl;
    }

    void deposit(double amount,string isSign) {
        if (isSign == "Yes"){ //Checking for the Sign on the Check
            setBalance(getBalance() + amount);
            cout <<"$"<< amount << " Have been depsoited via Check in " << getAccNum() <<  endl;
        }
        else if(isSign == "No" ){
            cout << "Not a Signed Check! " << endl;
        }
    } 

    void deposit(double amount,string num, string name){
        setBalance(getBalance() + amount);
        cout <<"$"<< amount << " Have been depsoited via Online Transfer in " << getAccNum() << 
        " through "<< num << "("<< name <<")" << endl;
    }

    //----------------------------------------------Deposit-----------------------------------------------//

    //----------------------------------------------Withdraw----------------------------------------------//
    void withdraw(double amount) override {
        if(amount < getBalance()){
            bankAccount :: withdraw(amount);
            cout << "$" << amount << " Have been withdrawn from " << getAccNum() << endl;
        }
        else if(amount > getBalance()){
            res = amount - getBalance();
            if(res > 1000){
                cout << "OverDratf is Allowed Upto $1000 Only" << endl;
            }
            else{
                bankAccount :: withdraw(amount);
                cout << "$" << amount << " Have been withdrawn from " << getAccNum() << endl; 
            }
        }
    }
    //----------------------------------------------Withdraw----------------------------------------------//

    //----------------------------------------------Display-----------------------------------------------//
     void displayBalance(){
        cout << "Balance: " <<"$" << getBalance() << endl;
    }
    //----------------------------------------------Display-----------------------------------------------//

};

int main(){


    return 0;
}
