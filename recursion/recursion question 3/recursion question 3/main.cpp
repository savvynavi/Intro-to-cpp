#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int hanoi(int numDisc);

//calculates towers of hanoi without all the vector bullshit i had earlier like god damn
int main(){
	int discNum = 4;
	cout << hanoi(discNum) << endl;
	system("pause");
	return 0;
}

int hanoi(int numDisc){
	if (numDisc == 1) {
		return 1;
	}
	return hanoi(numDisc - 1) * 2 + 1;
}