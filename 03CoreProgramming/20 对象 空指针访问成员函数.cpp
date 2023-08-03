#include"head.h"

/*
* C++允许：空指针调用成员函数，但要注意成员函数有没有用到this指针
* 
* 如果用到this指针，需要加判断语句，以增强代码鲁棒性
*/

class Person20 {

public:
	// 没有用到this指针
	void showClassName() {
		cout << " This is Person class" << endl;
	}

	// 用到了this指针，即this->m_Age（c++默认的在属性前加了this指针），而this指针为NULL
	void showPersonAge() {
		if (this == NULL) return;		// 提高代码健壮性，防止空指针出现
		cout << " The age of person is " << m_Age << endl;
	}

	int m_Age;

};

int main20() {

	Person20* p = NULL;

	p->showClassName();

	p->showPersonAge(); // error

	system("pause");
	return 0;
}