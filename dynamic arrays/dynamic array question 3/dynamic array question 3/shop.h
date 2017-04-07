#ifndef SHOP_H
#define SHOP_H
#include"item.h"
//#include<vector>

class Shop{
public:
	Shop();
	Shop(float gold, int size);
	~Shop();
	float getGold();
	void setGold(float gold);
	bool buyItem(Item &stock);
	bool sellItem(Item &stock);
	void setInventory(Item &stock, int itemNum);
	void getInventory();
	void setInventSize(int size);
	int getInventSize();
private:
	int m_inventSize;
	Item *m_inventory;
	float m_gold;
	int m_itemQuantity;
};

#endif