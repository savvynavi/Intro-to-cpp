// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include<algorithm>
#include"Entity.h"
#include "Marine.h"
#include "Zergling.h"
using namespace std;

//setting up new functions to help with efficiency/modularity in case more entity types are added
template<typename T, typename A>
bool alive(vector<T, A> entity);

template<typename T, typename A>
void fillVector(vector<T, A> &group, T &entity, int size);

template<typename T, typename A, typename B, typename C>
void attacking(vector<T, A> &attacker, vector<B, C> &defender);

template<typename T, typename A>
bool removal(Entity &entity, vector<T, A> &defender);

void enemyAttackText(Entity &entity);
void defenderDeathText(Entity &entity);
void winner(vector<Marine> &squad, vector<Zergling> &swarm);

int main(){
	vector<Marine> squad;
	vector<Zergling> swarm;
	Marine m;	
	Zergling z;
	int squadSize = 10;
	int swarmSize = 10;

	// Set up the Squad and the Swarm at their initial sizes listed above
	fillVector(squad, m, squadSize);
	fillVector(swarm, z, swarmSize);
	
	//game loop, will keep going until one group is dead
	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!\n\n";
	while(alive(squad) == true && alive(swarm) == true){
		//marines attack
		attacking(squad, swarm);
		cout << endl;
		//zerg attack
		attacking(swarm, squad);
		cout << endl;
	}
	winner(squad, swarm);
	system("pause");
	return 0;
}

//returns true if there is anything left alive no matter the type
template<typename T, typename A>
bool alive(vector<T, A> entity){
	return (entity.size() > 0);
}

//fills the vector up with objects
template<typename T, typename A>
void fillVector(vector<T, A> &group, T &entity, int size){
	for(int i = 0; i < size; i++){
		group.push_back(entity);
	}
}

//does all the attacking loops for both types, prints specific text depending on type and more can easily be added
template<typename T, typename A, typename B, typename C>
void attacking(vector<T, A> &attacker, vector<B, C> &defender){
	//lets all the attackers swing and subtracts its attack value from the defenders hp
	for(vector<T>::iterator i = attacker.begin(); i != attacker.end(); ++i){
		int damage = (*i).attack();
		defender.begin()->takeDamage(damage);
		enemyAttackText((*i));
		//if the defender dies it is removed from the vector, then if vector is empty it breaks out
		if(removal(defender[0], defender) == true){
			defenderDeathText((*i));
			if(alive(defender) == false){
				break;
			}
		}
	}
}

//if the entity dies, removes it from vector and returns true, otherwise does nothing and returns false
template<typename T, typename A>
bool removal(Entity &entity, vector<T, A> &defender){
	if(entity.isAlive() == false){
		defender.erase(defender.begin());
		return true;
	}
	return false;
}

//lets you print specific text for each entity types attack
void enemyAttackText(Entity &entity){
	if(entity.getName() == "Marine"){
		cout << "A marine fires for " << entity.attack() << " damage." << endl;
	}else if(entity.getName() == "Zergling"){
		cout << "A zergling attacks for " << entity.attack() << endl;
	}
}

//lets you print specific text for entity deaths
void defenderDeathText(Entity &entity){
	if(entity.getName() == "Marine"){
		cout << "The zergling target dies.\n";
	}else if(entity.getName() == "Zergling"){
		cout << "The marine succumbs to his wounds.\n";
	}
}

//prints who the winner is, can be updated easily if more enemy types are added
void winner(vector<Marine> &squad, vector<Zergling> &swarm){
	cout << "The fight is over. ";
	if(alive(squad) == true){
		cout << "The Marines win." << endl;
	}
	else if(alive(swarm) == true){
		cout << "The Zerg win." << endl;
	}
	else if(alive(squad) == false && alive(swarm) == false){
		cout << "Both teams are dead." << endl;
	}
}