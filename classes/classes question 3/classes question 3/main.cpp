#include"item.h"
#include"inventory.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
	Item test;
	Item cake("cake", 2);
	Item book("book", 4, 1);
	Item paper("paper", 1, 1);
	Item ball("ball", 5);
	Inventory invent;

	system("pause");
	return 0;
}