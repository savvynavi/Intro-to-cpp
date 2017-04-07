#include<iostream>
using namespace std;

int main(){
	int *ptrA, ptrB, *ptrC;

	ptrA = new int;
	*ptrA = 3;
	ptrB = ptrA;
	cout << "*ptrA: " << *ptrA << ", *ptrB: " << *ptrB << endl;

	ptrB = new int;
	*ptrB = 9;
	cout << "*ptrA: " << *ptrA << ", *ptrB: " << *ptrB << endl;

	*ptrB = *ptrA;
	cout << "*ptrA: " << *ptrA << ", *ptrB: " << *ptrB << endl;

	delete ptrA;
	ptrA = ptrB;
	cout << "*ptrA: " << *ptrA << ", *ptrB: " << *&*&*&*&ptrB << endl;

	ptrC = &ptrA;
	cout << "*ptrC: " << *ptrC << ", **ptrC: " << **ptrC;

	system("pause");
	return 0;
}