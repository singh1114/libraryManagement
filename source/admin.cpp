#include "../header/admin.h"
#include "../header/student.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
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
		file.seekg(file.eof());
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
		//file.seekg(0);

		// Now it is the time to read the file.
		// The following line reads a single object and shifts the file pointer after one object.
		file.read(reinterpret_cast<char*>(&student), sizeof(student));
		// While the end of file is not reached.
		while(!file.eof()){
			cout<<endl;
			cout<<endl;
			// This function shows the data on the terminal
			student.showStudentInfo(student);
			// This function reads another object
			//file.read(reinterpret_cast<char*>(&student), sizeof(student));
			cout<<endl;
			cout<<endl;
		}
		file.close();
	}
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
