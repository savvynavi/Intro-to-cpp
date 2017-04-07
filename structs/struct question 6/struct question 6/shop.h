#ifndef SHOP_H
#define SHOP_H
#include"item.h"
#include<vector>

class Shop{
public:
	Shop();
	Shop(float gold);
	~Shop();
	float getGold();
	void setGold(float gold);
	bool buyItem(Item &stock);
	bool sellItem(Item &stock);
	void setInventory(Item &stock);
	void getInventory();
private:
	std::vector<Item> m_inventory;
	float m_gold;
	int m_itemQuantity;
};

#endif