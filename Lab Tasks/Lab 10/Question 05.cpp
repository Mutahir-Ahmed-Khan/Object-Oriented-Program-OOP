#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("data.txt");
    outFile << "AI is the future. AI will transform the world. Embrace AI now.";
    outFile.close();

    string searchWord, replacementWord;
    cout << "Enter the word to search: ";
    cin >> searchWord;
    cout << "Enter the replacement word: ";
    cin >> replacementWord;

   

    fstream file("data.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return 1;
    }

    string word = "";
    char ch;
    streampos pos;
    while (file.get(ch)) {
        if (ch == ' ' || ch == '.' || ch == '\n') {
            if (word == searchWord) {
                pos = file.tellg();
                streamoff wordStart = pos - word.length() - 1;
                file.seekp(wordStart);
                file << replacementWord;
                file.seekg(pos);
            }
            word = "";
        } else {
            word += ch;
        }
    }

    file.close();

    ifstream updatedFile("data.txt");
    string line;
    cout << "\nUpdated file content:\n";
    while (getline(updatedFile, line)) {
        cout << line << endl;
    }
    updatedFile.close();

    return 0;
}
