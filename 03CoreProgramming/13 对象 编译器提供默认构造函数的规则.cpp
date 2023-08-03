#include"head.h"

/*
* 默认情况下，c++编译器 至少给一个类添加 三个函数
*	1、默认构造函数（无参，函数体为空）
*   2、默认析构函数（无参，函数体为空）
*   3、默认拷贝构造函数，对属性进行拷贝
* 
* 
* 构造函数调用规则：
*	1、如果用户定义了 有参构造
*		   c++不再提供 默认无参构造， 但提供 默认拷贝构造
*	
*	2、如果用户定义了 拷贝构造
*		   c++不会再提供其他构造函数（即默认无参）
* 
*/

class Person13 {};

static void test01() {
	Person13 p1;		// 默认无参构造
	Person13 p2 = p1;	// 默认拷贝构造
	// 默认析构函数
}

class Person13_ {
	int age;
public:
	Person13_(int a) {
		age = a;
	}
};

static void test02() {
	// Person13_ p1;	// 报错 不参在默认构造函数，即C++编译器不再提供
	Person13_ p1(10);	// 自定义 有参构造
	Person13_ p2 = p1;	// C++编译器提供 默认拷贝构造
	// C++编译器提供 默认析构函数
}


class Person13_b {
public:
	Person13_b(const Person13_b &p) {}
	Person13_b() {}
};

static void test03() {
	Person13_b p1;	// 报错 不参在默认构造函数，即C++编译器不再提供，需要自定义
	Person13_b p2 = p1;
}

int main13() {

	test01();
	test02();
	test03();

	system("pause");
	return 0;
}