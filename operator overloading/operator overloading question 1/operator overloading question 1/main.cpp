#include"position.h"
#include<iostream>
using namespace std;

//overloading operators
int main(){
	Position p1;
	cout << "p1 x = " << p1.getX() << ", y = " << p1.getY() << endl;
	p1++;
	cout << "p1 x = " << p1.getX() << ", y = " << p1.getY() << endl;
	++p1;
	cout << "p1 x = " << p1.getX() << ", y = " << p1.getY() << endl;
	p1--;
	cout << "p1 x = " << p1.getX() << ", y = " << p1.getY() << endl;
	
	p1--;
	cout << "p1 x = " << p1.getX() << ", y = " << p1.getY() << endl;
	system("pause");
	return 0;
}