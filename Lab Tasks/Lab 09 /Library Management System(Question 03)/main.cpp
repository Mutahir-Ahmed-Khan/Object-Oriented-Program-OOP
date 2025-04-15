#include "Book.h"
#include <iostream>
using namespace std;

int main(){
	Book b("Ammar Kamran", "Sameed", "892232534");
	Library L;
	cout << b.getAuthor() << endl;
	cout << b.getISBN() << endl;
	cout << b.getTitle() << endl;
	L.addBook();
	L.removeBook();
	L.searchBook();
	
}
