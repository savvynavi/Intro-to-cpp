#include<iostream>
using namespace std;

//swaps 2 numbers around
int main() {
	int a, b, tmp;
	cout << "Enter 2 numbers: ";
	cin >> a >> b;
	cout << "a: " << a << ", and b: " << b << endl;

	tmp = a;
	a = b;
	b = tmp;
	cout << "a: " << a << ", and b: " << b << endl;

	system("pause");
	return 0;
}