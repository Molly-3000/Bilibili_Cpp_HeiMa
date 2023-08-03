#include"head.h"

/*
* 静态成员变量及静态成员函数
* 
* static成员变量：
*	·所有对象共享同一份	（不属于某个对象，可以通过类名，即作用域，访问）
*	·在编译阶段分配内存	（静态变量，存储在静态全局区）
*	·在类内声明，类外初始化
* 
* static成员函数：
*	·所有对象共享同一份
*	·只能访问static成员变量（因为没有this指针，而非静态变量是this->的）
* 
*/

class Person17 {

public:
	static int m_A;		// 类内声明
	int m_B;			

	static void func1() {
		m_A *= 2;		// static成员函数 只能访问 static成员变量
		//m_B *= 2;		// error
	}

	// 可以通过传参的方式，传入 非static（成员）变量，但无法修改（因为没有访问权限）
	static void func3(int m_B) {
		cout << "static with non-static paramter." << endl;
	}

private:
	static int func2() { return 0; }
};

int Person17::m_A = 99;	// 类外初始化

static void test01() {
	Person17 p1,p2;
	cout << p1.m_A << endl;

	p2.m_A = 100;
	cout << p1.m_A << endl;	// 共享数据

	cout << Person17::m_A << endl;
}

static void test02() {
	Person17 p;
	p.m_A = 2;
	cout << p.m_A << endl;

	p.func1();
	cout << p.m_A << endl;

	Person17::func1();
	cout << p.m_A << endl;

	//Person17::func2();  // error, private成员函数 不可访问
	
	Person17::func3(1);

}

int main17() {

	test01();

	system("cls");

	test02();

	system("pause");
	return 0;
}