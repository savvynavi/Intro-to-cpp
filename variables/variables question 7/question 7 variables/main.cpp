#include<iostream>
using namespace std;

//takes in 2 characters, outputs the letter in the middle of them despite capitalisation
int main() {
	char firstLetter;
	char secondLetter;
	cout << "enter 2 letters:\n";
	cin >> firstLetter >> secondLetter;
	cout << "first letter: " << firstLetter << ", second letter: " << secondLetter << endl;


	if (firstLetter >= 97) {
		firstLetter = firstLetter - 32;
	}
	if (secondLetter >= 97) {
		secondLetter = secondLetter - 32;
	}

	char averageLetter = (firstLetter + secondLetter) / 2;
	cout << "letter halfway between these is: " << averageLetter << endl;
	system("pause");
	return 0;
}