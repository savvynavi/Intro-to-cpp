#include<iostream>
using namespace std;

//takes in a username and password, checks to see if password is long enough/has 1 special character/capital letter/number
int main() {
	const int length = 30;
	cout << "Enter your username: ";
	char username[length];
	cin.getline(username, length);
	cout << endl;

	//password flags
	bool capital = false;
	bool number = false;
	bool special = false;
	bool eightLong = false;
	bool passwordInput = true;

	char password[length];
	cout << "Enter password (needs at least 8 letters, containing 1 capital, 1 number and 1 symbol at least: )";
	while(passwordInput){
		passwordInput = false;
		cin.getline(password, length);
		//checks if 8 characters long
		if (strlen(password) >= 8) {
			eightLong = true;
		}else{
			cout << "\nNot long enough\n";
			passwordInput = true;
		}
		
		//checks if the pasword contains at least 1 capital, 1 special character and 1 number (in that order)
		for (int i = 0; i < strlen(password); i++) {
			if (password[i] >= 65 && password[i] <= 90 ) {
				capital = true;
			}else if((password[i] >= 32 && password[i] <= 38) || password[i] == 63 || password[i] == 64){
				special = true;
			}else if(password[i] >= '0' && password[i] <= '9'){
				number = true;
			}
		}

		//will keep looping if all flags aren't set to true
		if (capital && number && special && eightLong) {
			cout << "\nGood password\n";
		}else{
			cout << "\nBad password try again\n";
			passwordInput = true;
		}
	}

	system("pause");
	return 0;
}