#include"Board.h"
#include"Player.h"
#include<iostream>
#include<algorithm>
using namespace std;

//defining numbers for infinity(large number) and the character offset eg: turns 0 into 'a' 
#define INF 10
#define OFFSET 97

void twoPlayerGame(Board &board, Player &p1, Player &p2);
void aiGame(Board &board, Player &p1, Player &p2);
int minimax(Board &board, Player *currentPlayer, Player *otherPlayer, int maxDepth);
int maxValue(Board &board, Player *currentPlayer, Player *otherPlayer, int &maxDepth);
int minValue(Board &board, Player *currentPlayer, Player *otherPlayer, int &maxDepth);

int main(){
	Board board;
	Player p1('X', 1);
	Player p2('O', 2);
	int menu;
	bool running = true;
	while(running == true){
		int turns = 9;
		cout << "[1]Play Tic Tac Toe against another person\n[2]Play against an AI\n[3]Quit: ";
		cin >> menu;
		switch(menu){
		case 1:
			twoPlayerGame(board, p1, p2);
			board.reset();
			break;
		case 2:
			aiGame(board, p1, p2);
			board.reset();
			break;
		case 3:
			running = false;
			cout << "\nQuitting now\n";
			break;
		default:
			cout << "\nBad Input\n";
			cin.clear();
			cin.ignore();
			break;
		}
	}
	system("pause");
	return 0;
}

//takes in the board and 2 players, will keep taking user input for moves until either someone has won or 9 moves has passed
void twoPlayerGame(Board &board, Player &p1, Player &p2){
	char inputRow;
	int inputCol;
	int turns = 9;
	int playerSelect = 0;
	Player *currentPlayer;
	board.print();

	while(turns > 0){
		//sets who the current player is
		if((playerSelect % 2) + 1 == 1){
			currentPlayer = &p1;
		}else{
			currentPlayer = &p2;
		}

		cout << "Player " << currentPlayer -> getPlayerNumber() << "'s move: ";
		cin >> inputRow >> inputCol;
		if(cin.fail() == true){
			cout << "\nInvalid input\n";
			cin.clear();
			cin.ignore();
		}else{
			if(board.setMove(inputRow, inputCol, currentPlayer -> getSymbol()) == true){
				turns--;
				playerSelect++;
			}
		}
		board.print();
		if(board.winCheck(currentPlayer->getSymbol()) == true){
			cout << "\nThe winner is player " << currentPlayer -> getPlayerNumber() << "!\n\n";
			return;
		}
	}
	cout << "\nDraw!\n";
}

//takes in the board and 2 players, will take human input and also set AI input using minimax, returns when someone has won or 9 turns has passed
void aiGame(Board &board, Player &p1, Player &p2){
	char inputRow;
	int inputCol;
	int turns = 9;
	int playerSelect = 0;
	Player *currentPlayer;
	Player *otherPlayer;
	board.print();
	//sets how many iterations of solution trees it does(set to 2 so it doesn't always win)
	int maxDepth = 2;

	while(turns > 0){
		//sets who the current player is
		if((playerSelect % 2) + 1 == 1){
			currentPlayer = &p1;
			otherPlayer = &p2;
		}else{
			currentPlayer = &p2;
			otherPlayer = &p1;
		}

		//checks if the player is the AI or the human, if human it takes in player input for move, if AI it calls minimax to find best move
		if(currentPlayer -> getSymbol() == 'O'){
			int currentBestScore = -INF;
			int bestRow;
			int bestCol;
			//loops through board, places AI move and passes to minimax for each available position
			for(int i = 0; i < board.getHeight(); i++){
				for(int j = 1; j <= board.getWidth(); j++){
					if(board.getMove(i, j - 1, currentPlayer -> getSymbol()) == true){
						board.setMove(i + OFFSET, j, currentPlayer -> getSymbol());
						//passes players in this order as AI has already made it's move
						int currentScore = minimax(board, otherPlayer, currentPlayer, maxDepth);
						board.undoMove(i, j - 1);
						if(currentScore > currentBestScore){
							currentBestScore = currentScore;
							bestRow = i + OFFSET;
							bestCol = j;
						}
					}
				}
			}
			board.setMove(bestRow, bestCol, currentPlayer -> getSymbol());
			turns--;
			playerSelect++;
		}else{
			cout << "Player " << currentPlayer -> getPlayerNumber() << "'s move: ";
			cin >> inputRow >> inputCol;
			if(cin.fail() == true){
				cout << "\nInvalid input\n";
				cin.clear();
				cin.ignore();
			}else{
				if(board.setMove(inputRow, inputCol, currentPlayer -> getSymbol()) == true){
					turns--;
					playerSelect++;
				}
			}
		}
		board.print();
		if(board.winCheck(currentPlayer -> getSymbol()) == true){
			cout << "\nThe winner is player " << currentPlayer -> getPlayerNumber() << "!\n\n";
			return;
		}
	}
	cout << "It's a draw!\n";
}

//returns 1 if the AI can win, -1 if player can win, and 0 if it's a draw or if max depth is reached
int minimax(Board &board, Player *currentPlayer, Player *otherPlayer, int maxDepth){

	bool winState = board.winCheck(otherPlayer -> getSymbol());
	if(winState == true && otherPlayer -> getSymbol() == 'O'){
		return 1;
	}else if(winState == true && otherPlayer -> getSymbol() == 'X'){
		return -1;
	}else if(board.checkIfFull() == true || maxDepth <= 0){
		return 0;
	}

	if(currentPlayer -> getSymbol() == 'O'){
		maxValue(board, currentPlayer, otherPlayer, maxDepth);
	}else{
		minValue(board, currentPlayer, otherPlayer, maxDepth);
	}
}

//finds best move for the AI
int maxValue(Board &board, Player *currentPlayer, Player *otherPlayer, int &maxDepth){
	int best = -INF;
	int score;

	for(int i = 0; i < board.getHeight(); i++){
		for(int j = 1; j <= board.getWidth(); j++){
			if(board.getMove(i, j - 1, currentPlayer -> getSymbol()) == true){
				board.setMove(i + OFFSET, j, currentPlayer -> getSymbol());
				score = minimax(board, otherPlayer, currentPlayer, maxDepth--);
				board.undoMove(i, j - 1);
				best = max(best, score);
			}
		}
	}
	return best;
}

//finds best move for the player
int minValue(Board &board, Player *currentPlayer, Player *otherPlayer, int &maxDepth){
	int best = INF;
	int score;

	for(int i = 0; i < board.getHeight(); i++){
		for(int j = 1; j <= board.getWidth(); j++){
			if(board.getMove(i, j - 1, currentPlayer -> getSymbol()) == true){
				board.setMove(i + OFFSET, j, currentPlayer -> getSymbol());
				score = minimax(board, otherPlayer, currentPlayer, maxDepth--);
				board.undoMove(i, j - 1);
				best = min(best, score);
			}
		}
	}
	return best;
}