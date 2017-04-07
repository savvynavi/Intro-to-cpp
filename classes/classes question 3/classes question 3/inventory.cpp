#include"item.h"
#include"inventory.h"
#include<vector>
#include<iostream>
using namespace std;

//Default Constructor
Inventory::Inventory(){

}

//Destructor
Inventory::~Inventory(){

}

//puts an item into the inventory vector, if stackable it checks i falready inside vector at least once and ups the counter if it is
void Inventory::pickupItem(Item &newItem){
	if(newItem.getStackable() == true){
		for(size_t i = 0; i < m_inventory.size(); i++){
			if(m_inventory[i].getName() == newItem.getName()){
				m_inventory[i].stackPlus(1);
				return;
			}
		}
	}
	m_inventory.push_back(newItem);
}

//removes an item from the inventory vector, if stackable though just removes the stack count until 0
void Inventory::dropItem(Item &newItem){
	for(size_t i = 0; i < m_inventory.size(); i++){
		if(m_inventory[i].getName() == newItem.getName()){
			if(m_inventory[i].getStackable() == true){
				m_inventory[i].stackSub(1);
				return;
			}else{
				m_inventory.erase(m_inventory.begin() + i);
				return;
			}
		}
	}
}

//m_inventory[i].stackPlus(1);
//return;

//m_inventory.erase(m_inventory.begin() + i);
//return;


//prints the inventory out, also stack count if relevant
void Inventory::getInventory(){
	for(size_t i = 0; i < m_inventory.size(); i++){
		cout << m_inventory[i].getName();
		if(m_inventory[i].getStackable() == true){
			cout << " x" << m_inventory[i].getStackCount();
		}
		cout << endl;
	}
}