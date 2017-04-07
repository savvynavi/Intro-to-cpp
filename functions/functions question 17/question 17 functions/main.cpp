#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

void computerChoice(int &compChoice);
int gameResult(int &playerChoice, int &compChoice);

//takes player input for either rock, paper or scissors, randomly picks what the computer plays, displays it, and says if you won, lost or drew
int main(){
	//keeps playing as long as there is a draw
	bool playing = true;
	while (playing) {
		playing = false;
		//gets computer choice
		int compChoice;
		computerChoice(compChoice);

		//gets player choice
		cout << "enter either 1 for rock, 2 for paper, or 3 for scissors: ";
		bool inputFlag = true;
		int choice;
		//checks for valid play input, if none loops to start, can input again
		while (inputFlag) {
			inputFlag = false;
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "\nRock picked\n";
				break;
			case 2:
				cout << "\npaper picked\n";
				break;
			case 3:
				cout << "\nscissors picked\n";
				break;
			default:
				cout << "\ninvalid input\n";
				cin.clear();
				cin.ignore();
				inputFlag = true;
			}
		}
		
		//displays computer pick
		switch(compChoice){
		case 1:
			cout << "The computer picked rock\n";
			break;
		case 2:
			cout << "The computer picked paper\n";
			break;
		case 3:
			cout << "The computer picked scissors\n";
			break;
		default:
			cout << "Error\n";
		}

		//prints out if you won or lost
		int result = gameResult(choice, compChoice);
		switch(result){
		case 0:
			cout << "you won!\n";
			break;
		case 1:
			cout << "you lost!\n";
			break;
		case -1:
			cout << "draw!\n";
			playing = true;
			break;
		default:
			cout << "Error\n" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}

void computerChoice(int &compChoice){
	srand((unsigned int)time(NULL));
	//random range from 1 - 3
	compChoice = rand() % 3 + 1;	
	return;
}

//returns 0 if you won, 1 if you lost, and -1 if draw
int gameResult(int &playerChoice, int  &compChoice){
	if((playerChoice == 1 && compChoice == 3) || (playerChoice == 2 && compChoice == 1) || (playerChoice == 3 && compChoice == 2)){
		return 0;
	}else if((compChoice == 1 && playerChoice == 3) || (compChoice == 2 && playerChoice == 1) || (compChoice == 3 && playerChoice == 2)){
		return 1;
	}
	return -1;
}