#include<iostream>
using namespace std;

typedef double(*simpleCalculator)(float leftNum, float rightNum);
simpleCalculator checkOperation(char operation);

//using pointer functions, takes in user input for the operation and 2 numbers, and depending on the op will do a different math function and print the result
int main(){
	bool input = true;
	char op;
	float x, y;
	while(input == true){
		input = false;
		cout << "please enter either a +, -, /, * or ^: ";
		cin >> op;
		if(op == '+' || op == '-' || op == '/' || op == '*' || op == '^'){
			bool numberInput = true;
			while(numberInput == true){
				numberInput = false;
				cout << "please enter 2 numbers, in the order you wish to do the operation on them: ";
				cin >> x >> y;
				if(cin.fail() == false){
					cout << "the solution is: " << x << op << y << " = " << checkOperation(op)(x, y) << endl;
				}
				else{
					cout << "\nInvalid input\n";
					cin.clear();
					cin.ignore();
					numberInput = true;
				}
			}
		}else{
					cout << "\nInvalid input\n";
					cin.clear();
					cin.ignore();
					input = true;
				}
			}

	system("pause");
	return 0;
}

double add(float leftNum, float rightNum){
	return (leftNum + rightNum);
}

double sub(float leftNum, float rightNum){
	return (leftNum - rightNum);
}

double divide(float leftNum, float rightNum){
	return (leftNum / rightNum);
}

double multiply(float leftNum, float rightNum){
	return (leftNum * rightNum);
}

double power(float leftNum, float rightNum){
	float result = 1;
	for(int i = 0; i < rightNum; i++){
		result *= leftNum;
	}
	return result;
}

//eg root(25,2) outputs 2r25 = 5, or root(81,3) outputs 3r81 = 4.3267
/*double root(float leftNum, float rightNum){
	float result = leftNum;
	for(float i = rightNum; i > 0; i--){
		result *= (1/rightNum);
	}
	return result;
}*/

simpleCalculator checkOperation(char operation){
	switch(operation){
	case '+':
		return &add;
	case '-':
		return &sub;
	case '/':
		return &divide;
	case '*':
		return &multiply;
	case '^':
		return &power;
	default:
		return nullptr;
	}
}