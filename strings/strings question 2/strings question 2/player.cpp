#include"player.h"
#include"room.h"
#include<string>
using namespace std;

Player::Player(){
	m_currentRoom = nullptr;
}

Player::Player(Room *currentRoom){
	m_currentRoom = currentRoom;
}

Player::~Player(){

}

Room Player::getRoom(){
	return *m_currentRoom;
}

void Player::setRoom(Room *currentRoom){
	*m_currentRoom = *currentRoom;
}