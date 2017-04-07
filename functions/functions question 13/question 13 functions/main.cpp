#include<iostream>

using namespace std;

int arrSearch(int arr[], int size, int num);

//searches an array fo a given number, either prints the element number, or number not found
int main(){
	const int size = 5;
	int inputArray[size] = {10, 18, 22, 5, 7};
	int searchNum = 555;

	int result = arrSearch(inputArray, size, searchNum);
	if(result == -1){
		cout << "Number not found\n";
	}else{
		cout << "The number " << searchNum << " is in element " << result << endl;
	}

	system("pause");
	return 0;
}

int arrSearch(int arr[], int size, int num) {
	for (int i = 0; i < size; i++) {
		if(arr[i] == num){
			cout << "found!\n";
			return i;
		}
	}
	return -1;
}