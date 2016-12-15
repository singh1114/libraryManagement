#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book{
	string bookName;
	string publisher;
	string Category;
	
	public:
		
		// A function to take the data of the book.
		void getBooks(void);

		// A function to show the data of the books.
		void showBooks(void);

		// A function to find a book for issuing the book
		string getBookToFind(void);

		

};
#endif