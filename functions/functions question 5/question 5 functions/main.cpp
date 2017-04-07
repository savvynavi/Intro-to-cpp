#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

bool CoinToss();

//gives result of cointoss
int main(){
	if (CoinToss()){
		cout << "Heads!\n";
	}else{
		cout << "Tails!\n";
	}
	system("pause");
	return 0;
}

bool CoinToss(){
	//makes new random seed for rand()
	srand(time(NULL));
	if (rand()%2 == 0){
		return true;
	}else{
		return false;
	}
}