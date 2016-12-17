#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

// This class is specially for the students
class Student{
	public:
	string name;
	int age;
	int studClass;
	double rollno;
	double phoneNumber;
	//number of books that one student can get issued at a time are 4.
	int booksNotIssued;
	//public:
		// constructor that will set booksNotIssued to 4.
		Student();
		void getStudentInfo(void);
		void showStudentInfo(Student student);

};
#endif