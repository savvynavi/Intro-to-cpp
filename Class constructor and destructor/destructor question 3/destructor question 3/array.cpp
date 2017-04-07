#include"array.h"

//Constructor
DynamArr::DynamArr(int numOfEntries){
	m_numOfEntries = numOfEntries;
	m_dynArr = new int[m_numOfEntries];
}

//Copy Constructor
DynamArr::DynamArr(DynamArr &dynamArr){
	m_dynArr = new int[m_numOfEntries];
	*m_dynArr = *dynamArr.m_dynArr;
}

//Destructor
DynamArr::~DynamArr(){
	delete[] m_dynArr;
}