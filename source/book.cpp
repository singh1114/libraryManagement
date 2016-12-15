#include "../header/book.h"

/*
function name : getBooks
description : This function takes the information of a book
*/
void Book::getBooks(void){
	cout<<"Enter the name of the book without spaces : ";
	/* http://stackoverflow.com/questions/18786575/using-getline-in-c
		We have used cin.ignore to flush the newline character(\n) out of
		the buffer. If not used bookName variable will have null value.
	*/
	cin.ignore();
	getline(cin, Book::bookName);
	cout<<"Enter the name of the publisher : ";
	cin.ignore();
	getline(cin, Book::publisher);
	cout<<"Enter the category of the book : ";
	cin.ignore();
	getline(cin, Book::Category);
}

/*
function name : showBooks
description : This function shows the information of a book
*/
void Book::showBooks(void){
	cout<<"The name of the book is : ";
	cout<<this->bookName<<"\n";
	cout<<"The publisher of the book is : ";
	cout<<this->publisher<<"\n";
	cout<<"The category of the book is : ";
	cout<<this->Category<<"\n";
}

/*
function name : getBookToFind
description : This function get the book from the user and tries to find
			  that book in the booksInfo file for the issuing purpose.
*/
string Book::getBookToFind(void){
	string searchBook;
	cout<<"#############################\n";
	cout<<"Enter the name of the book that you want to get issued";
	/* http://stackoverflow.com/questions/18786575/using-getline-in-c
		We have used cin.ignore to flush the newline character(\n) out of
		the buffer. If not used bookName variable will have null value.
	*/
	cin.ignore();
	// getline is used to take the string with the spaces included.
	getline(cin, searchBook);
	cout<<"####################################\n";
	return searchBook;
}



