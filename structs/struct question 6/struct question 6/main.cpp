#include"item.h"
#include"shop.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
	//creating shop and items, filling inventory with items
	Shop shop(1111);
	Item cabbage("Cabbage", 3.5, 50);
	Item sword("Sword", 50, 10);
	Item shield("Shield", 40, 7);
	Item phoenix("Phoenix down", 500, 5);
	Item theCube;
	
	shop.setInventory(cabbage);
	shop.setInventory(sword);
	shop.setInventory(shield);
	shop.setInventory(phoenix);
	shop.setInventory(theCube);
	cout << "this is your store! ";
	bool shopping = true;
	int actionChoice;
	while(shopping == true){
		cout << "Choose one of the following actions:\n";
		cout << "[1]View inventory\n[2]Buy an item\n[3]Sell an item\n[4]Quit: ";
		cin >> actionChoice;
		switch(actionChoice){
		case 1:
			cout << "\n\nHere is your inventory: \n";
			shop.getInventory();
			break;
		case 2:
			cout << "what item would you like to buy? [1]Cabbage, [2]sword, [3]shield, [4]phoenix down or [5]generic cube: ";
			int buyChoice;
			cin >> buyChoice;
			switch(buyChoice){
			case 1:
				if(shop.buyItem(cabbage) == true){
					cout << "\ncabbage bought!\n";
				}else{
					cout << "\nNot enough gold\n";
				}
				break;
			case 2:
				if(shop.buyItem(sword) == true){
					cout << "\nsword bought!\n";
				}
				else{
					cout << "\nNot enough gold\n";
				}
				break;
			case 3:
				if(shop.buyItem(shield) == true){
					cout << "\nshield bought!\n";
				}
				else{
					cout << "\nNot enough gold\n";
				}
				break;
			case 4:
				if(shop.buyItem(phoenix) == true){
					cout << "\nphoenix down bought!\n";
				}
				else{
					cout << "\nNot enough gold\n";
				}
				break;
			case 5:
				if(shop.buyItem(theCube) == true){
					cout << "\ngeneric cube bought bought!\n";
				}
				else{
					cout << "\nNot enough gold\n";
				}
				break;
			default:
				cout << "\nnot an option\n";
				break;
			}
			break;
		case 3:
			cout << "what would you like to sell? [1]cabbage, [2]sword, [3]shield, [4]phoenix down, [5]cube: ";
			int sellChoice;
			cin >> sellChoice;
			switch(sellChoice){
			case 1:
				if(shop.sellItem(cabbage) == true){
					cout << "\ncabbage sold!\n";
				}
				else{
					cout << "\nout of cabbage to sell\n";
				}
				break;
			case 2:
				if(shop.sellItem(sword) == true){
					cout << "\nsword sold!\n";
				}
				else{
					cout << "\nNot enough to sell\n";
				}
				break;
			case 3:
				if(shop.sellItem(shield) == true){
					cout << "\nshield sold!\n";
				}
				else{
					cout << "\nNot enough to sell\n";
				}
				break;
			case 4:
				if(shop.sellItem(phoenix) == true){
					cout << "\nphoenix down sold!\n";
				}
				else{
					cout << "\nNot enough to sell\n";
				}
				break;
			case 5:
				if(shop.sellItem(theCube) == true){
					cout << "\ngeneric cube bought sold!\n";
				}
				else{
					cout << "\nNot enough to sell\n";
				}
				break;
			default:
				cout << "\nnot an option\n";
				break;
			}
			break;
		case 4:
			cout << "\nThanks for playing\n";
			shopping = false;
			break;
		default:
			cout << "not an option";
			break;
		}
	}
	system("pause");
	return 0;
}