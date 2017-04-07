#include<iostream>

using namespace std;

float smallerFloat(float &num1, float &num2 );
float smallerFloat(float &num1, float &num2, float &num3);

//takes in 2 or 3 floats, prints the smaller one
int main(){
	cout << "how many integers do you want to enter? 2 or 3: ";
	int numOfInt;
	float a, b, c;
	bool input = true;
	//checks to make sure if input is valid
	while (input){
		input = false;
		cin >> numOfInt;
		switch (numOfInt){
		case 2:
			cout << "\nEnter 2 floats: ";
			cin >> a >> b;
			cout << "\nThe smaller float is " << smallerFloat(a, b) << endl;
			break;
		case 3:
			cout << "\nEnter 3 floats: ";
			cin >> a >> b >> c;
			cout << "\nThe smaller float is " << smallerFloat(a, b, c) << endl;
			break;
		default:
			cout << "\ninvalid input\n";
			input = true;
			break;
		}
	}

	system("pause");
	return 0;
}

float smallerFloat(float &num1, float &num2){
	if (num1 < num2){
		return num1;
	}else{
		return num2;
	}
}

float smallerFloat(float &num1, float &num2, float &num3){
	float tmp = smallerFloat(num1, num2);
	if (tmp < num3){
		return tmp;
	}else{
		return num3;
	}
}