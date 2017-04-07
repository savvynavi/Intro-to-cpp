#include "Marine.h"

Marine::Marine(){
	m_health = 50;
	m_attack = 10;
	m_name = "Marine";
}

Marine::~Marine(){

}

//returns the marines attack power
int Marine::attack(){
	return m_attack;
}