#include"head.h"

// 继承中 同名静态成员的处理方式 
// 1、通过对象访问：与 同名非静态成员 一致
// 2、通过类名访问

class Base34 {
public: 
	static int m_A;
	static void func() {
		cout << "Base func()" << endl;
	}
	static void func(int num) {
		cout << "Base func(int)" << endl;
	}
};

int Base34::m_A = 0;	// 静态成员 类内声明，类外初始化

class Son34 : public Base34{
public:
	static int m_A;
	static void func() {
		cout << "Son func()" << endl;
	}
};

int Son34::m_A = 1;

// 同名静态成员属性
static void test01() {
	Son34 son;

	// 1、通过对象访问
	cout << "Son::m_A = " << son.m_A << endl;
	cout << "Base::m_A = " << son.Base34::m_A << endl;

	// 2、通过类名访问
	cout << "Son::m_A = " << Son34::m_A<< endl;
	cout << "Base::m_A = " << Base34::m_A << endl;
	// 第一个::表示通过Son类名访问
	// 第二个::表示Base34作用域
	cout << "Base::m_A = " << Son34::Base34::m_A << endl;
}

// 同名静态成员函数
static void test02() {
	Son34 son;

	// 1、通过对象访问
	son.func();
	son.Base34::func();

	// 2、通过类名访问
	Son34::func();
	Base34::func();
	Son34::Base34::func();

	// 子类同名会隐藏所有父类同名，包括重载
	Son34::Base34::func(1);
}

int main34() {

	test01();

	system("pause");
	return 0;
}