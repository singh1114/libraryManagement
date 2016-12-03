#include "../header/admin.h"
#include <iostream>
#include <stdlib.h>
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
	cout<<"nothing till noew";
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
