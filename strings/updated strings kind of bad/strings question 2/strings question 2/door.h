#ifndef DOOR_H
#define DOOR_H
#include"room.h"

class Door{
public:
	Door();
	Door(Room *room);
	~Door();
	//bool operator<(const Door &newDoor)const;
private:
	Room *m_room;
};
#endif