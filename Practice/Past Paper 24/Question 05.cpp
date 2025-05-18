#include <iostream>
#include <vector>
using namespace std;

class jewerlyItem{
    private: 
    string itemCode; 
    string itemName; 
    double weight;
    int purity; 

    public: 
    jewerlyItem(string c, string n, double w, int p)
        :itemCode(c), itemName(n), weight(w), purity(p) {}

    virtual void display() = 0; 
    virtual double calcPrice() = 0;

    double getWeight(){
        return weight; 
    }

    string getCode(){
        return itemCode;
    }

    string getName(){
        return itemName;
    }

    int getPurity(){
        return purity;
    }
};

class Gold :public jewerlyItem{
    private:
    int goldKarat;

    public: 
    Gold(string c, string n, double w, int p) 
        :jewerlyItem(c,n,w,p) {}
        
    void setGoldKarat(int goldKarat){
        this->goldKarat = goldKarat;
    }

    double calcPrice() override{ 
        return getWeight() * getPurity() * goldKarat; 
    }

    void display() override{
        cout << "Item Code: " << getCode() << endl; 
        cout << "Item Name: " << getName() << endl; 
        cout << "Weight: " << getWeight() << endl; 
        cout << "Purity: " << getPurity() << endl; 
        cout << "Karat: " << goldKarat << endl;
    }

};

class Diamond :public jewerlyItem{
    private:
    int numDiamond;
    double diamondCarat;

    public: 
    Diamond(string c, string n, double w, int p) 
        :jewerlyItem(c,n,w,p) {}
        
    void addDiamond(int num, double carat){ 
        numDiamond = num; 
        diamondCarat = carat;
    }

    double calcPrice() override {
        return getWeight() * getPurity() + numDiamond * diamondCarat * 1000;
    }
    

    void display() override{
        cout << "Item Code: " << getCode() << endl; 
        cout << "Item Name: " << getName() << endl; 
        cout << "Weight: " << getWeight() << endl; 
        cout << "Purity: " << getPurity() << endl;
        cout << "Number of diamonds: " << numDiamond << endl; 
        cout << "Diamond Karat: " << diamondCarat << endl; 
    }

};

class Customer{
    private: 
    string ID; 
    string name;
    jewerlyItem **purchasedItems;
    int cap; 
    int itemCount;

    void resize(){
        cap = cap * 2;
        jewerlyItem **newItems = new jewerlyItem*[cap];
        for(int i = 0; i < itemCount; i++){
            newItems[i] = purchasedItems[i]; 
        }

        delete[] purchasedItems; 
        purchasedItems = newItems;
    }

    public: 
    Customer(string id, string n)
        :ID(id), name(n){
            cap = 2; 
            itemCount = 0; 
            purchasedItems = new jewerlyItem*[cap];
        }

    void purchaseItem(jewerlyItem *item){
        if(itemCount >= cap){
            resize();
        }

        purchasedItems[itemCount++] = item;
    }

    double calcAllPurchases(){ 
        double total = 0; 
        for(int i = 0; i < itemCount; i++){
            total = total + purchasedItems[i]->calcPrice();
        }

        return total;
    }

    ~Customer(){
        delete[]  purchasedItems;
    }

};

class store{
    private: 
    jewerlyItem **inventory;
    int cap; 
    int count;

    void resize(){
        cap = cap * 2;
        jewerlyItem **newInv = new jewerlyItem*[cap];
        for(int i = 0; i < count; i++){
            newInv[i] = inventory[i]; 
        }

        delete[] inventory; 
        inventory = newInv;
    }

    public: 
    store(){
        cap = 2;
        count = 0;
        inventory = new jewerlyItem*[cap];
    }

    void addItem(jewerlyItem *itemm){ 
        if(count >= cap){
            resize();
        }

        inventory[count++] = itemm;
    }

    void displayInv(){
        for(int i = 0; i < count; i++){
            inventory[i]->display();
            cout << endl;
        }
    }

    ~store(){
        delete[] inventory;
    }

};

bool operator==(jewerlyItem &a, jewerlyItem&b){
    return a.calcPrice() == b.calcPrice();
}

bool operator<(jewerlyItem &a, jewerlyItem&b){
    return a.calcPrice() < b.calcPrice();
}

bool operator>(jewerlyItem &a, jewerlyItem&b){
    return a.calcPrice() < b.calcPrice();
}

int main(){

    Gold gold("101","Bracelet",100,10);
    gold.setGoldKarat(22);

    Diamond diamond("D001", "Ring", 5.2, 90);
    diamond.addDiamond(2, 0.5);

    Customer c("102","Ali");
    c.purchaseItem(&gold);
    c.purchaseItem(&diamond);

    cout << "Total Price is: " << c.calcAllPurchases() << endl; 

    store s;
    s.addItem(&gold);
    s.addItem(&diamond);

    s.displayInv();

    if(diamond == gold){
        cout << "Equal in Price" << endl; 
    }
    else if(diamond > gold){
        cout << "diamond price is greater" << endl; 
    }
    else{
        cout << "Gold is Greater" << endl;
    }


    return 0;
}
