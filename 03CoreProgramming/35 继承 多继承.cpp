#include"head.h"

/*
* 多继承：一个子类可以继承多个父类
* 
* 语法：
*		class 子类 : 继承方式 父类1, 继承方式 父类2,... {} 
* 
* 注意：不建议使用多继承，因为父类之间容易出现同名成员，
* 									还需要加作用域以区分
* 
*/

class Base35_1 {
public:
	Base35_1() {
		m_A = 100;
	}
	int m_A;
};

class Base35_2 {
public:
	Base35_2() {
		m_B = 200;
	}
	int m_B;
};

class Son35 :public Base35_1, public Base35_2 {
public:
	Son35() {
		m_C = 300;
		m_D = 400;
	}
	int m_C, m_D;
};

static void test01() {
	Son35 son;
	cout << "sizeof son = " << sizeof(Son35) << endl;
}

int main35() {

	test01();

	system("pause");
	return 0;
}