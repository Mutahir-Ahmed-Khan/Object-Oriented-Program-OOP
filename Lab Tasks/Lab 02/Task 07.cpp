You are tasked with building a simple product management system for an online store.
1. Create a function that allows the addition of a new product to the system. The function should
take parameters such as product name, price, quantity, and any other relevant details.
2. Implement a function that takes a product ID as input and displays detailed information about the
product, including its name, price, quantity in stock, and any other relevant details.
3. Design a function that enables the update of product information. It should take a product ID as
well as the new details (e.g., updated price, quantity, etc.) and modify the existing product&#39;s
information accordingly.

4. Create a function that removes a product from the system based on its product ID. Ensure that
the inventory is updated after the removal.

--------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct Product{
    string name;
    int id; 
    int price;
    string type;
    int quantity;
};

void add(Product products[10], int &size){
    if(size >= 10){
        cout << "The List is Full, Cant Add more" << endl;
        return;
    }

    cout << "Enter the Product ID: ";
    cin >> products[size].id;
    cin.ignore();

    cout << "Enter the Name Of The Product: ";
    getline(cin, products[size].name);

    cout << "Enter the Price of the Product: ";
    cin >> products[size].price;
    cin.ignore();

    cout << "Enter the Quantity of the Product:";
    cin >> products[size].quantity;
    cin.ignore();

    cout << "Enter the Type of the Product:";
    getline(cin, products[size].type);

    size++;
    cout << "The Product Has been Addedd successfully in the List" << endl;
    
}

void display(Product products[10], int productID,int &size){
    for(int i = 0; i < size ; i++){
        if(products[i].id == productID){
            cout << "----------------------------------" << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: $" << products[i].price << endl; 
            cout << "Quantity: " << products[i].quantity << endl;
            cout << "Type: " << products[i].type << endl;
            cout << "-----------------------------------" << endl;
        }
        else{
            cout << "Invalid Product ID" << endl;
        }
    }
}

void update(Product products[10], int &size, int productID){
    for (int i = 0; i < size; i++) {
        if (products[i].id == productID) {
            cout << "Enter New Price: ";
            cin >> products[i].price;
            cout << "Enter New Quantity: ";
            cin >> products[i].quantity;
            cin.ignore();
            cout << "Enter New Type: ";
            getline(cin, products[i].type);
            cout << "Product updated successfully!\n";
            return;
        }
    }
    cout << "Product not found" << endl;
}

void remove(Product products[10], int &size, int productID) {
    for (int i = 0; i < size; i++) {
        if (products[i].id == productID) {
            for (int j = i; j < size - 1; j++) {
                products[j] = products[j + 1];
            }
            size--;
            cout << "Product removed successfully";
            return;
        }
    }
    cout << "Product not found" << endl;
}


int main(){
    int size = 0;
    Product products[10];
    int option;
    int productID;

    while(true){
        cout << "-----Menue-----"<< endl;
        cout << "1. Add " << endl;
        cout << "2. Display" << endl; 
        cout << "3. Update " << endl; 
        cout << "4. Remove " << endl;
        cout << "5. Exit" << endl;
        cout << "----------------" << endl; 

        cout << "Enter the Option: ";
        cin >> option;

        switch(option){
            case 1: 
                add(products, size);
                break;
            case 2:
                cout << "Enter the ID of the Product: "; 
                cin >> productID;
                display(products,productID,size);
                break;
            case 3:
                cout << "Enter the ID of the Product to change the Information: ";
                cin >> productID;

                update(products,size,productID);
                break;
            case 4:
                cout << "Enter Product ID: ";
                cin >> productID;
                remove(products, size, productID); 
                break;
            case 5:
                cout << "The Program has Been Ended" << endl; 
                return 0; 
            default: 
                cout << "invlaid Option Selected" << endl; 
                break;
        } 
    }


}

