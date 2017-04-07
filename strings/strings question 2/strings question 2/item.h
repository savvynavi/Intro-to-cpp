#ifndef ITEM_H
#define ITEM_H
#include<string>
#include<vector>

class Item{
public:
	Item();
	Item(std::string name, std::string description);
	~Item();
	std::string getName();
	void setName(std::string name);
	std::string getDescription();
	void setDescription(std::string description);
private:
	std::string m_name;
	std::string m_description;
};
#endif