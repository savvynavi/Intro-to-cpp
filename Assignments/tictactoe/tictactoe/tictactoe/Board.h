#ifndef BOARD_H
#define BOARD_H
class Board{
public:
	Board();
	~Board();
	int getHeight();
	int getWidth();
	void print();
	void reset();
	bool checkIfFull();
	bool getMove(int row, int col, char symbol);	
	bool setMove(char row, int col, char symbol);
	void undoMove(int row, int col);
	bool winCheck(char symbol);

private:
	char **m_board;
	int m_height;
	int m_width;
	char m_row;
	char m_symbol;
	int m_col;
};
#endif