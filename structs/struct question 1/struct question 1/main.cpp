#include<iostream>
#include<string>
using namespace std;

//making basic player struct
struct Player{
	string name;
	int health;
	int score;
	float x;
	float y;
	float velocity;
};

struct Rectangle{
	float leftX;
	float rightX;
	float upperY;
	float lowerY;
	int colour;

};

//creates a player, sets all variables, prints it, same with rectangle
int main(){
	Player you;
	string yourName = you.name = "Dave";
	you.health = 50;
	you.score = 1500;
	you.x = 5.4f;
	you.y = 3.2f;
	you.velocity = 60;
	cout << "your name is " << you.name << ", your hp is " << you.health << ", and your position is (" << you.x << ", " << you.y << "), with a velocity of " << you.velocity << endl;

	Rectangle shape;
	shape.leftX = 15;
	shape.rightX = 30;
	shape.upperY = 45;
	shape.lowerY = 10;
	shape.colour = 90;
	cout << "upper right is at (" << shape.rightX << ", " << shape.upperY << "), upper left is (" << shape.leftX << ", " << shape.upperY << "), ect\n";
	system("pause");
	return 0;
}