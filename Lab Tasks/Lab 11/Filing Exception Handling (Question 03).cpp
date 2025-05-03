#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Base class
class FileException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "FileException: An error occurred with the file.";
    }
};

// Derived class: FileNotFound
class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "FileNotFoundException: File not found.";
    }
};

// Derived class: PermissionDenied
class PermissionDeniedException : public FileException {
public:
    const char* what() const noexcept override {
        return "PermissionDeniedException: Access denied!";
    }
};

// Function that throws based on filename
void readFile(const string& filename) {
    if (filename == "missing.txt") {
        throw FileNotFoundException();
    }
    else if (filename == "secret.txt") {
        throw PermissionDeniedException();
    }
    else {
        cout << "Reading '" << filename << "': Success!" << endl;
    }
}

int main() {
    string filename;
    cout << "Enter filename to read: ";
    cin >> filename;

    try {
        readFile(filename);
    }
    catch (const FileNotFoundException& e) {
        cout << "Reading '" << filename << "': " << e.what() << endl;
    }
    catch (const PermissionDeniedException& e) {
        cout << "Reading '" << filename << "': " << e.what() << endl;
    }
    catch (const FileException& e) {
        cout << "Reading '" << filename << "': " << e.what() << endl;
    }

    return 0;
}
