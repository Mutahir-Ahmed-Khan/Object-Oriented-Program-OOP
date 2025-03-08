#include <iostream>
using namespace std;

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
