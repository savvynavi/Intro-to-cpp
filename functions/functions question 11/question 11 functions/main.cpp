#include<iostream>

using namespace std;

void arraySum(int arr1[], int arr2[], int sumArr[], int size);

//uses 2 hard coded arrays and stores the sum of each element inside a 3rd array
int main(){
	const int size = 5;
	int array1[size] = {5, 8, 1, 10, 18};
	int array2[size] = { 20, 6, 7, 2, 15 };
	int sumArray[size];								//should end up as {25, 14, 8, 12, 33}
	
	arraySum(array1, array2, sumArray, size);
	for (int i = 0; i < size; i++) {
		cout << sumArray[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

void arraySum(int arr1[], int arr2[], int sumArr[], int size){
	for (int i = 0; i < size; i++) {
		sumArr[i] = arr1[i] + arr2[i];
	}
	return;
}