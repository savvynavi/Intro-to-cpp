#include<iostream>

using namespace std;

int main(){
	const int length = 20;
	char user[length];
	
	cout << "Enter a word: ";
	cin.getline(user, length);
	//char *pigWord = new char[strlen(user) + 2];
	char pigWord[length];
	//loops through last 2 letters of user, copies to start of pigWord
	for (int i = strlen(user) - 1; i < strlen(user); i++) {
		//cout << user[i];
		pigWord[i - strlen(user) - 1] = user[i];
	}

	for (int i = 0; i < strlen(user); i++) {
		pigWord[i + 2] = user[i];
	}
	
	cout << endl;

	//delete pigWord;
	system("pause");
	return 0;
}