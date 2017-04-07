#include<iostream>

using namespace std;

int power(int base, int pow, int result);

//takes in a base and raises it to a power, returns the result using recursion
int main(){
	int base = 5;
	int pow = 4;
	int result = 1;

	//5^4 should print out 625
	cout << power(base, pow, result) << endl;
	system("pause");
	return 0;
}

int power(int base, int pow, int result){
	if(pow > 0){
		pow--;
		result *= base;
		return power(base, pow, result);
	}else{
		return result;
	}
}