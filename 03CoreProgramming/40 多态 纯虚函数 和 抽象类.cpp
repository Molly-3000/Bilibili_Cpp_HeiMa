#include "head.h"

/*
* 多态 基类往往是抽象类
* 
* 纯虚函数和抽象类
* 
* 纯虚函数：没有实现的虚函数
*	语法： virtual 返回类型 函数名 (参数列表) = 0;
* 
* 抽象类：包含纯虚函数的类
*	特点：
*		·无法实例化对象
*		·子类必须 重写 抽象类中的 所有纯虚函数
*/

// 抽象类
// 定义：只要包含纯虚函数，就是抽象类
// 特点：1、无法实例化
//		 2、子类必须重写 父类中的纯虚函数
class Base40 {
public:
	virtual void func() = 0;		// 纯虚函数
};


class Son40:public Base40 {
public:
	// 抽象类的派生类，必须重写父类中的纯虚函数
	void func() {
		cout << "This is Son::func()." << endl;
	}
	static int m_static;
};

int Son40::m_static = 0;

static void test01() {
	
	//Base40 base;		// error，纯虚函数无法实例化

	Son40 son;
	son.func();

	//son.m_static = 1;
	//cout << "get the static member via an object." << endl;
	//Son40::m_static = 2;
	//cout << "get the static member via the class." << endl;
}

int main40() {

	test01();

	system("pause");
	return 0;
}