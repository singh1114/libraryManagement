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
	// First of all check whether the book exist.
	// If yes check if the issued flag is false.
	// If yes check if the student's havebook flag is flase( Make this one)
	// If all them says yes set.
	// havebook = true; issued = true; 

	// First of all go to the stored books file and open it up.
	fstream file("files/booksInfo.txt" ,ios::in|ios::out);
	fstream tempFile("files/tempbook.txt", ios::out|ios::in);

	// Check whether the file is open
	if(!file.is_open()){
		cout<<"We were not able to open the file. Check the permissions.";
	}
	else{
		// place the get and put pointer in the beginning
		file.seekg(0); 
		do{
			// Take in the first object into the buffers.
			getline(file, book.bookName, '\0');
			getline(file, book.publisher, '\0');
			getline(file, book.Category, '\0');
			int pos = file.tellg();
			file.read((char*)&book.issued, sizeof(book.issued));
			if(book.bookName == checkbookName){
				if(book.issued == 0){
					int start = 0;
					string s;
					file.seekg(start);
					s.resize(pos - start);
					file.read(&s[0], pos-start);
					bool boolVar = true;
					s = s + reinterpret_cast<char *>(&boolVar);
					tempFile.write(s.c_str(), pos-start + 1);
					file.seekg(0, ios::end);
					int end = file.tellg();
					pos = pos + 1;
					file.seekg(pos);
					s.resize(end - pos);
					file.read(&s[0], end - pos);
					tempFile.write(s.c_str(), end - pos);

					// Now write the tempFile to the file
					file.seekp(0);
					s.resize(end-start);
					tempFile.seekg(0);
					tempFile.read(&s[0], end-start);
					file.write(s.c_str(), end-start);
					
					return true;
				}
				else{
					cout<<"The book is already issued by a student. But let's check another similar book\n";
					return false;
				}
			}
		}while(!file.eof()); 
	}
	return false;


	/*
	Book book;
	int tempVar = 0;
	fstream file("files/booksInfo.txt", ios::in|ios::app);
	fstream tempFile("files/tempbook.txt", ios::out);
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
			tempFile.write(reinterpret_cast<char *>(&book.issued), sizeof(book.issued));
			while(!file.eof()){
				getline(file, book.bookName, '\0');
				getline(file, book.publisher, '\0');
				getline(file, book.Category, '\0');
				file.read((char*)&book.issued, sizeof(book.issued));

				tempFile.write(book.bookName.c_str(), book.bookName.length() + 1);
				tempFile.write(book.publisher.c_str(), book.publisher.length() + 1);
				tempFile.write(book.Category.c_str(), book.Category.length() + 1);

				filebookName = book.bookName;
				if(checkbookName == filebookName && tempVar == 0){
					book.issued = true;
					tempVar++;
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
	}
	if(tempVar == 0){
		return false;
	}
	else{
		return true;
	}*/
}
