#include"vehicle.h"
#include<iostream>
using namespace std;

//Constructor
Vehicle::Vehicle(){
	setPowered(false);
	setWheelNum(1);
	setSpeed(0);
	setSeatNum(4);
	setMotorised(true);
	setType("air");
}

//Destructor
Vehicle::~Vehicle(){

}

//returns the number of wheels a vehicle has
const int Vehicle::getWheelNum(){
	return m_wheelNum;
}

//sets the wheel number as long as it's not 0 or less
void Vehicle::setWheelNum(int wheelNum){
	if(wheelNum >= 0){
		m_wheelNum = wheelNum;
	}
}

//returns the current speed of the vehicle
const int Vehicle::getSpeed(){
	return m_speed;
}

//sets the speed of the vehicle, as long as it's not negative
void Vehicle::setSpeed(int speed){
	if(speed >= 0){
		m_speed = speed;
	}
}

//returns true if the vehicle is currently on/running, false if it's off
const bool Vehicle::getPowered(){
	return m_powered;
}

//sets the powered state of the vehicle, true if running false if not
void Vehicle::setPowered(bool powered){
	m_powered = powered;
}

//returns true if the vehicle has a motor, false otherwise
const bool Vehicle::getMotorised(){
	return m_motor;
}

//sets if the vehicle has a motor or not, true if it does, false if it doesn't
void Vehicle::setMotorised(bool motor){
	m_motor = motor;
}

//returns how many seats the vehicle has
const int Vehicle::getSeatNum(){
	return m_numSeat;
}

//sets the seat num, as long as it is 1 or more
void Vehicle::setSeatNum(int numSeat){
	if(numSeat > 0){
		m_numSeat = numSeat;
	}
}

//returns what kind of terrain the vehicle travels over, "land", "water", or "air"
const string Vehicle::getType(){
	return m_type;
}

//sets the type to either  "land", "water", or "air", errors out if it's otherwise set
void Vehicle::setType(string type){
	if(type == "air" || type == "land" || type == "water"){
		m_type = type;
	}else{
		cout << "\nERROR not a legal type\n";
	}
}

//checks to see if the vehicle is moving
const void Vehicle::isMoving(){
	if(getSpeed() > 0 && getPowered() == true){
		cout << "\nThe vehicle is currently moving at " << getSpeed() << "km/h\n";
	}else{
		cout << "\nThe vehicle is currently not moving\n";
	}
}

//returns the number of windows the car has
int Vehicle::getWindowNum(){
	return m_winNum;
}

//sets the number of windows
void Vehicle::setWindowNum(int winNum){
	m_winNum = winNum;
}
