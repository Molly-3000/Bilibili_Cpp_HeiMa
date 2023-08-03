#include"14 class template head.hpp"

template<class T1, class T2>
Person14<T1, T2>::Person14(T1 name, T2 age) {
	this->m_name = name;
	this->m_age = age;
}

template<class T1, class T2>
void Person14<T1, T2>::showInfo() {
	cout << "The age of " << this->m_name << " is " << this->m_age << endl;
}