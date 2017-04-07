#include<iostream>
#include<vector>
#include<time.h>
#include<cstdlib>
#include <algorithm>
#include<functional>
using namespace std;

void print(vector<int> &random);
bool isLarger(int x, int y);
void equals(int i);

int main(){
	srand((unsigned int)time(NULL));
	vector<int> randomNumbers;
	vector<int>::iterator it;

	for(int i = 0; i <= 20; i++){
		randomNumbers.push_back(rand());
	}

	sort(randomNumbers.begin(), randomNumbers.end());

	cout << "Sorted values:\n";
	print(randomNumbers);

	//for(int i = 0; i < randomNumbers.size(); i++){
	//	if(i % 2 == 0){
	//		randomNumbers[i] = 0;
	//	}
	//}

	/*cout << "\nSorted values where every 2nd number is 0:\n";
	for(int i = 0; i < randomNumbers.size(); i++){
		cout << randomNumbers[i] << endl;
	}*/

	cout << "Reverse order sort:\n";
	sort(randomNumbers.begin(), randomNumbers.end(), isLarger);
	for(it = randomNumbers.begin(); it != randomNumbers.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//adding 0 to every 2nd element using the for_each() function
	for_each(randomNumbers.begin(), randomNumbers.end(), equals);
	//cout << "\n\n";
	//print(randomNumbers);
	system("pause");
	return 0;
}

//prints vector
void print(vector<int> &random){
	for(int i = 0; i < random.size(); i++){
		cout << random[i] << endl;
	}
}

//returns if number is larger ot not
bool isLarger(int x, int y){
	return (x > y);
}

//doesn't work as intended :/
void equals(int i){
	if(i % 2 == 0){
		cout << 0 << " ";
	}else{
		cout << i << " ";
	}
	cout << endl;
}