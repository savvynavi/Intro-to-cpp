#include<iostream>
#include<vector>
using namespace std;

bool guess(int pcGuess);
void lowHigh(int pcGuess, int &lowPoint, int &highPoint);

//will guess what number you're thinking of between 1-100 using a binary search
int main(){
	vector<int> range;
	for(int i = 0; i < 100; i++){
		range.push_back(i + 1);
	}

	//storing low and high points of search
	int low = range.front();
	int high = range.back();
	
	cout << "please think of a number between " << low << " and " << high << endl;
	bool correctGuess = false;
	//will average the highest and lowest point, if correct guess will break loop and end game, if incorrect will then ask if too high or low and change either the low or high point
	while(correctGuess == false){
		int pointer = (low + high) / 2;
		if(guess(pointer) == true){
			cout << "\nI guessed your number, which was " << pointer << "!\n";
			correctGuess = true;
		}else{
			lowHigh(pointer, low, high);
		}
	}

	system("pause");
	return 0;
}

//prints out it's current guess, returns true if you say it's correct, false otherwise
bool guess(int pcGuess){
	int input;
	bool badInput = false;
	do{
		cout << "\nIs your number " << pcGuess << "? [1]yes, [2]no: ";
		cin >> input;
		switch(input){
		case 1:
			return true;
		case 2:
			return false;
		default:
			cout << "\nERROR bad input\n";
			cin.clear();
			cin.ignore();
			break;
		}
	}while(badInput == false);
}

//takes user input on if the guess was too high/low, will change the high point to the current guess if too high, low point if too low
void lowHigh(int pcGuess, int &lowPoint, int &highPoint){
	int input;
	bool badInput = false;
	do{
		cout << "\nWas your number lower or higher? [1]Lower, [2]Higher: ";
		cin >> input;
		switch(input){
		case 1:
			highPoint = pcGuess;
			badInput = false;
			break;
		case 2:
			lowPoint = pcGuess;
			badInput = false;
			break;
		default:
			cout << "\nERROR bad input\n";
			cin.clear();
			cin.ignore();
			badInput = true;
			break;
		}
	}while(badInput == true);
}