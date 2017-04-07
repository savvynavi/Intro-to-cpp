#include<iostream>

using namespace std;

//takes in 5 names, stores it in a 2D dynamic array of their size, prints it out in reverse order
int main() {
	const int numOfNames = 5;
	const int length = 20;
	char names[numOfNames][length];
	
	//populates array with names 
	for (int i = 0; i < numOfNames; i++) {
		cout << "enter name number " << i + 1 << ": ";
		cin.getline(names[i], length);
	}
	
	//reverses both array order and character order
	for (int i = numOfNames - 1; i >= 0; i--) {
		for (int k = strlen(names[i]) - 1; k >= 0; k--) {
			cout << names[i][k];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}