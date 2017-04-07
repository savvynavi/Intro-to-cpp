#include<iostream>;

using namespace std;

int MinInArray(int arr[], int size);

//prints out the smallest number in an array
int main(){
	const int size = 7;
	int integerArray[size] = { 10, 15, 7, 4, 13, 19, 8 };
	int result = MinInArray(integerArray, size);
	cout << "minimum in array is " << result << endl;

	system("pause");
	return 0;
}

int MinInArray(int arr[], int size){
	int min = arr[1];
	for (int i = 0; i < size; i++) {
		if(arr[i] < min){
			min = arr[i];
		}
	}
	return min;
}