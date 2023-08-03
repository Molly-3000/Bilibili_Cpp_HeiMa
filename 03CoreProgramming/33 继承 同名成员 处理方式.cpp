#include"head.h"

/*
* 当子类和父类 出现 同名成员时
* 
* ·子类成员(属性/函数)，可直接访问
* ·父类成员(属性/函数)，需要加作用域 
* 
* 注意：
*		如果子类中出现和父类同名的成员函数，
*			子类的成员函数会隐藏掉父类中所有的同名成员函数（包括重载）
*				所以访问父类的同名函数（包括重载的），必须加作用域
*/

class Base33 {
public:
	Base33() { m_A = 1; }
	void func() { cout << " This is Base func()." << endl; }
	void func(int a) { cout << " This is Base override func(int a)." << endl; }
	int m_A;
};

class Son33 :public Base33 {
public:
	Son33() { m_A = 2; }
	void func() { cout << " This is Son func()." << endl; }
	int m_A;
};

static void test01() {
	Son33 son;
	cout << "Son m_A=" << son.m_A << endl;			// 子类成员，直接访问
	cout << "Base m_A=" << son.Base33::m_A << endl;	// 父类成员，加作用域
	son.func();
	son.Base33::func();

	//son.func(1);	// error，父类中的同名函数（包括重载），被子类隐藏，不能直接调用
	son.Base33::func(1);
}

int main33() {

	test01();

	system("pause");
	return 0;
}