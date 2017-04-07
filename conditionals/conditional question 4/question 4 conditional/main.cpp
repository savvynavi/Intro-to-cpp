#include<iostream>

using namespace std;

//using a switch statement to check what entered
int main(){
	int choice = 0;
	cout << "enter a number between 1-4: ";
	cin >> choice;
	switch (choice){
	case 1:
		cout << "\n1\n";
		break;
	case 2:
	case 3:
		cout << "\n2 or 3\n";
		break;
	case 4:
		cout << "\n4\n";
	default:
		cout << "\nInvalid\n";
	}

	system("pause");
	return 0;
}