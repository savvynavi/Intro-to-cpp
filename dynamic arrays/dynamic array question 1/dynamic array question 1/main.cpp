#include<iostream>
using namespace std;

void revString(int *arr1, const int size);

//lets user input a size and list uf integers, then stores them in reverse order, prints result
int main(){
	int input;
	cout << "Enter how many numbers you are entering: ";
	bool numberInput = true;
	while(numberInput == true){
		numberInput = false;
		cin >> input;
		if(input <= 0){
			cout << "\nnot large enough, needs to be positive non-zero:";
			numberInput = true;
		}
	}
	cin.clear();
	cin.ignore();
	int size = input;
	int *numArr = new int[size];
	
	for(int i = 0; i < size; i++){
		cout << "\nplease enter integer number " << i + 1 << ": ";
		cin >> *(numArr + i);
	}

	revString(numArr, size);
	for(int i = 0; i < size; i++){
		cout << *(numArr + i) << " ";
	}

	cout << endl;
	delete[] numArr;
	system("pause");
	return 0;
}

//takes in a int array and size, reverses the array
void revString(int *arr1, const int size){
	int tmp;
	for(int i = 0; i < (size / 2); i++){
		tmp = *(arr1 + i);
		*(arr1 + i) = *(arr1 + size - 1 - i);
		*(arr1 + size - 1 - i) = tmp;
	}
}