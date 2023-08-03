#include"head.h"
/*
* STL 函数对象
* 
* 1、函数对象基本概念
* 
*		概念：重载 函数调用操作符() 的类，其对象 称为函数对象
*			  ~~~~ ~~~~~~~~~~~~~~~~
*			  函数对象使用重载的() 时，行为类似函数调用，故称为仿函数
*											~~~~~~~~~~~			~~~~~
*		本质：函数对象（仿函数）是一个类的对象，不是一个函数
*										  ~~~~
* 2、函数对象使用
* 
*		特点：函数对象在使用时，可以像普通函数那样调用，可以有参数、有返回值
*			  函数对象超出普通函数的概念，函数对象可以有自己的状态（成员属性）
*			  函数对象可以作为参数传递						  ~~~~
*						~~~~~~~~~~~~~~
*/

// 函数对象，可以有参数、返回值
class MyAdd {
public:
	int operator() (int v1, int v2) {
		return v1 + v2;
	}
};

static void test1() {

	cout << "1+2 = " << MyAdd()(1, 2) << endl;	// 匿名对象

	int v1 = 1;
	int v2 = 2;
	MyAdd myAdd;
	cout << "1+2 = " << myAdd(1, 2) << endl;

}

// 函数对象，可以有自己的状态
class MyMinus {
public:
	MyMinus(int v1, int v2):m_v1(v1),m_v2(v2),count(0) {}
	int operator() () {
		count++;
		return this->m_v1 - this->m_v2;

	}
	int operator() (int v1, int v2) {
		count++;
		return v1 - v2;
	}
	int m_v1;
	int m_v2;
	int count;
};

static void test2() {
	cout << "11-1 = " << MyMinus(11, 1)() << endl;

	MyMinus mySub(11, 1);
	cout << "11-1 = " << mySub() << endl;
	cout << "count: " << mySub.count << endl;

	MyMinus mySub2(11, 1);
	cout << "11-1-1-1 = " << mySub2(mySub2(mySub2(), 1),1) << endl;
	cout << "count: " << mySub2.count << endl;

}

// 函数对象，可以作为参数进行传递
class MyPrint55 {
public:
	void operator() (string s) {
		cout << s << endl;
		count++;
	}
	int count = 0;
};
static void doPrint(MyPrint55& printer, string s) {
	printer(s);
}

static void test3() {
	MyPrint55 printer;
	doPrint(printer, "hello");
	doPrint(printer, "hello");
	doPrint(printer, "hello");
	doPrint(printer, "hello");
	cout << "count: " << printer.count << endl;
}

int main55() {

	test1();
	test2();
	test3();
	return 0;
}