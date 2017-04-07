#pragma once
#include"Entity.h"

class Hunter: public Entity{
public:
	Hunter();
	~Hunter();
	int attack();
	void takeDamage(int damage);
};