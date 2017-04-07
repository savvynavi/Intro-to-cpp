#ifndef ITEM_H
#define ITEM_H
#include<string>

class Item{
public:
	Item();
	Item(std::string name, float price, int quantity);
	~Item();
	void setPrice(float price);
	float getPrice();
	void setName(std::string name);
	std::string getName();
	void setQuantity(int quantity);
	int getQuantity();
	void quantityUp();
	void quantityDown();
private:
	float m_price;
	std::string m_name;
	int m_quantity;
};
#endif