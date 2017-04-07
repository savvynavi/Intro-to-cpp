#include<iostream>

using namespace std;

//takes in a users name, stores it in a dynamic array of their size
int main(){
	int length;
	cout << "enter name length: ";
	cin >> length;
	//plus 2 as the space takes 1 space in array, and the null character uses another
	char *name = new char[length + 2];
	cin.clear();
	cin.ignore();

	
	cout << "Enter your name: ";
	cin.getline(name, length + 2);
	cout << endl << name << endl;

	delete name;
	system("pause");
	return 0;
}