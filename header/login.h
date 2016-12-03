#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <string>
using namespace std;
class Login{
	string username;
	string password;
	public:
		// Enter the username and password of the user.
		void getUsername(void);
		
		// You can check the user info with this function
		void showUserInfo(void);

		// Check for the login values given by the user
		int checkLoginValues(void);

};


#endif