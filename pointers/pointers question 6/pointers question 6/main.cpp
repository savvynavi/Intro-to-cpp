#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void revString(char *arr1);
int countEven(int *arr1, int size);
double *maximum(double *arr1, int size);
bool contains(char *arr1, char searchValue);

int main(){
	//part a - reverse
	char strArr[] = "Rose Lalonde";
	revString(strArr);
	for(int i = 0; i < strlen(strArr); i++){
		cout << *(strArr + i);
	}
	cout << endl;

	//part b - count even
	const int size = 9;
	int intArr[size] = {1, 2, 10, 4, 5, 6, 1, 8, 9};
	cout << "number of even numbers: " << countEven(intArr, size) << endl;
	cout << endl;

	//part c - maximum value
	const int constSize = 6;
	double maxArr[constSize] = {4, 50, 60, 700, 90, 1500};		//maximum is 90 at element 4
	cout << "maximum value of the array is: " << *maximum(maxArr, constSize) << endl;
	
	
	//part d - search for a letter
	char charArr[] = {"aeiofftfffq"};	//search for t(true) and w(fasle);
	char searchLetter1 = 't';
	char searchLetter2 = 'w';
	if(contains(charArr, searchLetter1) == true){
		cout << "the array contains the letter " << searchLetter1 << endl;
	}else{
		cout << "the array doesn't contain the search letter " << searchLetter1 << endl;
	}
	
	system("pause");
	return 0;
}

//reverses the string passed into it
void revString(char *arr1){
	int tmp;
	int size = strlen(arr1);
	for(int i = 0; i < (size / 2); i++){
		tmp = *(arr1 + i);
		*(arr1 + i) = *(arr1 + size - 1 - i);
		*(arr1 + size - 1 - i) = tmp;
	}
}

//takes in array + size, counts the even numbers inside
int countEven(int *arr1, int size){
	int count = 0;
	for(int i = 0; i < size; i++){
		if(*(arr1) % 2 == 0){
			count++;
		}
		*arr1++;
	}
	return count;
}

//takes in a size and array, spits out the element the largest number is at, if empty returns null(god this one is some ham)
double *maximum(double *arr1, int size){
	double *maxPtr = nullptr;
	if(arr1 == nullptr){
		return maxPtr;
	}
	for(int i = 0; i < size; i++){
		if(maxPtr == nullptr || *(arr1 + i) > *maxPtr){
			maxPtr = (arr1 + i);
		}
	}
	return maxPtr;
}

//takes in array and letter to search for, returns true if the array contains it
bool contains(char *arr1, char searchValue){
	bool isFound = false;
	for(int i = 0; i < strlen(arr1) - 1; i++){
		if(*(arr1 + i) == searchValue){
			return true;
		}
	}
	return false;
}