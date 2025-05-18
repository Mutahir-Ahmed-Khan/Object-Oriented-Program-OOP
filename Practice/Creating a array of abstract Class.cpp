class Customer {
private:
    string customerID;
    string name;
    JewelryItem** purchasedItems; // dynamic array of pointers
    int itemCount;
    int capacity;

    void resize() {
        capacity *= 2;
        JewelryItem** newItems = new JewelryItem*[capacity];
        for (int i = 0; i < itemCount; i++) {
            newItems[i] = purchasedItems[i];
        }
        delete[] purchasedItems;
        purchasedItems = newItems;
    }

public:
    Customer(string id = "", string n = "") {
        customerID = id;
        name = n;
        capacity = 2;
        itemCount = 0;
        purchasedItems = new JewelryItem*[capacity];
    }

    void purchaseItem(JewelryItem* item) {
        if (itemCount >= capacity) {
            resize();
        }
        purchasedItems[itemCount++] = item;
    }

    double calculateTotalPurchasePrice() {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += purchasedItems[i]->calculatePrice();
        }
        return total;
    }

    void displayPurchasedItems() {
        cout << "Customer ID: " << customerID << ", Name: " << name << endl;
        cout << "Purchased Items:" << endl;
        for (int i = 0; i < itemCount; i++) {
            purchasedItems[i]->displayDetails();
            cout << "--------------------" << endl;
        }
        cout << "Total Price: " << calculateTotalPurchasePrice() << endl;
    }

    ~Customer() {
        // We assume JewelryItem objects are managed externally
        delete[] purchasedItems;
    }
};
