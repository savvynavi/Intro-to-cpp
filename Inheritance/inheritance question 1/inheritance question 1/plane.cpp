#include"vehicle.h"
#include"plane.h"
#include<iostream>
using namespace std;

Plane::Plane(){
	setType("air");
	setWheelNum(3);
	setSpeed(0);
	setMotorised(true);
	setWindowNum(20);
	setSeatNum(40);
	setMotorised(true);
	setPowered(false);
}

Plane::~Plane(){

}

//checks to see if the plane is moving
const void Vehicle::isMoving(){
	if(getSpeed() > 0 && getPowered() == true){
		cout << "\nThe plane is currently moving at " << getSpeed() << "km/h through the air\n";
	}
	else{
		cout << "\nThe vehicle is currently not moving\n";
	}
}