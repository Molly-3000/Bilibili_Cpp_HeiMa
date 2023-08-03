#include"head.h"
#include<string>
/*
* 类模板对象 做函数参数
* 
* 由类模板实例化出的对象，可以作为函数参数
* 
* 三种传输方式：
*		1、指定传入类型		直接指定对象的数据类型
*		2、参数模板化		将对象中的参数 变为模板进行传递
*		3、整个类模板化		将这个对象类型 模板化进行传递
* 
*		第一种最常用
* 
* P.S. 显示类型推导的函数： typeid(para).name();
*/

template<class NameType,class AgeType = int>
class Person11 {
public:
	Person11(NameType name, AgeType age) :m_name(name), m_age(age) {}
	void show() {
		cout << this->m_name << " is " << this->m_age << endl;
	}
	NameType m_name;
	AgeType m_age;
};

// 1、指定传入的类型	直接显示对象的数据类型
static void show1(Person11<string,int> &p) {
	cout << "This is show 1." << endl;
	p.show();
}

// 2、参数模板化		将对象中的参数 变为模板进行传递
template<class T>
void show2(Person11<T> &p) {
	cout << "This is show 2." << endl;
	p.show();
	cout << "type inference of T: " << typeid(T).name() << endl;
}

// 3、整个类模板化		将这个对象类型 模板化进行传递
template<class T>
void show3(T &p) {
	cout << "This is show 3." << endl;
	p.show();
	cout << "type inference of T: " << typeid(T).name() << endl;
}

static void test() {
	Person11<string> p("zhangsan", 18);

	show1(p);	// 此时显示类型指定

	show2(p);	// 此时自动推导 T 为 string

	show3(p);	// 此时自动推导 T 为 Person<string,int>
}

int main11() {
	test();
	return 0;
}