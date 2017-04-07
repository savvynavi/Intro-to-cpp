#include<iostream>

using namespace std;

//loops through 0-1000, adds all multiples of 3 and 5 together, prints result
int main(){
	int sum = 0;
	for (int i = 0; i < 1000; i++){
		if (i%3 == 0){
			sum += i;
		}else if(i%5 == 0){
			sum += i;
		}
	}
	cout << "The sum is " << sum << "!\n";
	system("pause");
	return 0;
}