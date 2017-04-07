#include<iostream>
using namespace std;

//takes user input for 5 numbers, outputs average
int main() {
	int a, b, c, d, e;
	cout << "enter 5 numbers: ";
	cin >> a >> b >> c >> d >> e;
	cout << "a: " << a << "\nb: " << b << "\nc: " << c << "\nd: " << d << "\ne: " << e << endl;

	float avg = (a + b + c + d + e) / 5.0f;
	cout << "the average of these numbers is " << avg << endl;
	system("pause");
	return 0;
}