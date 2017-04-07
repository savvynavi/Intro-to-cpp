#ifndef ITEM_H
#define ITEM_H
#include<string>

class Item{
public:
	Item();
	Item(std::string name, int weight);
	Item(std::string name, int weight, int stackCount);
	~Item();
	void setName(std::string name);
	std::string getName();
	void setWeight(int weight);
	int getWeight();
	void setStackable(bool stackable);
	bool getStackable();
	void setStackCount(int stackCount);
	int getStackCount();
	void stackSub(int changeNum);
	void stackPlus(int changeNum);
private:
	std::string m_name;
	int m_weight;
	bool m_stackable;
	int m_stackCount;
};
#endif