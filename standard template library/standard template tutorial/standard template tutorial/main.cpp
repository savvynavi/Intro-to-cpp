#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

//STL Iterators - linked list p sure
int main(){

	vector<int> vectorOfInts;
	vectorOfInts.push_back(5);
	vectorOfInts.push_back(2);
	vectorOfInts.push_back(10);

	typedef vector<int>::iterator IntVectorIterator;
	IntVectorIterator it = vectorOfInts.begin();

	//iValue will equal 5(points to element 0), then sets element 0 to 12
	int iValue = (*it);
	(*it) = 12;

	//now it points to the 3rd element
	it = vectorOfInts.begin();
	it = it + 2;

	for(it = vectorOfInts.begin(); it != vectorOfInts.end(); ++it){
		cout << (*it) << endl;
	}

	system("pause");
	return 0;
}