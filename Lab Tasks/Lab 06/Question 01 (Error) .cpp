#include <iostream>
#include <string>
using namespace std;

class Message{
    private:
    string text;

    public:
    //Functions
    void setText(string text){
        this-> text = text;
    }
    string toString(){
        return text;
    }

    bool ContainKeyword(const Message &messageObject, const string &keyword) {
        string msg = messageObject.toString(); 
        int textLength = msg.length();
        int keywordLength = keyword.length();

        if (keywordLength > textLength) {
            return false; 
        }

        for (int i = 0; i <= textLength - keywordLength; i++) {
            bool match = true;
            for (int j = 0; j < keywordLength; j++) {
                if (msg[i + j] != keyword[j]) {
                    match = false;
                    break; 
                }
            }
            if (match) {
                return true; 
            }
        }
        return false; 
    }
};


class SMS : public Message{
    private:
    string recipentContactNo;

    public:
    string fullMsg;

    //Functions
    //Accessor (Getter)
    string getPhone(){
        return recipentContactNo;
    }
    //Mutator (Setter)
    void setPhone(string recipentContactNo){
        this-> recipentContactNo = recipentContactNo;
    }

    //Concatenating
    void MessageConcatenate(){
        fullMsg = getPhone() + " : " + toString();
        cout << fullMsg << endl;
    }

};

class Email : public Message{
    private:
    string receiver;
    string sender;
    string subject;

    public:
    string fullEmail;

    //Functions
    void setReceiver(string receiver){
        this-> receiver = receiver;
    }
    string getReceiver(){
        return receiver;
    }

    void setSender(string sender){
        this-> sender = sender;
    }
    string getSender(){
        return sender;
    }

    void setSubject(string subject){
        this-> subject = subject;
    }
    string getSubject(){
        return subject;
    } 

    void EmailConcatenate(){
        fullEmail = "Subject: " + getSubject() + "\n" + "Sender: " + getSender() + "\n" + "Receiver: " + getReceiver() + "\n" + toString();
        cout << fullEmail << endl;
    }

};

int main(){
    SMS sms;

    sms.setText("Hello My name is Mutahir Ahmed Khan");
    sms.setPhone("0300-0073812");
    sms.MessageConcatenate();

    string keyword1 = "Mutahir";
    if (sms.ContainKeyword(sms, keyword1)) {
        cout << "Keyword '" << keyword1 << "' found in SMS!" << endl;
    } 
    else {
        cout << "Keyword '" << keyword1 << "' not found in SMS!" << endl;
    }

    Email email;
    email.setText("This is an Email from Mutahir Ahmed Khan");
    email.setSubject("Testing...");
    email.setSender("MAK");
    email.setReceiver("ABC and XYZ");
    email.EmailConcatenate();

    return 0;
}
