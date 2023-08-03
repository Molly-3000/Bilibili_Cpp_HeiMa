#include"head.h"

/*
* 常函数：const修饰的成员函数
* 
*	特点：const修饰的成员函数，不能修改成员变量
*			如果想要常含数可以修改成员变量，需要用mutable关键字修饰成员变量
* 
* 常对象：const修饰的对象
*	
*	特点：1.常对象，不允许修改成员变量
*			如果想要常含数可以修改成员变量，需要用mutable关键字修饰成员变量
* 
*		  2.常对象，只能调用常函数，（为了防止非常函数修改成员变量）
*/

class Person21 {
public:
	// this指针的本质是const pointer，指针的指向不变
	// 常含数的本质就是const pointer to const,this指针指向的值也不变
	void showPerson() const {
		//m_A = 100;	// 等价于 this->m_A = 100;
		m_B = 100;
	}

	void func() {
	}

	int m_A;			// 常含数不可修改
	mutable int m_B;	// 常含数可以修改
};

static void test01() {
	Person21 p;
	p.showPerson();
}

static void test02() {
	const Person21 p;
	//p.func();	// error，常对象不能调用非常函数
	p.showPerson();
}

int main21() {

	test01();

	test02();

	system("pause");
	return 0;
}