#include<iostream>
#include<string>
using namespace std;

//making basic player struct
struct Player{
	string name;
	int health;
	int score;
	float x;
	float y;
	float velocity;
};

Player userCreator(Player &player, int &userScore, string &username);

//creates array of players, lets user enter the name and score for eaach of them using the function using a loop, prints the results
int main(){
	const int numOfPlayers = 5;
	Player user1;
	Player user2;
	Player user3;
	Player user4;
	Player user5;
	string currentName;
	int currentScore;
	Player playerArray[numOfPlayers] = {user1, user2, user3, user4, user5};
	for(int i = 0; i < numOfPlayers; i++){
		cout << "enter player " << i + 1 << " name: ";
		getline(cin, currentName);
		cout << "\nNow enter their score: ";
		cin >> currentScore;
		userCreator(playerArray[i], currentScore, currentName);
		cout << endl;
		cin.ignore();
		cin.clear();
	}

	for(int i = 0; i < numOfPlayers; i++){
		cout << "Player " << i + 1 << " is " << playerArray[i].name << ", with a score of " << playerArray[i].score << endl;
	}

	//question 5 section, adding in name search (you enter a name, if they are found it will output their score)
	string searchName;
	cout << "Enter the name of a player whos score you want: ";
	getline(cin, searchName);
	bool playerFound = false;
	int location;
	for(int i = 0; i < numOfPlayers; i++){
		if(playerArray[i].name == searchName){
			playerFound = true;
			location = i;
		}
	}
	if(playerFound == true){
		cout << "\nPlayer found! their score is " << playerArray[location].score << endl;
	}else{
		cout << "\nNo match found\n";
	}

	system("pause");
	return 0;
}

//creates the player from user input here
Player userCreator(Player &player, int &userScore, string &username){
	player.name = username;
	player.score = userScore;
	return player;
}