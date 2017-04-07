#include<iostream>
using namespace std;

int main(){
	const int size = 11;
	char testDate[size] = "19/05/1995";
	char letter = '/';
	char newArr[size];
	char userDay[3];
	const char *months[13] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char userMonth[3];
	/*char userYear[5];
	for(int i = 0; i < size; i++){
		if(testDate[i] != letter && testDate[i] != '\0'){
			
		}
	}
	

	for(int i = 0; i < 2; i++){
		userDay[i] = testDate[i];
	}
	cout << userDay << endl;*/

	for(int i = 3; i < 5; i++){
		userMonth[i] = testDate[i];
	}
	cout << userMonth << endl;
	system("pause");
	return 0;
}