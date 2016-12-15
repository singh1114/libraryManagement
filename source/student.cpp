#include "../header/student.h"

Student::Student(){
	this->booksNotIssued = 4;
}

void Student::getStudentInfo(void){
	cout<<"Enter the name of the student : ";
	/* http://stackoverflow.com/questions/18786575/using-getline-in-c
		We have used cin.ignore to flush the newline character(\n) out of
		the buffer. If not used bookName variable will have null value.
	*/
	cin.ignore();
	getline(cin, Student::name);
	cout<<"Enter the age of the student : ";
	cin>>Student::age;
	cout<<"Enter the student's class : ";
	cin>>Student::studClass;
	cout<<"Enter the roll number of the student : ";
	cin>>Student::rollno;
	cout<<"Enter the phone number of the student : ";
	cin>>Student::phoneNumber;
}

void Student::showStudentInfo(Student student){
	cout<<"name of the student : ";
	cout<<student.name;
	cout<<endl;
	cout<<"age of the student : ";
	cout<<student.age;
	cout<<endl;
	cout<<"class of the student : ";
	cout<<student.studClass;
	cout<<endl;
	cout<<"roll number of the student : ";
	cout<<student.rollno;
	cout<<endl;
	cout<<"phone number of the student : ";
	cout<<student.phoneNumber;
	cout<<endl;
	
}