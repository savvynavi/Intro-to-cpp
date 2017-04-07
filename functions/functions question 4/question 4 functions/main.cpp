#include<iostream>

using namespace std;

float Half(float &num);

//uses function to halve a hard set float
int main(){
	float number = 16.721f;
	float result = Half(number);

	cout << "half number: " << result << endl;
	system("pause");
	return 0;
}

float Half(float &num){
	num = num / 2;
	return num;
}