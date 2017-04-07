#pragma once
#include<string>

class Entity{
public:
	Entity();
	~Entity();
	virtual int attack() = 0;
	virtual void takeDamage(int damage) = 0;
	bool isAlive();
	std::string getName();
	int getHealth();
protected:
	int m_att;
	int m_hp;
	std::string m_name;
};