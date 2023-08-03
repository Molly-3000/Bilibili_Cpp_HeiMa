#pragma once
#include<iostream>
using namespace std;

template<class T>
class myArray {
public:

	void push_back(const T& ele) {
		if (this->m_size < this->m_capacity) {
			this->pAddress[this->m_size] = ele;
			this->m_size++;
		}
		else cout << "Insert Fail. It's full." << endl;
	}

	void pop_back() {
		if (this->m_size == 0) {
			cout << "Pop Fail. It's empty." << endl;
		}
		this->m_size--;
	}

	int capacity() {
		return this->m_capacity;
	}

	int size() {
		return this->m_size;
	}

	T& operator[] (int index) {
		if (index >= this->m_capacity) {
			cout << "out of index" << endl;
		}
		return this->pAddress[index];
	}

	// operator= 注意返回类型为引用
	myArray& operator= (const myArray& arr) {
		// 如果堆区有数据，需要先释放
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = nullptr;
			this->capacity = 0;
			this->m_size = 0;
		}

		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;

		// 深拷贝
		this->pAddress = new T[this->m_capacity];
		for (int i = 0; i < arr.m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	myArray(int capacity) {
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[capacity];
	}

	// 拷贝构造
	myArray(const myArray& arr) {
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;

		// 深拷贝
		this->pAddress = new T[arr.m_capacity];
		
		for (int i = 0; i < this->m_size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}

	}


	~myArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = nullptr;
		}
		this->m_size = 0;
		this->m_capacity = 0;
	}

private:
	T* pAddress;		// 数组头
	int m_size;		// 数组当前元素个数
	int m_capacity;	// 容量
};