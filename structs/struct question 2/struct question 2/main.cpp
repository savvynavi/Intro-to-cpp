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

//takes in name/score, stores in member vars in struct, prints them out
int main(){
	Player user;
	string name;
	int inputScore;
	cout << "Enter a name: ";
	getline(cin, name);
	cout << "\nEnter a score: ";
	cin >> inputScore;

	userCreator(user, inputScore, name);
	cout << "\nYour name is " << user.name << ", and your score is " << user.score << endl;
	
	system("pause");
	return 0;
}

//creates the player from user input here
Player userCreator(Player &player, int &userScore, string &username){
	player.name = username;
	player.score = userScore;
	return player;
}