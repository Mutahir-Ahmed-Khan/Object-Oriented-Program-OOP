class Customer {
private:
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
    Customer() {
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

    ~Customer() {
        // We assume JewelryItem objects are managed externally
        delete[] purchasedItems;
    }
};
