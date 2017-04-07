#include"room.h"
#include"door.h"

Door::Door(){
	m_room = nullptr;
}

Door::Door(Room *room){
	m_room = room;
}

Door::~Door(){
	delete m_room;
}

//bool Door::operator<(const Door &newDoor)const{
//	if(newDoor.getName() < this -> getName()){
//		return true;
//	}
//	return false;
//}