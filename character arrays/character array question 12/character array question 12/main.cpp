#include<iostream>
using namespace std;

char charCount(char[]);

int main(){
	cout << "Enter a word/series of words: ";
	const int size = 100;
	char input[size];
	cin.getline(input, size);
	if(strlen(input) < 2){
		cout << "\nnot long enough, needs at least 2 letters\n";
	}else{
		cout << "the character that is repeated the most is: " << charCount(input) << endl;
	}
	system("pause");
	return 0;
}

//takes in a char array, returns the most used letter inside it
char charCount(char array1[]){
	int count = 0;
	int oldCount = 0;
	char letter;
	int size = strlen(array1);
	for(int i = 0; i < size - 1; i++){
		for(int k = i + 1; k < size - 1; k++){
			if((array1[i] == array1[k]) && ((array1[i] >=65 && array1[i] <= 90) || (array1[i] >= 97 && array1[i] <= 122))){
				++count;
			}
		}
		if(count >= oldCount){
			letter = array1[i];
			oldCount = count;
			count = 0;
		}
	}
	return letter;
}