#ifndef PLAYER_H
#define PLAYER_H
class Player{
public:
	Player();
	Player(const char symbol, int playerNumber);
	~Player();
	char getSymbol();
	int getPlayerNumber();
private:
	char m_symbol;
	int m_playerNumber;
};
#endif