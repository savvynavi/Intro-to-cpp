#include"Beast.h"

Beast::Beast(){
	m_hp = 75;
	m_name = "Beast";
}

Beast::~Beast(){

}

int Beast::attack(){
	return 25;
}

//subs damage from hp, if it is then less than 0 will set hp to 0
void Beast::takeDamage(int damage){
	m_hp -= damage;
	if(m_hp < 0){
		m_hp = 0;
	}
}