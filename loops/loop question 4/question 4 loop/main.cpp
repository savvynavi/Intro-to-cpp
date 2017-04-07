#include<iostream>

using namespace std;

//loops through 0-1000, adds all multiples of 3 and 5 together, prints result, but uses a whiile loop
int main(){
	int sum = 0;
	int i = 0;
	while (i < 1000){
		if (i%3 == 0){
			sum += i;
		}else if(i%5 == 0){
			sum += i;
		}
		i++;
	}

	cout << "The sum is " << sum << endl;
	system("pause");
	return 0;
}