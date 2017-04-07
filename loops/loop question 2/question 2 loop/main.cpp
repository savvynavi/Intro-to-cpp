#include<iostream>

using namespace std;

//if number between 0-100 is divisible by 3, prints fizz, by 5 prints buzz, if bot prints fizzbuzz. If neither it prints the number
int main(){
	for (int i = 0; i <= 100; i++){
		if (i%3 == 0 && i%5 != 0){
			cout << "Fizz\n";
		}else if(i%5 == 0 && i%3 != 0){
			cout << "Buzz\n";
		}
		else if (i % 3 == 0 && i%5 == 0){
			cout << "FizzBuzz\n";
		}else{
			cout << i << endl;
		}
	}

	system("pause");
	return 0;
}