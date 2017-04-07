#include<iostream>
using namespace std;
//template function practice

//returns the minumum of 2 types
template<typename T>
T min(T a, T b){
	if(a <= b){
		return a;
	}else{
		return b;
	}
}

//returns the number alphabetically lower than the other
template<>
char min(char a, char b){
	//setting them to lowercase
	if(a >= 97){
		a = a - 32;
	}
	if(b >= 97){
		b = b - 32;
	}

	if(a <= b){
		return a;
	}else{
		return b;
	}
}

//returns the larger of the 2 types
template<typename T>
T max(T a, T b){
	if(a >= b){
		return a;
	}
	else{
		return b;
	}
}

//returns max character 
template<>
char max(char a, char b){
	//setting them to lowercase
	if(a >= 97){
		a = a - 32;
	}
	if(b >= 97){
		b = b - 32;
	}

	if(a >= b){
		return a;
	}
	else{
		return b;
	}
}

//returns a value between a and b
template<typename T>
T clamp(T a, T b){
	return((a + b) / 2);
}


int main(){

	char c = max('s', 'a');
	cout << "c = " << c << endl;
	system("pause");
	return 0;
}