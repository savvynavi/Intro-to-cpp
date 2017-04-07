#include<iostream>

using namespace std;

void runningSum(int arr[], int size);
void printArr(int arr[], int size);

//uses a hard coded array, then stores a running sum of all previous elements inside the elements
int main(){
	const int size = 4;
	int arrayInput[size] = { 3, 2, 4, 7 };
	printArr(arrayInput, size);
	cout << endl;

	//first run, should output {3, 5, 9, 16}
	runningSum(arrayInput, size);
	printArr(arrayInput, size);
	cout << endl;
	
	//second run, should be {3, 8, 17, 33}
	runningSum(arrayInput, size);
	printArr(arrayInput, size);
	cout << endl;
	
	system("pause");
	return 0;
}

void runningSum(int arr[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			arr[i] += arr[j];
		}
	}
	return;
}

//prints the array out
void printArr(int arr[], int size){
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}