#ifndef PLANE_H
#define PLANE_H
#include"vehicle.h"

//add something to see if on ground or not(bool), will affect the isMoving function

class Plane:public Vehicle{
public:
	Plane();
	~Plane();
	//void setWindowNum(int winNum);
	const void isMoving();
private:
};
#endif