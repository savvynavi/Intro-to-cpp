#include<iostream>

using namespace std;

int fibonacci(int n);

//prints the fibonacci sequence out in order up to the number specified
int main(){
	int num = 10;
	for (int i = 0; i < num; i++) {
		cout << fibonacci(i) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

int fibonacci(int n){
	if(n < 2){
		return 1;
	}
	for (int i = 1; i < n; i++) {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}