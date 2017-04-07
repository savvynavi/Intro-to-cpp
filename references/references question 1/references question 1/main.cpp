#include<iostream>
using namespace std;

//just going over referencing stuff
int main(){
	int num1 = 10;
	cout << "num1: " << num1 << endl;
	int &num2 = num1;
	cout << "num2: " << num2 << endl;
	num1 = 15;
	cout << "num1: " << num1 << ", num2: " << num2 << endl;
	num2 = 20;
	cout << "num1: " << num1 << ", num2: " << num2 << endl;
	int &num3 = num1;
	cout << "num1: " << num1 << ", num2: " << num2 << ", num3: " << num3 << endl;
	num3 = 25;
	cout << "num1: " << num1 << ", num2: " << num2 << ", num3: " << num3 << endl;

	system("pause");
	return 0;
}