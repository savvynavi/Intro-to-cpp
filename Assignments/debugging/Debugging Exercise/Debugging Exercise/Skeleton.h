#pragma once
#include "Entity.h"

class Skeleton: public Entity{
public:
	Skeleton();
	~Skeleton();

	int attack();
};