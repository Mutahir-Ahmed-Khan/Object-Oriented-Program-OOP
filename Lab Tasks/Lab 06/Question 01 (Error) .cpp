#include <iostream>
#include <string>
using namespace std;

class Message{
    private:
    string text;

    public:
    string EncodedMessage;
    int MessageLength;
    //Functions
    void setText(string text){
        this-> text = text;
    }
    string toString(){
        return text;
    }

    //Finding the Keyword (To be Made)

    //Encoding
    void Encoding(){
        string code;
        EncodedMessage = toString();
        MessageLength = EncodedMessage.length();

        for(int i = 0; i < MessageLength; i++){
            code += EncodedMessage[i] + 1; //Concatenating
        }

        cout << "Encoded Message: " << code << endl;
    }

};

class SMS : public Message{
    private:
    string recipientContactNo;

    public:
    string fullMsg;

    //Functions
    //Accessor (Getter)
    string getPhone(){
        return recipientContactNo;
    }
    //Mutator (Setter)
    void setPhone(string recipientContactNo){
        this-> recipientContactNo = recipientContactNo;
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
    sms.Encoding();

    Email email;
    email.setText("This is an Email from Mutahir Ahmed Khan");
    email.setSubject("Testing...");
    email.setSender("MAK");
    email.setReceiver("ABC and XYZ");
    email.EmailConcatenate();

    return 0;
}
