// All the operations are allowed if the user login as an admin
#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;
class Admin{
	int operationNumber;
	public:
		// This function asks for the admin to choose a operation
		int showOperations(void);
		void operate(int x);
		void addStudent(void);
		void addBook(void);
		void issueBook(void);
		void takeBookBack(void);
};
#endif