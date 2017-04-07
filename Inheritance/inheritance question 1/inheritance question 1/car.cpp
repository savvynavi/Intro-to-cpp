#include"vehicle.h"
#include"car.h"
#include<iostream>
using namespace std;

//Default Constructor
Car::Car(){
	setType("land");
	setWheelNum(4);
	setSpeed(0);
	setMotorised(true);
	setWindowNum(6);
	setGear(1);
	setSeatNum(5);
}

//Destructor
Car::~Car(){

}

//sets the number of windows, as long as it's between 4-6
void Car::setWindowNum(int winNum){
	if(winNum >= 4 && winNum <= 6){
		m_winNum = winNum;
	}else{
		cout << "\nERROR can't have that number of windows in a car, minimum is 4 and max is 6\n";
	}
}

//returns what gear the car is in
int Car::getGear(){
	return m_gear;
}

//sets the gear for the car, as long as it's between 1-6
void Car::setGear(int gear){
	if(gear < 0){
		cout << "\nERROR car can't have negative gear\n";
	}else if(gear >= 7){
		cout << "\nERROR can't have a gear that's not between 1-6\n";
	}else{
		m_gear = gear;
	}
}

//overriding the base class setWheelNum() so that it can't change from 4
void Car::setWheelNum(int wheelNum){
	if(wheelNum != 4){
		cout << "\nCar can't have anything other than 4 wheels, if it did it would be broken or not a car\n";
		m_wheelNum = 4;
	}else{
		m_wheelNum = wheelNum;
	}
}

//override base class setMotorised() so that the car always returns true
void Car::setMotorised(bool motor){
	if(motor == false){
		cout << "\nA car needs a motor\n";
		m_motor = true;
	}else{
		m_motor = motor;
	}
}

//checks to see if the car is moving
const void Car::isMoving(){
	if(getSpeed() > 0 && getPowered() == true){
		cout << "\nThe car is currently moving at " << getSpeed() << "km/h\n";
	}
	else{
		cout << "\nThe vehicle is currently not moving\n";
	}
}