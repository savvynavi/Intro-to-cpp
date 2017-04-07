#include"Entity.h"

Entity::Entity(){

}

Entity::~Entity(){

}

//returns false if dead, true otherwise
bool Entity::isAlive(){
	if(m_hp <= 0){
		return false;
	}
	else{
		return true;
	}
}

std::string Entity::getName(){
	return m_name;
}

int Entity::getHealth(){
	return m_hp;
}