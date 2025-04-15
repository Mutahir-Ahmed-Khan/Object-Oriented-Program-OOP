#ifndef BOOK
#define BOOK
#include <string>
using namespace std;

class Book{
	private:
		string title;
		string author; 
		string ISBN;
	
	public:
		Book(string t, string a, string I);
		Book();
		
		string getTitle();
		string getAuthor();
		string getISBN();
};

	class Library{
		private:
		Book books[10];
		
		public:
			void addBook();
			void removeBook();
			void searchBook();
	};

#endif
