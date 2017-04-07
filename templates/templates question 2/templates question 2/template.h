#ifndef TEMPLATE_H
#define TEMPLATE_H
#include<memory>
//How to initialise for an int: MyContainer<int> storage(10);

template<typename T>
class MyContainer{
public:
	MyContainer(int capacity){
		m_cap = cap;
		m_size = 0;
		m_arr = new T[m_cap];
		memset(m_arr, 0, sizeof(T) * m_arr);
	}
	~MyContainer(){
		delete[] m_arr;
	}

	//adding to array
	void add(T &item){
		if(m_size == m_cap){
			expand();
		}
		m_arr[m_size++] = item;
	}

	//expanding the array
	expand(){
		T *tmp = new T[m_cap * 2];
		memset(tmp, 0, sizeof(T) * m_cap * 2);
		for(i<m_cap){
			tmp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
		m_cap *= 2;
	}

	T &operator[](unsigned int index){
		return m_arr[index];
	}

private:
	int m_capacity
	int m_size;
	T m_arr[size];
};
#endif