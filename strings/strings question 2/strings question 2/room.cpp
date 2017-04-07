#include"item.h"
#include"room.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

Room::Room(){
	m_name = "blank room";
	m_description = "nothing to see here";
	m_north = false;
	m_south = false;
	m_east = false;
	m_west = false;
}

Room::Room(string name, string description, bool north, bool south, bool east, bool west){
	m_name = name;
	m_description = description;
	m_north = north;
	m_south = south;
	m_east = east;
	m_west = west;
}

Room::~Room(){

}

string Room::getName() const{
	return m_name;
}

void Room::examine(){
	cout << m_description << endl;
	cout << "This room contains:\n";
	for(int i = 0; i < m_roomContents.size(); i++){
		cout << "\t\t" << m_roomContents[i].getName() << endl;
	}
}

void Room::setContents(Item &item){
	m_roomContents.push_back(item);
}

void Room::removeItem(Item &item){
	for(int i = 0; i < m_roomContents.size(); i++){
		if(m_roomContents[i].getName() == item.getName()){
			m_roomContents.erase(m_roomContents.begin() + i);
			return;
		}
	}
}

vector<Item> Room::getContents(){
	return m_roomContents;
}

bool Room::getNorth(){
	return m_north;
}

bool Room::getSouth(){
	return m_south;
}

bool Room::getEast(){
	return m_east;
}

bool Room::getWest(){
	return m_west;
}

bool Room::operator<(const Room &newRoom)const{
	if(newRoom.getName() < this -> getName()){
		return true;
	}
	return false;
}