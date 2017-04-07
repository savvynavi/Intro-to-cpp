#include<iostream>
using namespace std;

//create dynamic 2d array, print it, delete it
int main(){
	int width = 5;
	int height = 5;

	//creating the array, inner ones need to be made in a loop
	int **arr1 = new int *[height];
	for(int i = 0; i < height; i++){
		*(arr1 + i) = new int[width];
	}

	//filling the array with junk (array[i][k] the same as *(*(array + i) + k))
	for(int i = 0; i < height; i++){
		for(int k = 0; k < width; k++){
			*(*(arr1 + i) + k)  = i + k + 6;
		}
	}

	for(int i = 0; i < height; i++){
		for(int k = 0; k < width; k++){
			cout << *(*(arr1 + i) + k) << " ";
		}
		cout << endl;
	}

	//deleting the sub arrays first, then the main outer one
	for(int i = 0; i < height; i++){
		delete[]*(arr1 + i);
	}

	delete[] arr1;
	system("pause");
	return 0;
}