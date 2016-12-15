#include "../header/admin.h"
#include "../header/student.h"
#include "../header/book.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <string>
// This function is going to show all the operations of the admin on the screen

void Admin::showOperations(void){
	cout<<"1. ADD STUDENT";
	cout<<endl;
	cout<<"2. SHOW STUDENTS";
	cout<<endl;
	cout<<"3. ADD BOOKS";
	cout<<endl;
	cout<<"4. ISSUE BOOKS";
	cout<<endl;
	cout<<"5. TAKE BOOKS BACK";
	cout<<endl;
	cout<<"6. SHOW ALL BOOKS\n";
	cout<<"CHOOSE AN OPERATION FROM THE LIST";
	cout<<endl;
}

// This function maps the operation choosen by the admin to the code of the operations.
void Admin::operate(void){
	Admin user;
	int x;
	cin>>x;
	if(x == 1){
		user.addStudent();
	}
	else if(x == 2){
		user.showStudent();
	}
	else if(x == 3){
		user.addBook();
	}
	else if(x == 4){
		user.issueBook();
	}
	else if(x == 5){
		user.takeBookBack();
	}
	else if(x == 6){
		user.showBooks();
	}
	else{
		cout<<"Not a valid operation";
	}
}

// This function is used to add a student to a list
// This list will contain all the students that can access the library.
void Admin::addStudent(void){
	// The students can be added into a file.
	// The files are going to be stored in the '../files/'
	
	// Create a object of class student
	Student student;
	char x;

	//Create a object of the file.
	fstream file("files/studentInfo.dat", ios::app|ios::out|ios::binary);

	// Check wheather the file is open or not.
	if(!file.is_open()){
		cout<<"file is not open";
	}
	else{
		do{
			cout<<"Enter the data fo the student\n";

			// Here is the function that get the students data.
			student.getStudentInfo();
			// Write the content to the file in the form of binary or any other form
			file.write(student.name.c_str(), student.name.length() + 1);
			file.write(reinterpret_cast<char*>(&student.age), sizeof(student.age));
			file.write(reinterpret_cast<char*>(&student.studClass), sizeof(student.studClass));
			file.write(reinterpret_cast<char*>(&student.rollno), sizeof(student.rollno));
			file.write(reinterpret_cast<char*>(&student.phoneNumber), sizeof(student.phoneNumber));

			// Ask the user if you want to enter more values.
			cout<<"Do you want to enter more(y/n)?";
			cin.ignore();
			cin>>x;
		}while(x=='y');
		cout<<"ALL Student data is saved";
		file.close();
	}
	cout<<endl;
	cout<<"##############################################";
	cout<<endl;
	Admin admin;
	admin.showOperations();
	admin.operate();
	
}
void Admin::showStudent(void){
	Student student;

	//Open the file in input mode
	fstream file("files/studentInfo.dat", ios::in|ios::binary);
	if(!file.is_open()){
		cout<<"File not opened";
	}
	else{
		// Now bring the file pointer back to the starting position
		file.seekg(0);

		// Now it is the time to read the file.
		// The following line reads a single object and shifts the file pointer after one object.
		getline(file, student.name,'\0');
		file.read((char*)&student.age, sizeof(student.age));
		file.read((char*)&student.studClass, sizeof(student.studClass));
		file.read((char*)&student.rollno, sizeof(student.rollno));
		file.read((char*)&student.phoneNumber, sizeof(student.phoneNumber));

		// While the end of file is not reached.
		while(!file.eof()){
			cout<<endl;
			cout<<"#################################################";
			// This function shows the data on the terminal
			student.showStudentInfo(student);
			// This function reads another object
			getline(file, student.name,'\0');
			file.read((char*)&student.age, sizeof(student.age));
			file.read((char*)&student.studClass, sizeof(student.studClass));
			file.read((char*)&student.rollno, sizeof(student.rollno));
			file.read((char*)&student.phoneNumber, sizeof(student.phoneNumber));
			cout<<endl;
			cout<<"##################################################";
		}
		file.close();
	}
}
/*
Name of the function : addBook
description : this function takes the info of the book using the function defined
			  in the book.cpp file and writes the object to the file named 
			  bookinfo.txt
*/
void Admin::addBook(void){
	cout<<"#############################################################\n";
	// First create a object of the Books class.
	Book book;
	char x;

	fstream file("files/booksInfo.txt", ios::app | ios::out);

	if(!file.is_open()){
		cout<<"File can't be opened";
	}
	else{
		do{
			cout<<"Enter the information of the book.\n";
			
			// Call the function to read the values
			book.getBooks();

			// write the object to the file.
			file.write((char *)&book, sizeof(book));

			cout<<"Do you want to enter more values.\n";
			cin>>x;
		}while(x == 'y');
		cout<<"DATA entered is saved into the files";
		file.close();
	}
	cout<<endl;
	cout<<"##############################################\n";
	cout<<endl;
	Admin admin;
	admin.showOperations();
	admin.operate();
}


/*
function name : showBooks
description : This function will show all the books one by one by reading them from the 
			  file ../files/booksInfo.txt
*/
void Admin::showBooks(void){
	Book book;

	//Open the file in input mode
	fstream file("files/booksInfo.txt", ios::in);
	if(!file.is_open()){
		cout<<"File not opened";
	}
	else{
		// Now bring the file pointer back to the starting position
		file.seekg(0);

		// Now it is the time to read the file.
		// The following line reads a single object and shifts the file pointer after one object.
		file.read((char *)&book, sizeof(book));
		// While the end of file is not reached.
		while(!file.eof()){
			cout<<endl;
			cout<<"#################################################\n";
			// This function shows the data on the terminal
			book.showBooks();
			// This function reads another object
			file.read((char *)&book, sizeof(book));
			cout<<endl;
			cout<<"##################################################\n";
		}
		file.close();
	}

}

/*
function name : issueBook
description : This function allows the students to get the books issued.
			  First it checks wheather the book is present, if yes is returned 
			  then it get the book out of the bookInfo file and put it in the 
			  issuedBooks file with a date( may be).
*/

void Admin::issueBook(void){
	// Take in the book name that user want to get issued
	Book book; 
	string bookName = book.getBookToFind();

	//Task : search for the book
	//Task : Issue it
	//Task : Put the book in the new file and remove the old one
	
}
void Admin::takeBookBack(void){
	cout<<"nothing till noew";
}