#include<iostream>

using namespace std;

void lookAndSay(int arr[], int size);

//takes in an array and then prints out how many times each number appeares in a row
int main() {
	const int size = 19;
	int arr[size] = { 1,2,2,1,5,1,1,7,7,7,7,1,1,1,1,1,1,1,1 };
	lookAndSay(arr, size);

	system("pause");
	return 0;
}

void lookAndSay(int arr[], int size){
	int currentNum = arr[0];
	int count = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] == currentNum){
			count++;
		}else{
			cout << count << ", " << currentNum << endl;
			currentNum = arr[i];
			count = 0 + 1;
		}
	}
	cout << count << ", " << currentNum << endl;
}