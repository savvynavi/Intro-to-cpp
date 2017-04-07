#ifndef VEHICLE_H
#define VEHICLE_H
#include<string>

class Vehicle{
public:
	Vehicle();
	~Vehicle();
	const int getWheelNum();
	virtual void setWheelNum(int wheelNum);

	const int getSpeed();
	void setSpeed(int speed);

	const bool getPowered();
	virtual void setPowered(bool powered);

	const bool getMotorised();
	virtual void setMotorised(bool motor);

	const int getSeatNum();
	void setSeatNum(int numSeat);

	const std::string getType();
	void setType(std::string type);

	virtual const void isMoving();
	
	int getWindowNum();
	virtual void setWindowNum(int winNum);
protected:
	int m_wheelNum;
	int m_speed;
	bool m_powered;
	bool m_motor;
	int m_numSeat;
	std::string m_type;
	int m_winNum;
};
#endif