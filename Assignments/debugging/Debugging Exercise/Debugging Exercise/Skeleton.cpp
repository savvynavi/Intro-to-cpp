#include"Skeleton.h"

Skeleton::Skeleton(){
	m_health = 30;
	m_attack = 20;
	m_name = "Skeleton";
}

Skeleton::~Skeleton(){

}

//returns the skeletons attack power
int Skeleton::attack(){
	return m_attack;
}