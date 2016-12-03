#include "../header/student.h"

Student::Student(){
	this->booksNotIssued = 4;
}

void Student::getStudentInfo(void){
	cout<<"Enter the name of the student : ";
	cin>>Student::name;
	cout<<"Enter the age of the student : ";
	cin>>Student::age;
	cout<<"Enter the student's class : ";
	cin>>Student::studClass;
	cout<<"Enter the roll number of the student : ";
	cin>>Student::rollno;
	cout<<"Enter the phone number of the student : ";
	cin>>Student::phoneNumber;
}

void Student::showStudentInfo(void){
	cout<<"name of the student : ";
	cout<<this->name;
	cout<<endl;
	cout<<"age of the student : ";
	cout<<this->age;
	cout<<endl;
	cout<<"class of the student : ";
	cout<<this->studClass;
	cout<<endl;
	cout<<"roll number of the student : ";
	cout<<this->rollno;
	cout<<endl;
	cout<<"phone number of the student : ";
	cout<<this->phoneNumber;
	cout<<endl;
	
}