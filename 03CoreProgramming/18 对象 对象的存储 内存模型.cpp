#include"head.h"

/*
* 成员变量 和 成员函数 是 分开存储的
*/

class Person18 {

	int m_A;		// 非静态成员变量，属于类的对象

	static int m_B; // 静态成员变量，不属于类的对象，共享一份，存储在static区

	void func() {}	// 非静态成员函数，不属于对象，共享一份，存储在

	static void func2() {}	// 静态成员函数，不属于对象，

};

int Person18::m_B = 0;

static void test01() {
	Person18 p;
	
	// ！！！空对象占用的内存空间为：1
	// 
	// c++编译器会给么个空对象也分配一个字节的空间，为了区分空对象占用内存的位置
	// 
	// （每个空对象也应该有一个独一无二的内存地址
	cout << "The size of p = " << sizeof(p) << endl;
}

static void test02() {
	Person18 p;
	cout << "The size of p = " << sizeof(p) << endl;
}


int main18() {

	test02();

	system("pause");
	return 0;
}