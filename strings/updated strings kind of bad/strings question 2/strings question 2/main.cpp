#include"item.h"
#include"inventory.h"
#include"room.h"
#include"player.h"
#include"door.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//struct House{
//	Room data;
//	House *m_north;
//	House *m_south;
//	House *m_east;
//	House *m_west;
//};

enum eChoice{
	eNorth,
	eSouth,
	eEast,
	eWest,
	eExamineRoom,
	ePickup,
	eDrop,
	eExamineItem,
	eUse
};

bool walk(int choice, Room &room);
void examineItem(Item &item, vector<Item> &items);
void examineRoom(Room &room);
void controls();


int main(){

	//map stuff, setting up a map that holds a vector of all the rooms a room can lead to
	map<Room, vector<Door>> house;

	/*house[room1].push_back(room2);
	house[room2].push_back(room1);
	house[room2].push_back(room3);
	house[room3].push_back(room2);*/

	Door *currentRoom;
	Room *tmpRoom;


	//currentRoom = &house[room1][0];
	/*cout << house[room1][0].getName() << endl;

	Player player(currentRoom);

	cout << player.getRoom().getName() << endl;
	currentRoom = &house[room2][];
	player.setRoom(currentRoom);
	cout << player.getRoom().getName() << endl;*/

	//creating rooms for the house
	Room hall("Main Hall", "A nicely lit if dusty room with 4 exits", true, true, true, true);
	Room EXIT(" ", " ", false, true, false, false);
	Room kitchen("Kitchen", "A small kitchen that looks like it hasnb't been used recently. There is one exit to the east", false, false, true, false);
	Room lounge("Loungeroom", "A sparsely furnished loungeroom, the few bits of furniture here are covered in dusty cloth. There are 2 exits to the south and west", false, true, false, true);
	Room bathroom("Bathroom", "A cramped bathroom, dimly lit and covered in a layer og grime. There are 2 exits to the north and west", true, false, false, true);
	Room bedroom("Bedroom", "A nice room with a large window to the wouth overlooking an overgrown garden, the only furniture present being a large bedframe and a dusty bookshelf. there are 2 exits to the north and east", true, false, true, false);
	
	//creating items for the game/player inventory
	Item carKeys("Car Keys", "Keys for a car you don't recognize");
	Item coat("Coat", "I warm coat");
	Item knife("Knife", "A dull kitchen knice, slightly rusted");
	Item apple("Apple", "A rotten apple");
	Item glass("Glass of Water", "A glass half full of water");
	Item book("Book", "A dusty book, yellowing with age");
	Item money("Coins", "A handful of old coins");
	Item wallet("Wallet", "Your wallet, fairly new and empty");
	Inventory bag;

	//placing items
	bag.pickupItem(wallet);
	hall.setContents(carKeys);
	hall.setContents(coat);
	kitchen.setContents(knife);
	kitchen.setContents(apple);
	kitchen.setContents(glass);
	lounge.setContents(book);
	bedroom.setContents(money);
	
	//creating a door for each room
	Door dEXIT(&EXIT);
	Door dHall(&hall);
	Door dKitchen(&kitchen);
	Door dLounge(&lounge);
	Door dBathroom(&bathroom);
	Door dBedroom(&bedroom);


	//creating map of the rooms so each room has a vector of all the rooms it can go to
	house[EXIT].push_back(dHall);
	house[hall].push_back(dEXIT);
	house[hall].push_back(dLounge);
	house[hall].push_back(dBedroom);
	house[hall].push_back(dKitchen);
	house[kitchen].push_back(dHall);
	house[lounge].push_back(dBathroom);
	house[lounge].push_back(dHall);
	house[bathroom].push_back(dLounge);
	house[bathroom].push_back(dBedroom);
	house[bedroom].push_back(dHall);
	house[bedroom].push_back(dBathroom);

	//set current room to the entry hall
	currentRoom = &house[EXIT][0];
	//tmpRoom = &house[EXIT][0];
	
	bool playing = true;
	while(playing = true){
		cout << "you are currently in the " << currentRoom -> getName() << endl;
		cout << "[1]walk north\n[2]walk south\n[3]walk east\n[4]walk west\n[5]examine room\n[6]view inventory\n: ";
		int choice;
		cin >> choice;
		switch(choice){
		case 1:
			//walk north
			if(house[currentRoom].getNorth() == true){

			}
			break;
		case 2:
			//walk south
			break;
		case 3:
			//walk east
			break;
		case 4:
			//walk west
			break;
		default:
			cout << "\nERROR bad input\n";
			cin.clear();
			cin.ignore();
			break;
		}
	}

	
	//bool running = true;
	//while(running == true){
	//	cout << "you are currently in the " << currentRoom -> getName() << endl;
	//	cout << "[1]walk north\n[2]walk south\n[3]walk east\n[4]walk west\n[5]examine room\n[6]view inventory\n: ";
	//	int choice;
	//	cin >> choice;
	//	switch(choice){
	//	//walking north
	//	case 1:
	//		if(walk(choice, *currentRoom) == true){
	//			for(int i = 0; i < house[*currentRoom].size(); i++){
	//				if(house[*currentRoom][i].getSouth() == true){
	//					tmpRoom = &house[*currentRoom][i];
	//					for(int j = 0; j < house[*tmpRoom].size(); j++){
	//						if((house[*tmpRoom][j].getSouth() == true) && (house[*tmpRoom][j].getName() == currentRoom -> getName())){
	//							currentRoom = &house[*currentRoom][i];
	//							break;
	//						}
	//					}
	//				}
	//			}
	//		}
	//		break;
	//	//walking south
	//	case 2:
	//		if(walk(choice, *currentRoom) == true){
	//			for(int i = 0; i < house[*currentRoom].size(); i++){
	//				if(house[*currentRoom][i].getNorth() == true){
	//					tmpRoom = &house[*currentRoom][i];
	//					for(int j = 0; j < house[*tmpRoom].size(); j++){
	//						if((house[*tmpRoom][j].getNorth() == true) && (house[*tmpRoom][j].getName() == currentRoom->getName())){
	//							currentRoom = &house[*currentRoom][i];
	//							break;
	//						}
	//					}
	//				}
	//			}
	//		}
	//		break;
	//	//walking east
	//	case 3:
	//		if(walk(choice, *currentRoom) == true){
	//			for(int i = 0; i < house[*currentRoom].size(); i++){
	//				if(house[*currentRoom][i].getWest() == true){
	//					tmpRoom = &house[*currentRoom][i];
	//					for(int j = 0; j < house[*tmpRoom].size(); j++){
	//						if((house[*tmpRoom][j].getWest() == true) && (house[*tmpRoom][j].getName() == currentRoom->getName())){
	//							currentRoom = &house[*currentRoom][i];
	//							break;
	//						}
	//					}
	//				}
	//			}
	//		}
	//		break;
	//	//walking west
	//	case 4:
	//		if(walk(choice, *currentRoom) == true){
	//			for(int i = 0; i < house[*currentRoom].size(); i++){
	//				if(house[*currentRoom][i].getEast() == true){
	//					tmpRoom = &house[*currentRoom][i];
	//					for(int j = 0; j < house[*tmpRoom].size(); j++){
	//						if((house[*tmpRoom][j].getEast() == true) && (house[*tmpRoom][j].getName() == currentRoom->getName())){
	//							currentRoom = &house[*currentRoom][i];
	//							break;
	//						}
	//					}
	//				}
	//			}
	//		}
	//		break;
	//	case 5:
	//		currentRoom->examine();
	//		break;
	//	case 6:
	//		cout << "\nYour inventory contains the following:\n\t";
	//		bag.printInventory();
	//		cout << endl;
	//		break;
	//	default:
	//		cout << "\nnot an option here\n";
	//		cin.clear();
	//		cin.ignore();
	//		break;
	//	}
	//}

	system("pause");
	return 0;
}

//prints out controls
void controls(){
	cout << "\texamine room - Will examine the room you are in\n";
	cout << "\tnorth - will move you north\n";
	cout << "\tsouth - will move you south\n";
	cout << "\teast - will move you east\n";
	cout << "\twest - will move you west\n";
	cout << "\texamine <item name> - will examine the item\n";
	cout << "\tpickup <item name> - picks the item up\n";
	cout << "\tdrop <item name> - will drop the item\n";
	cout << "\tuse <item name> - will use the item\n";
	cout << "\tinventory - will display your current inventory\n";
}


//returns true if you can walk that way and false if not
bool walk(int choice, Room &room){
	bool moved = false;
	switch(choice){
	case 1:
		if(room.getNorth() == true){
			cout << "\nyou go through the northern entryway\n";
			moved = true;
		}else{
			cout << "\nyou bump against the north wall as there is no door here\n";
		}
		break;
	case 2:
		if(room.getSouth() == true){
			cout << "\nyou go through the southern entryway\n";
			moved = true;
		}
		else{
			cout << "\nyou bump against the south wall as there is no door here\n";
		}
		break;
	case 3:
		if(room.getEast() == true){
			cout << "\nyou go through the eastern entryway\n";
			moved = true;
		}
		else{
			cout << "\nyou bump against the eastern wall as there is no door here\n";
		}
		break;
	case 4:
		if(room.getWest() == true){
			cout << "\nyou go through the weatern entryway\n";
			moved = true;
		}
		else{
			cout << "\nyou bump against the western wall as there is no door here\n";
		}
		break;
	}
	return moved;
}

//prints out item description
void examineItem(Item &item, vector<Item> &items){
	for(int i = 0; i < items.size(); i++){
		if(items[i].getName() == item.getName()){
			cout << items[i].getDescription() << endl;
			return;
		}
	}
}

//prints out the room description
void examineRoom(Room &room){
	room.examine();
}