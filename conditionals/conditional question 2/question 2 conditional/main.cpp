#include<iostream>
using namespace std;

//displays the larger of the 2 numbers entered
int main(){
	int a, b;
	cout << "Please enter 2 numbers:\n";
	cin >> a >> b;

	if (a >= b){
		cout << a << " is the larger number!\n";
	}
	else{
		cout << b << " is the larger number!\n";
	}

	system("pause");
	return 0;
}