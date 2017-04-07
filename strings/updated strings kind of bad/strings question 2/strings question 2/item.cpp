#include"item.h"
#include<string>
using namespace std;

Item::Item(){
	setName("Generic Cube");
	setDescription("Perfectly generic in every way");
}

Item::Item(std::string name, std::string description){
	setName(name);
	setDescription(description);
}

Item::~Item(){

}

string Item::getName(){
	return m_name;
}

void Item::setName(std::string name){
	m_name = name;
}

std::string Item::getDescription(){
	return m_description;
}

void Item::setDescription(std::string description){
	m_description = description;
}