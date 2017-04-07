#include"zombie.h"
#include<iostream>
using namespace std;

int main(){
	Zombie bob("bob", "janitor", 50, 10);
	cout << "zombie name is " << bob.getName() << ", old job was " << bob.getJob() << ", and they have an attack power of " << bob.getAttack() << " and hp of " << bob.getHealth() << endl;
	Zombie whoCares;
	cout << "zombie name is " << whoCares.getName() << ", old job was " << whoCares.getJob() << ", and they have an attack power of " << whoCares.getAttack() << " and hp of " << whoCares.getHealth() << endl;
	
	system("pause");
	return 0;
}