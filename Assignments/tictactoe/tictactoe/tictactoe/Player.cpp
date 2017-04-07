#include"Player.h"


Player::Player(){
	m_symbol = 'X';
	m_playerNumber = 1;
}

Player::Player(const char symbol, int playerNumber){
	m_symbol = symbol;
	m_playerNumber = playerNumber;
}

Player::~Player(){

}

//returns what symbol the player is using 
char Player::getSymbol(){
	return m_symbol;
}

//returns what player number they have
int Player::getPlayerNumber(){
	return m_playerNumber;
}