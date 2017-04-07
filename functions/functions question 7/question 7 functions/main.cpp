#include<iostream>

using namespace std;

int SumTo(int N);

//takes int input, sums from 1-input and prints result
int main(){
	int input;
	cout << "enter integer: ";
	cin >> input;
	cout << "\nSum of 1 to " << input << " is " << SumTo(input) << endl;

	system("pause");
	return 0;
}

int SumTo(int N){
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += i;
	}
	return sum;
}