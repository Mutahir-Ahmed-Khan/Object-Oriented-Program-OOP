#include <iostream>
#include <cstring>

using namespace std;

class MenuItem {
private:
    string name;
    double price;
public:
    MenuItem() : name(""), price(0.0) {}
    MenuItem(string name, double price) : name(name), price(price) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
    void display() const { cout << name << " - $" << price << endl; }
};

class Menu {
private:
    MenuItem* items;
    int itemCount;
    int capacity;
public:
    Menu(int cap = 10) : capacity(cap), itemCount(0) {
        items = new MenuItem[capacity];
    }
    
    ~Menu() {
        delete[] items;
    }

    void addItem(const MenuItem& item) {
        if (itemCount < capacity) {
            items[itemCount++] = item;
        } else {
            cout << "Menu is full!\n";
        }
    }

    void displayMenu() const {
        cout << "Menu:\n";
        for (int i = 0; i < itemCount; i++) {
            items[i].display();
        }
    }

    MenuItem* getItem(const string& name) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i].getName() == name) {
                return &items[i];
            }
        }
        return nullptr;
    }
};

class Payment {
private:
    double amount;
public:
    Payment(double amount) : amount(amount) {}
    void display() const {
        cout << "Total Amount Due: $" << amount << endl;
    }
};

class Order {
private:
    MenuItem* orderedItems;
    int itemCount;
    int capacity;
    Payment* payment;
public:
    Order(int cap = 10) : capacity(cap), itemCount(0), payment(nullptr) {
        orderedItems = new MenuItem[capacity];
    }

    ~Order() {
        delete[] orderedItems;
        delete payment;
    }

    void addItem(const MenuItem& item) {
        if (itemCount < capacity) {
            orderedItems[itemCount++] = item;
        } else {
            cout << "Order is full!\n";
        }
    }

    void finalizeOrder() {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += orderedItems[i].getPrice();
        }
        payment = new Payment(total);
    }

    void displayOrder() const {
        cout << "Order Details:\n";
        for (int i = 0; i < itemCount; i++) {
            orderedItems[i].display();
        }
        if (payment) {
            payment->display();
        }
    }
};

class RestaurantOrderingSystem {
private:
    Menu menu;
public:
    RestaurantOrderingSystem() {
        menu.addItem(MenuItem("Burger", 5.99));
        menu.addItem(MenuItem("Pizza", 8.99));
        menu.addItem(MenuItem("Pasta", 7.49));
    }

    void displayMenu() const {
        menu.displayMenu();
    }

    void placeOrder() {
        Order order;
        string itemName;
        char choice;
        do {
            cout << "Enter item name to order: ";
            cin >> itemName;
            MenuItem* item = menu.getItem(itemName);
            if (item) {
                order.addItem(*item);
            } else {
                cout << "Item not found!\n";
            }
            cout << "Add more items? (y/n): ";
            cin >> choice;
        } while (choice == 'y');

        order.finalizeOrder();
        order.displayOrder();
    }
};

int main() {
    RestaurantOrderingSystem system;
    system.displayMenu();
    system.placeOrder();
    return 0;
}

