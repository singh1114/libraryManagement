#include "../header/book.h"

/*
function name : getBooks
description : This function takes the information of a book
*/
void Book::getBooks(void){
	cout<<"Enter the name of the book : ";
	/* http://stackoverflow.com/questions/18786575/using-getline-in-c
		We have used cin.ignore to flush the newline character(\n) out of
		the buffer. If not used bookName variable will have null value.
	*/
	cin.ignore();
	getline(cin, Book::bookName);
	cout<<"Enter the name of the publisher : ";
	getline(cin, Book::publisher);
	cout<<"Enter the category of the book : ";
	getline(cin, Book::Category);
	Book::issued = false;
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
	cout<<"Book is issued : ";
	cout<<this->issued<<"\n";
}

/*
function name : getBookToFind
description : This function get the book from the user and tries to find
			  that book in the booksInfo file for the issuing purpose.
*/
string Book::getBookToFind(void){
	string searchBook;
	cout<<"#############################\n";
	cout<<"Enter the name of the book that you want to get issued : ";
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

bool Book::findBook(string checkbookName){
	Book book;
	int tempVar = 0;
	fstream file("files/booksInfo.txt", ios::in|ios::out|ios::app);
	fstream tempFile("files/tempbook.txt", ios::in|ios::out);
	if(!file.is_open() || !tempFile.is_open()){
		cout<<"We were not able to open the file. Check the permissions.\n";
	}
	else{
		file.seekg(0);
		tempFile.seekg(0);
		
		// Take in whole of the stuff into the buffers.
		getline(file, book.bookName, '\0');
		getline(file, book.publisher, '\0');
		getline(file, book.Category, '\0');
		file.read((char*)&book.issued, sizeof(book.issued));

		// Now put all the strings into a temporary file.
		tempFile.write(book.bookName.c_str(), book.bookName.length() + 1);
		tempFile.write(book.publisher.c_str(), book.publisher.length() + 1);
		tempFile.write(book.Category.c_str(), book.Category.length() + 1);

		string filebookName = book.bookName;
		if(checkbookName == filebookName){
			book.issued = true;
			tempVar++;
			cout<<book.issued;
			tempFile.write(reinterpret_cast<char *>(&book.issued), sizeof(book.issued));
		}
		else{
			file.write(reinterpret_cast<char *>(&book.issued), sizeof(book.issued));
			while(!file.eof()){
				getline(file, book.bookName, '\0');
				getline(file, book.publisher, '\0');
				getline(file, book.Category, '\0');
				file.read((char*)&book.issued, sizeof(book.issued));

				tempFile.write(book.bookName.c_str(), book.bookName.length() + 1);
				tempFile.write(book.publisher.c_str(), book.publisher.length() + 1);
				tempFile.write(book.Category.c_str(), book.Category.length() + 1);

				filebookName = book.bookName;
				if(checkbookName == filebookName){
					book.issued = true;
					tempVar++;
					cout<<"was it here";
					tempFile.write(reinterpret_cast<char *>(&book.issued), sizeof(book.issued));
				}
				else{
					tempFile.write(reinterpret_cast<char *>(&book.issued), sizeof(book.issued));
				}
			}
		}
		while(!file.eof()){
			getline(file, book.bookName, '\0');
			getline(file, book.publisher, '\0');
			getline(file, book.Category, '\0');
			file.read((char*)&book.issued, sizeof(book.issued));

			tempFile.write(book.bookName.c_str(), book.bookName.length() + 1);
			tempFile.write(book.publisher.c_str(), book.publisher.length() + 1);
			tempFile.write(book.Category.c_str(), book.Category.length() + 1);
			tempFile.write(reinterpret_cast<char *>(&book.issued), sizeof(book.issued));
		}
		file.close();
		tempFile.close();
		cout<<tempVar;
	}
	if(tempVar == 0){
		return false;
	}
	else{
		return true;
	}
}
