#include<iostream>

using namespace std;

int Power(int x, int y);

//takes 2 ints, and takes the first one to the power of the second one
int main(){
	int x = 4;
	int y = 3;
	cout << x << " to the power of " << y << " is " << Power(x, y) << endl;

	system("pause");
	return 0;
}

int Power(int x, int y)
{
	int result = 1;
	for (int i = 0; i < y; i++) {
		result *= x;
	}
	return result;
}