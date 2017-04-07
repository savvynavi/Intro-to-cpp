#include "Entity.h"

Entity::Entity(){

}

Entity::~Entity(){

}

//returns false if dead, true if alive
bool Entity::isAlive(){
	if(m_health <= 0){
		return false;
	}else{
		return true;
	}
}

//subtracts damage from hp, if it's less than 0 it sets it to 0
void Entity::takeDamage(int damage){
	m_health -= damage;
	if(m_health < 0){
		m_health = 0;
	}
}

//returns the entity name
std::string Entity::getName(){
	return m_name;
}

//lets you set the attack strength
void Entity::setAttack(int attack){
	m_attack = attack;
}

//lets you set the health as long as it's more than 0
void Entity::setHealth(int health){
	if(health <= 0){
		m_health = 1;
	}else{
		m_health = health;
	}
}