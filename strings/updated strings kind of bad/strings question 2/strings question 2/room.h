#ifndef ROOM_H
#define ROOM_H
#include"item.h"
#include<string>

class Room{
public:
	Room();
	Room(std::string name, std::string description, bool north, bool south, bool east, bool west);
	~Room();
	std::string getName() const;
	void examine();
	void setContents(Item &item);
	std::vector<Item> getContents();
	void removeItem(Item &item);
	bool getNorth();
	bool getSouth();
	bool getEast();
	bool getWest();
	bool operator<(const Room &newRoom)const;
private:
	std::vector<Item> m_roomContents;
	std::string m_name;
	std::string m_description;
	bool m_north;
	bool m_south;
	bool m_east;
	bool m_west;
};
#endif