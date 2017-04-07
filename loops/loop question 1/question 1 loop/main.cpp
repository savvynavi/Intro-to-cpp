#include<iostream>

using namespace std;

//counts down by 2 from 100 to 0
int main(){
	for (int i = 100; i >=0; i--) {
		if (i%2 == 0) {
			cout << i << endl;
		}
	}

	system("pause");
	return 0;
}