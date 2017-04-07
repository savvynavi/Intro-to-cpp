#include<iostream>

using namespace std;

bool usrDetector(char *name);

//takes in user unput for a username/password, checks if usrname meets standards and if the password is correct
int main(){
	bool userInput = true;
	const int length = 30;
	char username[length];
	cout << "Enter username, must contain 'usr' somewhere within it: ";

	//user enters a username, calls function to detect if 'usr' is in it anywhere
	while(userInput == true){
		userInput = false;
		cin.getline(username, length);
		if(usrDetector(username)){
		}else{
			cout << "\nusername bad, try again: ";
			userInput = true;
		}
	}
	cout << endl;
	
	bool passInput = true;
	char password[length];
	char realPassword[] = "Pa55w0rd";
	char output[40];
	cout << "Enter a password: ";

	//checks if password matches the true password, if so stores concatenated user/pass together with a - in char array output
	while(passInput){
		passInput = false;
		cin.getline(password, length);
		if (strcmp(password, realPassword) == 0) {
			cout << "\npassword correct!";
			strcpy(output, username);
			strcat(output, "-");
			strcat(output, password);
		}
		else {
			cout << "\nIncorrect password, try again";
			passInput = true;
			}
		cout << endl;
	}

	cout << output << endl;
	system("pause");
	return 0;
}

bool usrDetector(char *name){
	for(int i = 0; i < strlen(name) - 2; i++){
		if(name[i] == 'u' && name[i + 1] == 's' && name[i + 2] == 'r'){
			return true;
		}
	}
	return false;
}