#include<iostream>

using namespace std;

int Split(int arr1[], int outputArr1[], int outputArr2[], int size);

//takes an array, copies all positive elements to one array and all negatives to another, prints how many positives were copied
int main(){
	const int size =5;
	int inputArr[size] = { -3, 10, 4, 8, 5 };
	int outputArr1[size] = {};					//zero array so that they aren't half full of random memory
	int outputArr2[size] = {};
	int count = Split(inputArr, outputArr1, outputArr2, size);

	cout << "positive numbers were copied " << count << " times\n";
	system("pause");
	return 0;
}

//edit to make not broken and horrible(technically works fine but arrays are messy)
int Split(int arr1[], int outputArr1[], int outputArr2[], int size){
	int count = 0;
	for (int i = 0; i < size; i++) {
		//currently leaves gaps in array, fix later
		if(arr1[i] > 0){
			outputArr1[i] = arr1[i];
			count++;
		}else{							//needs to be an else if here so 0's don't get put in
			outputArr2[i] = arr1[i];
		}
	}
	return count;
}