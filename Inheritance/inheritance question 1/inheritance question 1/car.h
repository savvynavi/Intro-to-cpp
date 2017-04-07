#ifndef CAR_H
#define CAR_H
#include"vehicle.h"

class Car: public Vehicle{
public:
	Car();
	~Car();
	void setWindowNum(int winNum);
	int getGear();
	void setGear(int gear);
	void setWheelNum(int wheelNum);
	void setMotorised(bool motor);
	const void isMoving();
private:
	int m_gear;
};

#endif