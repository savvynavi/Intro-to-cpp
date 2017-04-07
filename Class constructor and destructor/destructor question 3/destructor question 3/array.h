#ifndef DYNAMARRAY_H
#define DYNAMARRAY_H

class DynamArr{
public:
	DynamArr(int numOfEntries);
	DynamArr(DynamArr &dynamArr);
	~DynamArr();

private:
	int m_numOfEntries;
	int *m_dynArr;
};
#endif