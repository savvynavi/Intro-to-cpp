#include"item.h"
#include<iostream>
using namespace std;

//Default Constructor
Item::Item(){
	setName("perfectly generic cube");
	setWeight(5);
	setStackable(true);
	setStackCount(10);

}

//Non-stackable item constructor
Item::Item(string name, int weight){
	setName(name);
	setWeight(weight);
	setStackable(false);
	setStackCount(1);
}

//Stackable item constructor
Item::Item(string name, int weight, int stackCount){
	setName(name);
	setWeight(weight);
	setStackable(true);
	setStackCount(stackCount);
}

//Destructor
Item::~Item(){

}

//sets the item name
void Item::setName(string name){
	m_name = name;
}

//gets the item name
string Item::getName(){
	return m_name;
}

//sets the item weight
void Item::setWeight(int weight){
	m_weight = weight;
}

//gets the item weight
int Item::getWeight(){
	return m_weight;
}

//sets m_stackable to true if the item can stack, to false if it can't be
void Item::setStackable(bool stackable){
	m_stackable = stackable;
}

//gets if the item can be stacked
bool Item::getStackable(){
	return m_stackable;
}

//gets the stack count
int Item::getStackCount(){
	return m_stackCount;
}

//sets the stack count
void Item::setStackCount(int stackCount){
	if(stackCount > 0){
		m_stackCount = stackCount;
	}
}

//add amount to stack
void Item::stackPlus(int changeNum){
	m_stackCount += changeNum;
}

//subtracts amount from stack
void Item::stackSub(int changeNum){
	if((getStackCount() - changeNum) > 0){
		m_stackCount -= changeNum;
	}else{
		m_stackCount = 0;
	}
}