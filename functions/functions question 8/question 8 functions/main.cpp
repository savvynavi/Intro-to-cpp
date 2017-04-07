#include<iostream>

using namespace std;

int SumArray(int arr[], int size);

//takes hard coded array, sums the elements
int main(){
	const int size = 5;
	int integerArray[size] = { 7, 3, 2, 4, 9 };
	int result = SumArray(integerArray, size);
	cout << "sum of array is " << result << endl;
	system("pause");
	return 0;
}

int SumArray(int arr[], int size){
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}