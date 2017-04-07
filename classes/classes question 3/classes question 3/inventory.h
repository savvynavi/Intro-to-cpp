#ifndef INVENTORY_H
#define INVENTORY_H
#include"item.h"
#include<string>
#include<vector>

class Inventory{
public:
	Inventory();
	~Inventory();
	void pickupItem(Item &newItem);
	void dropItem(Item &newItem);
	void getInventory();
private:
	std::vector<Item> m_inventory;

};
#endif