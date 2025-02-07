#include <iostream>
using namespace std;

class Smartphone{
    private:
        string company;
        int model;
        string display;
        int RAM;
        int ROM;
        int storage;
    public:
        //Getter and Setter for the company
        string getCompany(){
            return company;
        }
        void setCompany(string name){
            company = name;
        }

        //Getter and Setter for the model
        int getModel(){
            return model;
        }
        void setModel(int model_num){
            model = model_num;
        }

        //getter and setter for the display 
        string getDisplay(){
            return display;
        }
        void setDisplay(string display01){
            display = display01;
        }

        //getter and setter for the RAM 
        int getRAM(){
            return RAM;
        }
        void setRAM(int E_RAM){
            RAM = E_RAM;
        }

        //getter and setter for the ROM
       int getROM(){
            return ROM;
        }
        void setROM(int ROM_E){
            ROM = ROM_E;
        } 

        //getter and setter for the storage
        int getStorage(){
            return storage;
        }
        void setStorage(int E_Storage){
            storage = E_Storage;
        }
};



int main(){
    Smartphone mobile;

    mobile.setCompany("Apple");
    mobile.setModel(2010);
    mobile.setDisplay("1080p");
    mobile.setRAM(14);
    mobile.setROM(16);
    mobile.setStorage(64);

    cout << "Company:" << mobile.getCompany() << endl;
    cout << "Model:" << mobile.getModel() << endl;
    cout << "Display:" << mobile.getDisplay() << endl;
    cout << "RAM:" << mobile.getRAM() << endl;
    cout << "ROM:" << mobile.getROM() << endl;
    cout << "Storage:" << mobile.getStorage() << endl; 


    return 0;
}
