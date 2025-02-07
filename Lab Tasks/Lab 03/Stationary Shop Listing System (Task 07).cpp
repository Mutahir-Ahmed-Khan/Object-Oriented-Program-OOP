#include <iostream>
using namespace std;

class stationary{
    public:
        string item[5] = {"Apple","Mango", "Watermelon", "Orange", "Banana"};
        int price[5]= {20,60,70,60,40};
};

int main(){
    int option;
    stationary shop;
    string list[10];
    int k = 0;
    int t = 1;
    int dollar[10];
    int change;
    int C_price;

    //creating a menue 
    cout << "---------- MENU ----------" << endl;
    cout << "--- ITEMS ---"<< endl;
    cout << "0. Apple" << endl;
    cout << "1. Mango" << endl;
    cout << "2. Watermelon" << endl;
    cout << "3. Orange" << endl;
    cout << "4. Banana" << endl;
    cout << "-------------" << endl;
    cout << "5. Show list " << endl;
    cout << "6. Edit the Price" << endl;
    cout << "7. EXIT" << endl;

    while(t){
        cout << "---------------------------" << endl;
        cout << "CHOOSE OPTIONS: ";
        cin >> option;
        cout << "---------------------------" << endl;

        switch(option){
            case 0: 
                list[k] = shop.item[option];
                dollar[k] = shop.price[option];
                k++;
                break;
            case 1:
                list[k] = shop.item[option];
                dollar[k] = shop.price[option];
                k++;
                break;
            case 2:
                list[k] = shop.item[option];
                dollar[k] = shop.price[option];
                k++;
                break;
            case 3:
                list[k] = shop.item[option];
                dollar[k] = shop.price[option];
                k++;
                break;
            case 4:
                list[k] = shop.item[option];
                dollar[k] = shop.price[option];
                k++;
                break;
            case 5:
                for(int i = 0; i < k; i++){
                cout << list[i] << "---" << "$" << dollar[i] <<  endl; 
                }
                break;
            case 6:
                cout << "Enter the number of item to change its price: ";
                cin >> change;
                cout << "Enter the Price you want to change: ";
                cin >> C_price;

                dollar[change] = C_price;
                break;
            case 7:
                t=0;
                break;
            default:
                cout << "Entered the Wrong Option" << endl;
                break;
        }
    }   
return 0;
}
