#include"Hunter.h"

Hunter::Hunter(){
	m_hp = 50;
	m_name = "Hunter";
}

Hunter::~Hunter(){

}

int Hunter::attack(){
	return 20;
}

//subs damage from hp, if it is then less than 0 will set hp to 0
void Hunter::takeDamage(int damage){
	m_hp -= damage;
	if(m_hp < 0){
		m_hp = 0;
	}
}