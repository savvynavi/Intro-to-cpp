#include"Entity.h"
#include"Hunter.h"
#include"Beast.h"
#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

template<typename T>
void fillArray(T &entity, T *arr, int size);

template<typename T, typename A>
void attacking(T *attacker, A *defender, int &numAttackers, int &numDefenders);

template<typename T>
T *sortRemove(T *defender, int &numDefenders);

template<typename T>
void print(T &group, int &size);

bool alive(int size);
void enemyAttackText(Entity &entity);
void defenderDeathText(Entity &entity);
void winner(int huntSize, int beastSize);

//creates 2 vectors of either hunters or beasts, then pits them against eachother until 1 group fully dies, prints the winner
int main(){
	srand((unsigned int)time(NULL));
	int numHunters = rand() % 15 + 7;
	int numBeasts = rand() % 10 + 5;
	Hunter hunter;
	Beast beast;
	
	//making arrays of different entities
	Hunter *huntGroup = new Hunter[numHunters];
	fillArray(hunter, huntGroup, numHunters);

	Beast *beastGroup = new Beast[numBeasts];
	fillArray(beast, beastGroup, numBeasts);
	
	while(alive(numBeasts) == true && alive(numHunters) == true){
		//displays current health of each group
		cout << "Hunters: ";
		print(huntGroup, numHunters);
		cout << "Beasts: ";
		print(beastGroup, numBeasts);
		cout << endl;

		//hunters attack
		attacking(huntGroup, beastGroup, numHunters, numBeasts);
		beastGroup = sortRemove(beastGroup, numBeasts);
		cout << endl;

		//beasts attack
		attacking(beastGroup, huntGroup, numBeasts, numHunters);
		huntGroup = sortRemove(huntGroup, numHunters);
		cout << endl;
	}
	winner(numHunters, numBeasts);
	system("pause");
	return 0;
}

//fills the arrays with entities
template<typename T>
void fillArray(T &entity, T *arr, int size){
	for(int i = 0; i < size; i++){
		arr[i] = entity;
	}
}

//takes in 2 arrays, loops through the number of attackers and subtracts attack damage from the defenders 1st element until it's hp is 0, then moves onto next element. Breaks if all defenders are dead
template<typename T, typename A>
void attacking(T *attacker, A *defender, int &numAttackers, int &numDefenders){
	int count = 0;
	for(int i = 0; i < numAttackers; i++){
		int damage = attacker[i].attack();
		defender[count].takeDamage(damage);
		enemyAttackText(attacker[i]);
		if(defender[count].isAlive() == false){
			defenderDeathText(defender[count]);
			count++;
		}
		if(count > numDefenders - 1){
			break;
		}

	}
}

//sorts array using selection sort, delets any entities that have 0hp and resizes array
template<typename T>
T *sortRemove(T *group, int &size){
	//sorting all entities with 0hp to the end of the array
	for(int i = 0; i < size - 1; i++){
		int lowestHp = i;
		for(int j = i + 1; j < size; j++){
			if(group[j].getHealth() > group[lowestHp].getHealth()){
				lowestHp = j;
			}
		}
		if(lowestHp != i){
			T tmp = group[i];
			group[i] = group[lowestHp];
			group[lowestHp] = tmp;
		}
	}
	//Counts the dead things, makes an array of new size, stores all living entities inside it and returns this 
	int count = 0;
	for(int i = size - 1; i >= 0; i--){
		if(group[i].isAlive() == false){
			count++;
		}else{
			break;
		}
	}
	size -= count;
	T* newGroup = new T[size];
	for(int i = 0; i < size; i++){
		newGroup[i] = group[i];
	}
	delete[] group;
	return newGroup;
}

//prints out health of each entity
template<typename T>
void print(T &group, int &size){
	for(int i = 0; i < size; i++){
		cout << group[i].getHealth();
		if(i < size-1){
			cout << ", ";
		}
	}
	cout << endl;
}

//returns true if array still has alive entities inside, false otherwise
bool alive(int size){
	if(size == 0){
		return false;
	}
	return true;
}

//prints out attack text depending on type passed in
void enemyAttackText(Entity &entity){
	if(entity.getName() == "Hunter"){
		cout << "A hunter swings for " << entity.attack() << " damage!\n";
	}else if(entity.getName() == "Beast"){
		cout << "A beast attacks for " << entity.attack() << " damage!\n";
	}
}

//prints out death text for given type
void defenderDeathText(Entity &entity){
	if(entity.getName() == "Hunter"){
		cout << "The hunter falls.\n";
	}else if(entity.getName() == "Beast"){
		cout << "The beast is slain.\n";
	}
}

//prints out who won
void winner(int huntSize, int beastSize){
	cout << "The fight is over. ";
	if(alive(huntSize) == true){
		cout << "The Hunters win." << endl;
	} else if(alive(beastSize) == true){
		cout << "The Beasts win." << endl;
	} else if(alive(huntSize) == false && alive(beastSize) == false){
		cout << "Both sides are dead." << endl;
	}
}