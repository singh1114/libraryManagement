#include "../header/login.h"

// This function takes and store the values for a object
void Login::getUsername(void){
	cout<<"Enter the username : ";
	string username;
	cin>>username;
	Login::username = username;
	cout<<"Enter the password : ";
	string password;
	cin>>password;
	Login::password = password;
}
void Login::showUserInfo(void){
	cout<<"The username of the user is:";
	cout<<this->username;
	cout<<endl;
	cout<<endl;
	cout<<"The password of the user is:";
	cout<<this->password;
	cout<<endl;
	cout<<endl;

}
int Login::checkLoginValues(void){
	if(this->username == "ranvir" && this->password == "ranvir"){
		cout<<"WELCOME AS ADMIN";
		cout<<endl;
		// if admin then return 1.
		return 1;
	}
	else if(this->username == "student" && this->password == "student"){
		cout<<"WELCOME AD STUDENT";
		cout<<endl;
		// if student then return 1.
		return 2;
	}
	else{
		cout<<"YOU NEED TO LOGIN AGAIN";
		cout<<endl;

		//unsuccessful Login returns -1.
		return -1;
	}
	return 1;
}
