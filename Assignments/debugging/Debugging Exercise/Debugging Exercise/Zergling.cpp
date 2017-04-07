#include "Zergling.h"

Zergling::Zergling(){
	m_health = 25;
	m_attack = 15;
	m_name = "Zergling";
}

Zergling::~Zergling(){

}

//returns the zergs attack power
int Zergling::attack(){
	return m_attack;
}