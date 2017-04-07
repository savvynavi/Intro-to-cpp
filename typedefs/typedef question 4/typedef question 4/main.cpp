#include<iostream>

using namespace std;

//takes input, converts it to litres, main thing here is storing the conversion as a constS
int main(){
	cout << "Enter number of gallons: ";
	int input;
	cin >> input;

	const float conversion = 3.78533f;
	float result = input*conversion;
	cout << "\nThat is " << result << " litres\n";

	system("pause");
	return 0;
}