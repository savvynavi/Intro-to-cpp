#include<iostream>

using namespace std;

void MultiplyByIndex(int arr1[], int arr2[], int size);

//takes hard coded array, copies and multiplies to a second array
int main(){
	const int size = 7;
	int integerArray[size] = { 10, 15, 7, 4, 19, 8 };
	int outputArray[size] = {};
	MultiplyByIndex(integerArray, outputArray, size);
	for (int i = 0; i < size - 1; i++) {
		cout << outputArray[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

void MultiplyByIndex(int arr1[], int arr2[], int size){
	for(int i = 0; i < size; i++){
		arr2[i] = arr1[i] * 2;
	}
	return;
}