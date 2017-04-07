#include<iostream>
using namespace std;

struct varHolder{
	int x;
	int y;
};

void numberChange(const varHolder &tersStruct);

//simple pass by reference, using a struct to hold vars ###EDITED FROM Q 3: now can't change vars inside the function as it's passed as a constant, so now it does nothing i guess###
int main(){
	varHolder test;
	test.x = 20;
	test.y = 15;
	cout << "x: " << test.x << ", y: " << test.y << endl;
	numberChange(test);
	cout << "new x: " << test.x << ", new y: " << test.y << endl;
	system("pause");
	return 0;
}

void numberChange(const varHolder &testStruct){
	testStruct.x = testStruct.x + 30;
	testStruct.y = testStruct.y - 6;
}