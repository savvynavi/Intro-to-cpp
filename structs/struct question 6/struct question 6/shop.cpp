#include"shop.h"
#include"item.h"
#include<iostream>
using namespace std;

//constructor
Shop::Shop(){
	setGold(1500);
}

//Constructor overload
Shop::Shop(float gold){
	setGold(gold);
}

//destructor
Shop::~Shop(){

}

//gets gold amount you currently have
float Shop::getGold(){
	return m_gold;
}

//sets the amount of gold you have
void Shop::setGold(float gold){
	m_gold = gold;
}

//subtracts item value from gold, increments quantity counter for item but only if you have enough gold to buy it
bool Shop::buyItem(Item &stock){
	for(int i = 0; i < m_inventory.size(); i++){
		if(m_inventory[i].getName().compare(stock.getName()) == 0 && m_gold >= stock.getPrice()){
			m_inventory[i].quantityUp();
			m_gold = m_gold - stock.getPrice();
			return true;
		}
	}
	return false;
}

//adds item value to gold, decrements quantity counter for item
bool Shop::sellItem(Item &stock) {
	for(int i = 0; i < m_inventory.size(); i++){
		if(m_inventory[i].getName().compare(stock.getName()) == 0){
			m_inventory[i].quantityDown();
			m_gold = m_gold + stock.getPrice();
			return true;
		}
	}
	return false;
}

//prints the contents of the inventory, with spaces between elements
void Shop::getInventory(){
	for(int i = 0; i < m_inventory.size(); i++){
		cout << m_inventory[i].getName() << "x" << m_inventory[i].getQuantity() << endl;
	}
	cout << endl;
}

//lets the user set the inventory by checking to see if the name is already there, if not it stores the whole item inside the m_inventory vector 
void Shop::setInventory(Item &stock){
	for(int i = 0; i < m_inventory.size(); i++){
		if(m_inventory[i].getName() == stock.getName()){
			cout << "\nitem already here\n";
			return;
		}
	}
	m_inventory.push_back(stock);
}