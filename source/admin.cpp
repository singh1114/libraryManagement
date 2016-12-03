#include "../header/admin.h"
#include "../header/student.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
// This function is going to show all the operations of the admin on the screen

int Admin::showOperations(void){
	int x;
	cout<<"1. ADD STUDENT";
	cout<<endl;
	cout<<"2. ADD BOOKS";
	cout<<endl;
	cout<<"3. ISSUE BOOKS";
	cout<<endl;
	cout<<"4. TAKE BOOKS BACK";
	cout<<endl;
	cout<<"CHOOSE AN OPERATION FROM THE LIST";
	cout<<endl;
	cin>>x;
	this->operationNumber = x;
	return x;
}

// This function maps the operation choosen by the admin to the code of the operations.
void Admin::operate(int x){
	Admin user;
	if(x == 1){
		user.addStudent();
	}
	else if(x == 2){
		user.addBook();
	}
	else if(x == 3){
		user.issueBook();
	}
	else if(x == 4){
		user.takeBookBack();
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
	fstream file;
	file.open("files/studentInfo.dat", ios::app|ios::out|ios::in|ios::binary);

	do{
		cout<<"Enter the data fo the student\n";

		// Here is the function that get the students data.
		student.getStudentInfo();

		// Write the content to the file in the form of binary or any other form
		file.write(reinterpret_cast<char*>(&student), sizeof(student));

		// Ask the user if you want to enter more values.
		cout<<"Do you want to enter more(y/n)?";
		cin>>x;
	}while(x=='y');
	
	// Now bring the file pointer back to the starting position
	file.seekg(0);

	// Now it is the time to read the file.
	// The following line reads a single object and shifts the file pointer after one object.
	file.read(reinterpret_cast<char*>(&student), sizeof(student));

	// While the end of file is not reached.
	while(!file.eof()){
		cout<<endl;
		cout<<endl;
		// This function shows the data on the terminal
		student.showStudentInfo();

		// This function reads another object
		file.read(reinterpret_cast<char*>(&student), sizeof(student));
		cout<<endl;
		cout<<endl;
	}
	file.close();
}

void Admin::addBook(void){
	cout<<"nothing till noew";
}
void Admin::issueBook(void){
	cout<<"nothing till noew";
}
void Admin::takeBookBack(void){
	cout<<"nothing till noew";
}
