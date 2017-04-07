#include"zombie.h"
#include<iostream>
#include<vector>
#include<time.h>
#include<cstdlib>
using namespace std;

void zomFight(Zombie &zom1, Zombie &zom2);

//uses the zombie class to create a few zombies, then pits them against eachother until only 1 is alive(hp > 0), prints the winner
int main(){
	srand((unsigned int)time(NULL));

	Zombie bob("bob", "janitor", 75, 90);
	Zombie kate("Kate", "accountant", 110, 25);
	Zombie eileen("Eileen", "Hunter", 100, 75);
	Zombie zomGeneric;
	vector<Zombie> zombies = {bob, kate, eileen, zomGeneric};
	string winner = "no one yet";
	int numOfZom = zombies.size();

	//fight loop, stops when the vector only contains 1 zombie
	while(numOfZom > 1){
		for(int i = 0; i < numOfZom; i++){
			//random number from 0 - size of vector, check in place to make sure zombie doesn't right itself
			int zomb1 = 0;
			int zomb2 = 0;
			while(zomb1 == zomb2){
				zomb1 = rand() % numOfZom;
				zomb2 = rand() % numOfZom;
			}
			zomFight(zombies[zomb1], zombies[zomb2]);
			if(zombies[zomb2].getHealth() == 0){
				zombies.erase(zombies.begin() + zomb2);
				numOfZom--;
			}
		}
	}

	winner = zombies[0].getName();
	cout << "the last one standing is " << winner << "!\n";
	system("pause");
	return 0;
}

//takes in 2 zombie objects, subtracts attack of zom1 from hp of zom2
void zomFight(Zombie& zom1, Zombie &zom2){
	cout << zom1.getName() << " the " << zom1.getJob() << " is attacking " << zom2.getName() << " the " << zom2.getJob() << "!\n";
	zom2.setHealth(zom2.getHealth() - zom1.getAttack());
	int zomhp = zom2.getHealth();
	if(zomhp == 0){
		cout << zom2.getName() << " the " << zom2.getJob() << " is now dead\n\n";
	}else{
		cout << zom2.getName() << " is now at " << zomhp << "hp\n\n";
	}
}