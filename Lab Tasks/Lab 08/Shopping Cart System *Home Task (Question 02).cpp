#include <iostream>
#include <iomanip>
using namespace std;

class Product{
    private:
    int productID;
    float price;

    public: 
    Product(int id, float p) : productID(id) , price(p) {}

    //getter and setter 
    float getPrice(){
        return price;
    }

    //Virtual Function
    virtual void calcPrice() = 0;
}; 

class Electronics : public Product{
    private:
    const float tax = 0.15;
    float res;
    float dis;

    public:
    Electronics(int id,float p) : Product(id,p) {
        cout << right << setw(30) << "-----Electronics-----" << endl;
    }

    //Virtual Function 
    void calcPrice() override {
        res = getPrice() + (getPrice() * tax);
        cout << "Amount after 15% tax: ($" << res << ")" << endl;
    }

    //Discounts
    void Discount(const float discount, int productID){
        dis = getPrice() - (getPrice() * discount);
        cout << "Amount Before: $" << getPrice() << " After " << "(" << discount * 100 << "% OFF): $" << dis << endl;
    }

    void Discount(const int discount){
        dis = getPrice() -  discount;
        cout << "Amount Before: $" << getPrice() << " After " << "($" << discount  << " OFF): $" << dis << endl;
    }

    void Discount(){
        cout << "Bought One Get One Free" << endl;
    }
};

class Clothing : public Product{
    private:
    const float tax = 0.05;
    float res;
    float dis;

    public:
    Clothing(int id,float p) : Product(id,p) {
        cout << right << setw(30) << "-----Clothing-----" << endl;
    }

    //Virtual function 
    void calcPrice() override {
        res = getPrice() + (getPrice() * tax);
        cout << "Amount after 5% tax: (" << res << ")Rs" << endl;
    }

    //Discounts
    void Discount(const float discount, int productID){
        dis = getPrice() - (getPrice() * discount);
        cout << "Amount Before: $" << getPrice() << " After " << "(" << discount * 100 << "% OFF): $" << dis << endl;
    }

    void Discount(const int discount){
        dis = getPrice() -  discount;
        cout << "Amount Before: $" << getPrice() << " After " << "($" << discount  << " OFF): $" << dis << endl;
    }

    void Discount(){
        cout << "Bought One Get One Free" << endl;
    }
};

int main(){
    

return 0;
}
