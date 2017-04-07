#include"item.h"
#include"inventory.h"
#include"room.h"
#include"player.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//struct House{
//	Room data;
//	House *m_north;
//	House *m_south;
//	House *m_east;
//	House *m_west;
//};


bool walk(int choice, Room &room);
void examineItem(Item &item, vector<Item> &items);
void examineRoom(Room &room);
void controls();



int main(){
	
	//map stuff, setting up a map that holds a vector of all the rooms a room can lead to
	map<Room, vector<Room>> house;
	
	/*house[room1].push_back(room2);
	house[room2].push_back(room1);
	house[room2].push_back(room3);
	house[room3].push_back(room2);*/

	Room *currentRoom;
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
	Room kitchen("Kitchen", "A small kitchen that looks like it hasnb't been used recently", false, false, true, false);
	Room lounge("Loungeroom", "A sparsely furnished loungeroom, the few bits of furniture here are covered in dusty cloth", false, true, false, true);
	Room bathroom("Bathroom", "A cramped bathroom, dimly lit and covered in a layer og grime", true, false, false, true);
	Room bedroom("Bedroom", "A nice room with a large window to the wouth overlooking an overgrown garden, the only furniture present being a large bedframe and a dusty bookshelf", true, false, true, false);
	
	//creating map of the rooms so each room has a vector of all the rooms it can go to
	house[hall].push_back(EXIT);
	house[hall].push_back(kitchen);
	house[hall].push_back(lounge);
	house[hall].push_back(bedroom);
	house[kitchen].push_back(hall);
	house[lounge].push_back(hall);
	house[lounge].push_back(bathroom);
	house[bathroom].push_back(lounge);
	house[bathroom].push_back(lounge);
	house[bedroom].push_back(hall);
	house[bedroom].push_back(bathroom);
	
	//set current room to the entry hall
	currentRoom = &house[EXIT][0];

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

	bool playing = true;

	while(playing == true){
		cout << "You find yourself in an unfamiliar room, what do you do?(type help at any time to get controls):\n";
		string input;
		cin.getline(input);
		switch(input){
		case "help":
			controls();
			break;

		}
	}

	////test house of 3 rooms
	//bool running = true;
	//while(running == true){
	//	cout << "you are currently in the " << currentRoom -> getName() << endl;
	//	cout << "[1]walk north\n[2]walk south\n[3]walk east\n[4]walk west\n";
	//	int choice;
	//	cin >> choice;
	//	switch(choice){
	//	//walking north
	//	case 1:
	//		if(walk(choice, *currentRoom) == true){
	//			for(int i = 0; i < house[*currentRoom].size(); i++){
	//				if(house[*currentRoom][i].getSouth() == true){
	//					currentRoom = &house[*currentRoom][i];
	//				}
	//			}
	//		}
	//		break;
	//	//walking south
	//	case 2:
	//		if(walk(choice, *currentRoom) == true){
	//			for(int i = 0; i < house[*currentRoom].size(); i++){
	//				if(house[*currentRoom][i].getNorth() == true){
	//					currentRoom = &house[*currentRoom][i];
	//				}
	//			}
	//		}
	//		break;
	//	//walking east
	//	case 3:
	//		if(walk(choice, *currentRoom) == true){
	//			for(int i = 0; i < house[*currentRoom].size(); i++){
	//				if(house[*currentRoom][i].getWest() == true){
	//					currentRoom = &house[*currentRoom][i];
	//				}
	//			}
	//		}
	//		break;
	//	//walking west
	//	case 4:
	//		if(walk(choice, *currentRoom) == true){
	//			for(int i = 0; i < house[*currentRoom].size(); i++){
	//				if(house[*currentRoom][i].getEast() == true){
	//					currentRoom = &house[*currentRoom][i];
	//				}
	//			}
	//		}
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
	cout << "\t\texamine room - Will examine the room you are in\n";
	cout << "\t\tnorth - will move you north\n";
	cout << "\t\tsouth - will move you south\n";
	cout << "\t\teast - will move you east\n";
	cout << "\t\twest - will move you west\n";
	cout << "\t\texamine <item name> - will examine the item\n";
	cout << "\t\tpickup <item name> - picks the item up\n";
	cout << "\t\tdrop <item name> - will drop the item\n";
	cout << "\t\tuse <item name> - will use the item\n";
	cout << "\t\tinventory - will display your current inventory\n";
}


//moves the player, returns true if you can walk that way and false if not
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