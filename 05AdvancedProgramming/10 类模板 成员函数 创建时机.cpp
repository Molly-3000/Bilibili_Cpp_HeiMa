#include"head.h"
#include<string>
/*
* 类模板 vs 普通类
* 
* 成员函数 创建时机 的区别：
* 
*	·普通类中，成员函数一开始就可以创建
* 
*	·类模板中，成员函数在调用时才创建
*						 ~~~~~~
*/

class Person10_a {
public:
	void show_a() {
		cout << "Normal class A function." << endl;
	}
};

class Person10_b {
public:
	void show_b() {
		cout << "Normal class B function." << endl;
	}
};

template<class T>
class Person10 {
public:
	T obj;
	void show1() {
		obj.show_a();	// show_a()和show_b()不是同一个类的函数
	}
	void show2() {
		obj.show_b();	// 但可以通过编译,因为类模板中，成员函数在调用时才创建
	}
};

static void test() {
	Person10<Person10_a> pa;
	pa.show1();			// 调用时，类模板中的成员函数才创建
	//pa.show2();		// err,show_b()不是Person_a的成员
}

int main10() {
	test();
	return 0;
}
