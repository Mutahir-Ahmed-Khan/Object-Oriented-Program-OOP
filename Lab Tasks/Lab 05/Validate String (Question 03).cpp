#include <iostream>
using namespace std;

//Nothing would be happened if we did not make this function const as const function does not change the Values of variable, but would not work if we try to call it from const object 
//What happens if you do not make your function constant? Add a comment right above your function explaining why we make a function constant.

class ValidateString {
private:
    string text;  

public:

    ValidateString(string t) : text(t) {}

    void checkString() const {
        int sizeOfString = text.length();  

        for (int i = 0; i < sizeOfString; i++) {
            if (!((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))) {
                cout << "Invalid character found: " << text[i] << endl;
                return;
            }
        }
        cout << "Valid String: " << text << endl;
    }
};

int main(){
    ValidateString str1("Hello");
    ValidateString str2("World123");
    ValidateString str3("C++Rocks");
    ValidateString str4("ValidString");

    str1.checkString();
    str2.checkString();
    str3.checkString();
    str4.checkString();
    return 0;
}
