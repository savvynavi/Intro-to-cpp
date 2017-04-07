#ifndef BIKE_H
#define BIKE_H
#include"vehicle.h"

class Bike:public Vehicle{
public:
	Bike();
	~Bike();
	const int getBasketWeight();
	void setBasketWeight(int weight);
	const void adjustSeat();
	void setWheelNum(int wheelNum);
	void setMotorised(bool motor);
	void setPowered(bool powered);
	const void isMoving();
	void setWindowNum(int winNum);
private:
	int m_weight;
};
#endif