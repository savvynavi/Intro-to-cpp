#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void ascendSort(vector<int>& userVector, int size);
void descendSort(vector<int>& userVector, int size);

//takes in a list of 5 numbers, will sort in ascending or descending order as long as sum of vector isn't 0
int main() {
	vector<int> userNumbers;
	int number;
	cout << "enter 5 numbers:\n";
	int size = 5;
	int i = 0;
	
	//stores input in a vector, but only 5 numbers (size can be hard changed)
	while (i < size){
		cin >> number;
		userNumbers.push_back(number);
		i++;
	 }
	cout << endl;

	//adds the numbers in the vector together, stores result in vectorAdd
	int vectorAdd = 0;
	for (int j = 0; j < size; j++){
		vectorAdd = vectorAdd + userNumbers[j];
	}
	
	//checks vectorAdd to see if pos for ascending sort, or neg for descending sort, if 0 does nothing
	if (vectorAdd > 0){
		ascendSort(userNumbers, size);
	}else if(vectorAdd < 0){
		descendSort(userNumbers, size);
	}

	for (int i = 0; i < size; i++){
		cout << userNumbers[i] << endl;
	}


	system("pause");
	return 0;
}

void ascendSort(vector<int>& userVector, int size){
	sort(userVector.begin(), userVector.end());
	return;
}

void descendSort(vector<int>& userVector, int size){
	sort(userVector.begin(), userVector.end());
	reverse(userVector.begin(), userVector.end());
	return;
}