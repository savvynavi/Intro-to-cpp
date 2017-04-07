#include<iostream>
using namespace std;

void numberChange(int &int1, int &int2);

int main(){
	int a = 10;
	int b = 15;
	cout << "a: " << a << ", b: " << b << endl;
	numberChange(a, b);
	cout << "new a: " << a << ", new b: " << b << endl;
	system("pause");
	return 0;
}

void numberChange(int &int1, int &int2){
	int1 = int1 + 20;
	int2 = int2 - 6;
}