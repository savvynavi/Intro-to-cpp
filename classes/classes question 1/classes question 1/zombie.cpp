#include"zombie.h"
using namespace std;

//Default constructor
Zombie::Zombie(){
	setName("perfectly generic name");
	setJob("business");
	setHealth(5);
	setAttack(5);	
}

//Custom constructor, lets you set name, job, hp and attack yourself from initialisation
Zombie::Zombie(string name, string job, int hp, int att){
	setName(name);
	setJob(job);
	setHealth(hp);
	setAttack(att);
}

//Destructor
Zombie::~Zombie(){

}

//Lets you set the name of a zombie
void Zombie::setName(string name){
	m_name = name;
}

//Returns zombie name
string Zombie::getName(){
	return m_name;
}

//Sets the health 
void Zombie::setHealth(int hp){
	m_hp = hp;
}

//Gets the health
int Zombie::getHealth(){
	return m_hp;
}

//sets attack power
void Zombie::setAttack(int att){
	m_attack = att;
}

//returns the attack power
int Zombie::getAttack(){
	return m_attack;
}

//sets the job
void Zombie::setJob(string job){
	m_job = job;
}

//gets the job
string Zombie::getJob(){
	return m_job;
}