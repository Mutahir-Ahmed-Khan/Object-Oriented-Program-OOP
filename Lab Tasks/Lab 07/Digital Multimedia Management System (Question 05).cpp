#include <iostream>
#include <string>
using namespace std;

// Base class
class Media {
protected:
    string title, publicationDate, uniqueID, publisher;

public:
    Media() {}

    void displayInfo() {
        cout << "Displaying media item details.\n";
    }

    void checkOut() {
        cout << "Processing checkout of media item.\n";
    }

    void returnItem() {
        cout << "Processing return of media item.\n";
    }

    // Function overloading
    void search(string title) {
        cout << "Searching by title: " << title << endl;
    }

    void searchByAuthor(string author) {
        cout << "Searching by author: " << author << endl;
    }

    void search(int year) {
        cout << "Searching by publication year: " << year << endl;
    }
};

// Derived class: Book
class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    void displayInfo() {
        cout << "Displaying book details.\n";
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    float rating;

public:
    void displayInfo() {
        cout << "Displaying DVD movie details.\n";
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    void displayInfo() {
        cout << "Displaying CD album details.\n";
    }
};

class Magazine : public Media {
public:
    void displayInfo() {
        cout << "Displaying magazine details.\n";
    }
};
