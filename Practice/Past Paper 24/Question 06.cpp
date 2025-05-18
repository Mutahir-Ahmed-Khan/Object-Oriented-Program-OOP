#include <iostream>
#include <exception>
using namespace std;

class Duplicate : public exception{
    public:
    const char* what() const noexcept override{
        cout << "Duplicate Item Exception" << endl;
    }
};

class ItemNotFound : public exception{
    public:
    const char* what() const noexcept override{
        cout << "Item Not Found Exception" << endl;
    }
};

class outOfBound : public exception{
    public:
    const char* what() const noexcept override{
        cout << "Out of Bound Exception" << endl;
    }
};

template <typename T>
class UniqueCart{
    public:
    T *arr; 
    int size;
    int count = 0;

    UniqueCart(int s){
        size = s;
        arr = new T[size];
    }

    ~UniqueCart() {
        delete[] arr; 
    }

    bool contains(const T &item){
        for(int i = 0; i < count ;i++){
            if(arr[i] == item){
                return true;
            }
            else{
                return false;
            }
        }
    }

    void add(const T &item){
        if(contains(item)){
            throw Duplicate();
        }
        if(count < size){
            arr[count++] = item;
        }
        else{
            throw outOfBound(); 
        }
    }

    void display(){
        for(int i = 0; i < count; i++){
            cout << i+1 << ". " <<arr[i] << endl; 
        }
    }

    void remove(const T &item){
        int index = -1;
        for(int i = 0; i < count; i++){
            if(arr[i] == item){
                index = i;
                break;
            }
        }

        if(index == -1){
            throw ItemNotFound(); 
        }

        for(int i = index; i < count - 1; i++){
            arr[i] = arr[i+1];
        }
        count --;
        cout << item << " Removed" << endl;
    }


};

int main() {
    try {
        UniqueCart<string> cart(3);
        cart.add("Cars");
        cart.add("Bikes");
        // cart.add("Planes");
        // cart.add("Bikes");        // Uncomment to test Duplicate
        // cart.add("Trucks");       // Uncomment to test OutOfBound
        cart.remove("Cars");
        // cart.remove("Boats");    // Uncomment to test ItemNotFound
        cart.display();
    } catch (exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
