#include <iostream>
#include <conio.h>
using namespace std;

class tollBooth{
    public:
        int cars;
        double money;
        //constructor
        tollBooth():cars(0), money(0){
        }

        //PayingCars
        void payingCars(){
            cars++;
            money = money + 0.50;
        }

        //NoPayers
        void noPay(){
            cars++;
        }

        //Display 
        void display(){
            cout << "Total Number of Cars Passed " << cars << endl;
            cout << "Total Money Collected is " << money << endl;
        }
        
};


int main(){
    int t = 1;
    char option;
    tollBooth O1;

        cout << "--------------------" << endl;
        cout << "Press 'p' or 'P' to pass a car with money" << endl;
        cout << "Press 'n' or 'N' to pass a car with no Money" << endl;
        cout << "ESC to Exit" << endl;
        cout << "--------------------" << endl;

    while(t){
        option = _getch();

        switch(option){
            case 'p':
            case 'P':
                O1.payingCars();
                cout << "Passed*" << endl;
                break;
            case 'n':
            case 'N':
                O1.noPay();
                cout << "Passed" << endl;
                break;
            case 27:
                O1.display();
                t=0;
                break;
            default:
                cout << "Entered the Wrong Option" << endl;
                break;
        }
    }
    return 0;
}
