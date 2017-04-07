#include<iostream>

using namespace std;

//takes in a users name, stores it in a dynamic array of their size, prints it out in reverse order
int main() {
	int length;
	cout << "enter name length: ";
	cin >> length;
	//plus 2 as the space takes 1 space in array, and the null character uses another
	char *name = new char[length + 2];
	cin.clear();
	cin.ignore();
	cout << "Enter your name: ";
	cin.getline(name, length + 2);
	
	//the reverse bit, probably a built in function but can't find it
	for (int i = strlen(name) - 1; i >= 0; i--) {
		cout << name[i];
	}

	cout << endl;

	delete name;
	system("pause");
	return 0;
}