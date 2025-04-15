#include "Book.h"
#include <iostream>
using namespace std;


	Book::Book(string t, string a, string I) : title(t), author(a), ISBN(I){}
	Book::Book() {}
	
	string Book::getTitle(){
		return title;
	}
	string Book::getAuthor(){
		return author;
	}
	string Book::getISBN(){
		return ISBN;
	}
	

		
		void Library::addBook(){
				cout << "Adding the Book..." << endl;
			}
			void Library::removeBook(){
				cout << "Removing Book..." << endl; 
			}
			void Library::searchBook(){
				cout << "Searching Book" << endl;
			}




