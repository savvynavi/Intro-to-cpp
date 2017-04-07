#include<iostream>
using namespace std;

int strLength(char[]);
int strCompare(char[], char[]);
char strCopy(char[],char[]);
char strConcat(char[], char[]);

int main(){
	char array1[] = "hello";
	char array2[] = "hello";
	char array3[] = "different";
	char array4[30];

	strCopy(array4, array1);
	strConcat(array4, " ");
	strConcat(array4, array3);
	strConcat(array4, " ");
	strConcat(array4, array2);
	
	cout << array4 << endl;
	system("pause");
	return 0;
}

//takes in 1 char array, returns the length
int strLength(char array[]){
	int counter = 0;
	while(array[counter] != 0){
		counter++;
	}
	return counter;
}

//takes in 2 char arrays, returns 0 if the same, 1 if array1 is lexographically after array2, and -1 for the opposite
int strCompare(char array1[], char array2[]){
	int index = 0;
	int result = 0;
	bool isRunning = true;

	while(isRunning){
		if(array1[index] == 0 && array2[index] == 0){
			result = 0;
			break;
		}else if(array1[index] > array2[index]){
			result = 1;
			break;
		}else if(array1[index] < array2[index]){
			result = -1;
			break;
		}else{
			++index;
		}
	}
	return result;
}

//takes in 2 char arrays, copies array1 onto array 2, returns array2
char strCopy(char array2[], char array1[]){
	int index = 0;
	while(array1[index] != 0){
		array2[index] = array1[index];
		++index;
	}
	array2[index] = 0;
	return *array2;
}

//takes in 2 char arrays, copies array1 onto the end of array2, MINUS the null terminator(pseudocode forgot to remove that bit, doesn't read if it's there)
char strConcat(char array2[], char array1[]){
	int destinationIndex = strLength(array2) ;
	int sourceIndex = 0;
	while(array1[sourceIndex] !=0){
		array2[destinationIndex] = array1[sourceIndex];
		++destinationIndex;
		++sourceIndex;
	}
	array2[destinationIndex] = 0;
	return *array2;
}