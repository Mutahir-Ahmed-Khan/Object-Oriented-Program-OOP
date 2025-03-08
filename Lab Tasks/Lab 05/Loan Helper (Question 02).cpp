#include <iostream>
using namespace std;

class loanHelper{
    public:
    float loanRate;
    float amount;
    int months;
    int monthCounter = 0; //For incrementing the months for instance i have used it 3 times means after 5 times the next month will start and the amount will be increased according to the rate 
    float change;
    float perMonth;

    //Constructor 
    loanHelper(float r,float a, int m): loanRate(r), amount(a), months(m) {}

    //Member Functions
    void loanRepayment(int repayAmount){
        perMonth = amount / months;
        months++;

        if(monthCounter > 3){
            amount = amount + (amount / months)* loanRate;
        }
        else {
            if(repayAmount < amount){
                amount = amount - repayAmount;
            }
            else{
                cout << "All the Amount is paid" << endl;
                change = repayAmount - amount; 
                cout << "your change is " << change << endl; 
                months = 0;
                perMonth = 0;
            }
        }

        cout << "you have to pay $" << perMonth << " every month to repay your loan" << endl;
        cout << amount << endl;
    }
};


int main(){

    loanHelper loan(0.5,1000,12);
    loan.loanRepayment(100);

    return 0;
}
