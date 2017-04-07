#pragma once
#include<string>

class Entity{
public:
	Entity();
	~Entity();

	//keeping attack pure virtual in case you wanted all derived classes able to have different attack patterns
	virtual int attack() = 0;
	virtual void takeDamage(int damage);
	bool isAlive();
	std::string getName();
	void setAttack(int attack);
	void setHealth(int health);
protected:
	int m_health;
	int m_attack;
	std::string m_name;
};