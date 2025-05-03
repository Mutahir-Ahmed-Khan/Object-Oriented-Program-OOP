#include <iostream>
#include <exception>
using namespace std;

class stackOverflowException : public exception{
    public:
    const char* what() const noexcept override{
        return "Stack Overflow Exception - Stack is Full!";
    }
};

class stackUnderflowException : public exception{
    public:
    const char* what() const noexcept override{
        return "Stack Underflow Exception - Stack is Empty!";
    }
};

template <typename T>
class Stack{
    private:
    const T cap = 10; 

    public: 
    void pop(){
        throw stackUnderflowException();
    }

    void push(){
        throw stackOverflowException();
    }
};

int main(){
string str;
Stack <int> s;

    try{
        cout << "Enter the pop or push Function: ";
        cin >> str;
        if(str == "pop"){
            s.pop();
        }
        else if(str == "push"){
            s.push();
        }
    }
    catch(stackUnderflowException &e){
        cout << "Exception: " << e.what() << endl;
    }
    catch(stackOverflowException &e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
