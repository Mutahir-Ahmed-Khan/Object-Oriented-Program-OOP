#include <iostream>
using namespace std;

// Class Book
class Book {
public:
    int ID;
    string title;
    string author;
    bool availability;

    Book() {
        ID = 0;
        title = "";
        author = "";
        availability = true;
    }

    Book(int id, string author, string title, bool availability) {
        this->ID = id;
        this->author = author;
        this->title = title;
        this->availability = availability;
    }

    Book(int ID, bool availaibility){
        this -> ID = ID;
        this -> availability = availability;
    }
};

// Class Library
class Library {
private:
    Book* books; 
    int libCount;
    int capacity; 

public:
    Library(int cap = 10) { 
        capacity = cap;
        libCount = 0;
        books = new Book[capacity]; 
    }

    // Method to Add a Book
    void addBook(int id, string author, string title, bool availability) {
        if (libCount == capacity) {
            capacity *= 2;
            Book* newBooks = new Book[capacity];

            for (int i = 0; i < libCount; i++) {
                newBooks[i] = books[i];
            }

            delete[] books; 
            books = newBooks;
        }

        books[libCount] = Book(id, author, title, availability);
        libCount++;
    }

    // Borrow Book Method
    void borrowBook(string name) {
        for (int i = 0; i < libCount; i++) {
            if (books[i].title == name && books[i].availability) {
                books[i].availability = false;
                cout << "Book '" << name << "' borrowed successfully!" << endl;
                return;
            }
        }
        cout << "Book '" << name << "' not available!" << endl;
    }

    // Return Book Method
    void returnBook(string name) {
        for (int i = 0; i < libCount; i++) {
            if (books[i].title == name && !books[i].availability) {
                books[i].availability = true;
                cout << "Book '" << name << "' returned successfully!" << endl;
                return;
            }
        }
        cout << "Book '" << name << "' was not borrowed!" << endl;
    }

    // Display Books Method
    void displayBooks() {
        if (libCount == 0) {
            cout << "No books in the library!" << endl;
            return;
        }

        for (int i = 0; i < libCount; i++) {
            cout << "---------- Book " << i + 1 << " ----------" << endl;
            cout << "Name: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "ID: " << books[i].ID << endl;
            cout << "Availability: " << (books[i].availability ? "Available" : "Not Available") << endl;
            cout << "-----------------------------------" << endl;
        }
    }
};

int main() {
    Library lib(2); 
    
    // Adding books
    lib.addBook(1, "J.K. Rowling", "Harry Potter", true);
    lib.addBook(2, "J.R.R. Tolkien", "The Hobbit", true);
    lib.addBook(3, "George Orwell", "1984", true); 
    
    // Displaying books
    lib.displayBooks();
    
    // Borrowing a book
    lib.borrowBook("The Hobbit");
    lib.displayBooks();
    
    // Returning a book
    lib.returnBook("The Hobbit");
    lib.displayBooks();

    return 0;
}
