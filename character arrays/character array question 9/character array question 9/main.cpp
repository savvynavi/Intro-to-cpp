#include<iostream>

using namespace std;

//takes input, says how many words there are in it
int main(){
	const int size = 50;
	char input[size];

	cout << "enter words: ";
	cin.getline(input, size);
	int count = 1;
	for(int i = 0; i < strlen(input); i++){
		if(input[i] == 32){
			count++;
		}
	}

	cout << "\nthere are " << count << " words in that phrase!\n";

	system("pause");
	return 0;
}