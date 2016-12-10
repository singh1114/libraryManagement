#include "header/login.h"
#include "header/admin.h"
#include "header/student.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
	static int x;
	do{
		Login user;
		user.getUsername();
		user.showUserInfo();
		x = user.checkLoginValues();
	}while(x < 0);
	if(x==1){
		Admin user;
		user.showOperations();

		// Now pass operation number to the operate function that map operations and there code
		user.operate();
	}
	else{
		// do the operations for stduents
	}
	return 0;
}
