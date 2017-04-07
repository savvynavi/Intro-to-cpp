#include"template.h"

template<typename T, int size>
MyContainer<T, size>::MyContainer(){
	m_size = 3;
	m_arr = new T[m_size];
	memset(m_arr, 0, m_size);
}

template<typename T, int size>
MyContainer<T, size>::MyContainer(int size){
	m_size = size;
	m_arr = new T[m_size];
	memset(m_arr, 0, m_size);
}

template<typename T, int size>
MyContainer<T, size>::~MyContainer(){
	delete m_arr[];
}

template<typename T, int size>
void MyContainer<T, size>::add(T item){
	for(int i = 0; i < m_size; i++){
		if((i + 1) > size){
			expand(m_arr);
		}
		m_arr[i + 1] += m_arr[i];
	}
}

