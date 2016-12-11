#include "../header/book.h"

/*
function name : getBooks
description : This function takes the information of a book
*/
void Book::getBooks(void){
	cout<<"Enter the name of the book without spaces : ";
	cin>>Book::bookName;
	cout<<"Enter the name of the publisher : ";
	cin>>Book::publisher;
	cout<<"Enter the category of the book : ";
	cin>>Book::Category;
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


