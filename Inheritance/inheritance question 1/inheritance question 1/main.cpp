#include"vehicle.h"
#include"car.h"
#include"bike.h"
#include<iostream>
using namespace std;

int main(){
	Car car;
	Vehicle genCar;
	Bike bike;
	bike.setSpeed(20);
	bike.isMoving();
	bike.setSpeed(0);
	bike.isMoving();

	system("pause");
	return 0;
}