#include"vehicle.h"
#include"bike.h"
#include<iostream>
using namespace std;

//Default Constructor
Bike::Bike(){
	setPowered(true);
	setWheelNum(2);
	setSpeed(0);
	setMotorised(false);
	setSeatNum(1);
	setType("land");
	setBasketWeight(5);
	setSeatNum(1);
	setWindowNum(0);
}

//Destructor
Bike::~Bike(){

}

//gets the current weight in the basket on the front of the bike
const int Bike::getBasketWeight(){
	return m_weight;
}

//sets the weight of the basket as long as it's not negative
void Bike::setBasketWeight(int weight){
	if(weight >= 0){
		m_weight = weight;
	}else{
		m_weight = 0;
	}
}

const void Bike::adjustSeat(){
	cout << "\nYou adjust the seat slightly\n";
}

//overriding the base class setWheelNum() so that it can't change from 2
void Bike::setWheelNum(int wheelNum){
	if(wheelNum != 2){
		cout << "\nBike can't have anything other than 2 wheels\n";
		m_wheelNum = 2;
	}
	else{
		m_wheelNum = wheelNum;
	}
}

//override base class setMotorised() so that the car always returns false
void Bike::setMotorised(bool motor){
	if(motor == true){
		cout << "\nthis isn't a motorbike\n";
		m_motor = false;
	}
	else{
		m_motor = motor;
	}
}

//Bikes can't not be powered, always sets it to true
void Bike::setPowered(bool powered){
	if(powered == false){
		cout << "\nbike can't be unpowered unless you aren't using it\n";
		m_powered = true;
	}else{
		m_powered = powered;
	}
}

//checks to see if the bike is moving
const void Bike::isMoving(){
	if(getSpeed() > 0){
		cout << "\nThe bike is currently moving at " << getSpeed() << "km/h\n";
	}
	else{
		cout << "\nThe vehicle is currently not moving\n";
	}
}

//sets the number of windows, as long as 0
void Bike::setWindowNum(int winNum){
	if(winNum == 0){
		m_winNum = winNum;
	}
	else{
		cout << "\nERROR bikes don't have windows\n";
	}
}
