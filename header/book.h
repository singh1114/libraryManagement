#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book{
	char bookName[80];
	char publisher[80];
	char Category[20];
	
	public:
		
		// A function to take the data of the book.
		void getBooks(void);

		// A function to show the data of the books.
		void showBooks(void);

		// A function to search the books
		bool findBooks(char bookName[80]);

};
#endif