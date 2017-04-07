#pragma once
#include"Entity.h"

class Beast: public Entity{
public:
	Beast();
	~Beast();
	int attack();
	void takeDamage(int damage);
};