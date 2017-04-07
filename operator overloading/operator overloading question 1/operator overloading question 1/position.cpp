#include"position.h"

Position::Position(){
	m_x = 5.0f;
	m_y = 5.0f;
}

Position::Position(float x, float y){
	m_x = x;
	m_y = y;
}

Position::~Position(){

}

float Position::getX(){
	return m_x;
}

float Position::getY(){
	return m_y;
}

void Position::setX(float x){
	m_x = x;
}

void Position::setY(float y){
	m_y = y;
}

//overloading the '+' operator
Position Position::operator+(Position &other){
	Position tmp;
	tmp.setX(this -> getX() + other.getX());
	tmp.setY(this -> getY() + other.getY());
	return tmp;
}

//overloading the '-' operator
Position Position::operator-(Position &other){
	Position tmp;
	tmp.setX(this->getX() - other.getX());
	tmp.setY(this->getY() - other.getY());
	return tmp;
}

//overloading the += operator
Position Position::operator+=(Position &other){
	this->setX(this -> getX() + other.getX());
	this->setY(this->getY() + other.getY());
	return *this;
}

//overloading -+ operator
Position Position::operator-=(Position &other){
	this -> setX(this -> getX() - other.getX());
	this -> setY(this -> getY() - other.getY());
	return *this;
}

//overloading == operator
bool Position::operator==(Position &other){
	return ((this -> getX() == other.getX()) && (this -> getY() == other.getY()));
}

//overload the / operator
Position Position::operator/(Position &other){
	Position tmp;
	tmp.setX(this->getX() / other.getX());
	tmp.setY(this->getY() / other.getY());
	return tmp;
}

//overload the * operator
Position Position::operator*(Position &other){
	Position tmp;
	tmp.setX(this->getX() * other.getX());
	tmp.setY(this->getY() * other.getY());
	return tmp;
}

//overloading the *= operator
Position Position::operator*=(Position &other){
	this->setX(this->getX() * other.getX());
	this->setY(this->getY() * other.getY());
	return *this;
}

//overloading the /= operator
Position Position::operator/=(Position &other){
	this->setX(this->getX() / other.getX());
	this->setY(this->getY() / other.getY());
	return *this;
}

//overloading the -- operator prefix
Position &Position::operator--(){
	this->setX(this -> getX() - 1.0f);
	this->setY(this->getY() - 1.0f);
	return *this;
}

//overloading the ++ operator prefix
Position &Position::operator++(){
	this->setX(this->getX() + 1.0f);
	this->setY(this->getY() + 1.0f);
	return *this;
}

//overloading the -- operator postfix
Position Position::operator--(int z){
	Position tmp(*this);
	this -> operator--();
	return tmp;
}

//overloading the ++ operator postfix
Position Position::operator++(int z){
	Position tmp(*this);
	this -> operator++();
	return tmp;
}