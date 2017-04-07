#include"Board.h"
#include<iostream>
using namespace std;

Board::Board(){
	m_width = 3;
	m_height = 3;
	m_board = new char*[m_height];
	for(int i = 0; i < m_height; i++){
		m_board[i] = new char[m_width];
	}
	reset();
}

Board::~Board(){
	for(int i = 0; i < m_height; i++){
		delete[] m_board[i];
	}
	delete[] m_board;
}

//returns height of board
int Board::getHeight(){
	return m_height;
}

//returns width of board
int Board::getWidth(){
	return m_width;
}

//prints out the current boardstate
void Board::print(){
	cout << "     1      2      3\n";
	cout << "   ___________________   \n";
	cout << "  |     |      |      |\n";
	cout << " a|  " << m_board[0][0] << "  |  " << m_board[0][1] << "   |   " << m_board[0][2] << "  |\n";
	cout << "  |_____|______|______|\n";
	cout << "  |     |      |      |\n";
	cout << " b|  " << m_board[1][0] << "  |  " << m_board[1][1] << "   |   " << m_board[1][2] << "  |\n";
	cout << "  |_____|______|______|\n";
	cout << "  |     |      |      |\n";
	cout << " c|  " << m_board[2][0] << "  |  " << m_board[2][1] << "   |   " << m_board[2][2] << "  |\n";
	cout << "  |_____|______|______|\n";
}

//clears all player input from board and resets it to an empty state
void Board::reset(){
	for(int i = 0; i < m_height; i++){
		for(int j = 0; j < m_width; j++){
			m_board[i][j] = ' ';
		}
	}
}

//returns false if the board isn't full, true otherwise
bool Board::checkIfFull(){
	for(int i = 0; i < m_height; i++){
		for(int j = 0; j < m_width; j++){
			if(m_board[i][j] == ' '){
				return false;
			}
		}
	}
	return true;
}

//returns true if the move is valid, false otherwise, doesn't actually set move
bool Board::getMove(int row, int col, char symbol){
	if(m_board[row][col] == ' '){
		return true;
	}
	return false;
}

//takes in the players move and will save the players symbol into the array if the space is empty, returns true if it is and false if unable to
bool Board::setMove(char row, int col, char symbol){
	bool validMove = true;
	switch(row){
	case 'a':
		if(col == 1 && m_board[0][0] == ' '){
			m_board[0][0] = symbol;
		} else if(col == 2 && m_board[0][1] == ' '){
			m_board[0][1] = symbol;
		} else if(col == 3 && m_board[0][2] == ' '){
			m_board[0][2] = symbol;
		} else{
			validMove = false;
			cout << "\nERROR invalid input\n";
		}
		break;
	case 'b':
		if(col == 1 && m_board[1][0] == ' '){
			m_board[1][0] = symbol;
		} else if(col == 2 && m_board[1][1] == ' '){
			m_board[1][1] = symbol;
		} else if(col == 3 && m_board[1][2] == ' '){
			m_board[1][2] = symbol;
		} else{
			validMove = false;
			cout << "\nERROR invalid input\n";
		}
		break;
	case 'c':
		if(col == 1 && m_board[2][0] == ' '){
			m_board[2][0] = symbol;
		} else if(col == 2 && m_board[2][1] == ' '){
			m_board[2][1] = symbol;
		} else if(col == 3 && m_board[2][2] == ' '){
			m_board[2][2] = symbol;
		} else{
			validMove = false;
			cout << "\nERROR invalid input\n";
		}
		break;
	default:
		cout << "\nERROR invalid input\n";
		validMove = false;
		break;
	}
	return validMove;
}

//resets given space
void Board::undoMove(int row, int col){
	m_board[row][col] = ' ';
}

//goes through and checks if any rows, columns or diagonals are all the same symbol, returns true if so and false otherwise
bool Board::winCheck(char symbol){
	if((m_board[0][0] == symbol && m_board[0][1] == symbol && m_board[0][2] == symbol) || (m_board[1][0] == symbol && m_board[1][1] == symbol && m_board[1][2] == symbol) || (m_board[2][0] == symbol && m_board[2][1] == symbol && m_board[2][2] == symbol)){
		return true;
	} else if((m_board[0][0] == symbol && m_board[1][0] == symbol && m_board[2][0] == symbol) || (m_board[0][1] == symbol && m_board[1][1] == symbol && m_board[2][1] == symbol) || (m_board[0][2] == symbol && m_board[1][2] == symbol && m_board[2][2] == symbol)){
		return true;
	} else if((m_board[0][0] == symbol && m_board[1][1] == symbol && m_board[2][2] == symbol) || (m_board[0][2] == symbol && m_board[1][1] == symbol && m_board[2][0] == symbol)){
		return true;
	}
	return false;
}