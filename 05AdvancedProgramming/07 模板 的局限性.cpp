#include "head.h"
#include <string>
/*
* 模板 的局限性
* 
* 通用并不是万能的，有些特定数据类型，需要提供具体实现
*						~~~~~~~~~~~~          ~~~~~~~~
*			比如 内置数据类型 和 数组/自定义类型 的模板 往往不能通用
* 
* 通过具体化的模板，可以解决自定义类型的通用化
*	  ~~~~~~
* P.S.学习模板不是为了写模板，是为了会用STL中的模板
*/

class Person07 {
public:
	Person07(int age,string name):m_age(age),m_name(name) {}
	int m_age;
	string m_name;
};

template<class T>
bool myEqual(T& a, T& b) {
	return a == b;
}

//// 1、运算符重载
//bool operator== (Person07 &p1, Person07 &p2) {
//	return (p1.m_age == p2.m_age && p1.m_name == p2.m_name);
//}

// 2、利用具体化Person数据类型的函数模板，具体化优先调用
template<> bool myEqual(Person07 &p1, Person07 &p2) {
	return (p1.m_age == p2.m_age && p1.m_name == p2.m_name);
}


static void test01() {
	int a = 10;
	int b = 20;
	bool ret = myEqual(a, b);
	if (ret) cout << "a = b" << endl;
	else cout << "a != b" << endl;
}

static void test02() {
	Person07 p1(10, "Tom");
	Person07 p2 = Person07(12, "Tom");
	p2 = p1;
	bool ret = myEqual(p1, p2);			// 如果不具体化模板，运行时报错
	if (ret) cout << "p1 = p2" << endl;
	else cout << "p1 != p2" << endl;
}

int main07() {
	test01();
	test02();
	return 0;
}