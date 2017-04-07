#include"item.h"
#include<iostream>
using namespace std;

//Constructor
Item::Item(){
	setName("perfectly generic cube");
	setPrice(10);
	setQuantity(15);
}

//Constructor overload
Item::Item(std::string name, float price, int quantity){
	setName(name);
	setPrice(price);
	setQuantity(quantity);
}

//Destructor
Item::~Item(){

}

//allows you to get an item name
string Item::getName(){
	return m_name;
}

//allows you to set an item name
void Item::setName(string name){
	m_name = name;
}

//gets the price of the item
float Item::getPrice(){
	return m_price;
}

//sets the price of the item
void Item::setPrice(float price){
	if(price >= 0){
		m_price = price;
	}else{
		cout << "\nERROR can't have negative price\n";
	}
}

//lets you get the quantity of the item currently stocked
int Item::getQuantity(){
	return m_quantity;
}

//lets you set the quantity as long as it's 0 or more
void Item::setQuantity(int quantity){
	if(quantity >= 0){
		m_quantity = quantity;
	}else{
		cout << "\nERROR can't have negative items\n";
	}
}

//increments quantity by 1
void Item::quantityUp(){
	m_quantity++;
}

//decrements quantity by 1 as long as it isn't 0 or less
void Item::quantityDown(){
	if(m_quantity <= 0){
		cout << "\nERROR can't have negative quantities\n";
	}else{
		m_quantity--;
	}
}