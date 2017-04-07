#include"item.h"
#include"inventory.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

Inventory::Inventory(){

}

Inventory::~Inventory(){

}

void Inventory::pickupItem(Item &newItem){
	m_inventory.push_back(newItem);
}

void Inventory::dropItem(Item &newItem){
	for(int i = 0; i < m_inventory.size(); i++){
		if(m_inventory[i].getName() == newItem.getName()){
			m_inventory.erase(m_inventory.begin() + i);
			return;
		}
	}
}

void Inventory::printInventory(){
	for(int i = 0; i < m_inventory.size(); i++){
		cout << m_inventory[i].getName() << endl;
	}
}

vector<Item> Inventory::getInventory(){
	return m_inventory;
}