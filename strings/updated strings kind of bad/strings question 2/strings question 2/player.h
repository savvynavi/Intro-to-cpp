#ifndef PLAYER_H
#define PLAYER_H
#include"room.h"
#include<string>
#include<vector>

class Player{
public:
	Player();
	Player(Room *currentRoom);
	~Player();
	Room getRoom();
	void setRoom(Room *currentRoom);
private:
	Room *m_currentRoom;
};
#endif