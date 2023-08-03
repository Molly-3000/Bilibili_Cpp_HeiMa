#include"head.h"

/*
* 左移运算符重载
* 
* 作用：自定义输出类型
* 
*/

class Person24 {

	// 友元函数 以访问私有属性
	friend ostream& operator<< (ostream& cout, Person24& p);

private:
	int m_A = 10;
	int m_B = 20;

	// 利用成员函数 重载左移运算符
	// 通常不会这么重载<<，因为无法实现cout在左侧
	// 
	// cout 是标准输出流(ostream)对象，全局只能有一个
	// 输入流为(istream)
	// 返回类型为ostream&，即返回cout本身，为了链式编程
public:
	ostream& operator<< (ostream &cout) {	// cout 要传引用
		cout << "p.m_A=" << this->m_A << " " << endl;
		cout << "p.m_B=" << this->m_B << " " << endl;
		return cout;
	}

};

// 通过成员函数 重载<<，调用方式
// 本质是 p.operator<<(cout)
static void test0() {
	Person24 p;
	p << cout;
}

// 返回类型为ostream&，即返回cout本身，为了链式编程
ostream& operator<< (ostream &cout, Person24& p) {
	cout << "p.m_A=" << p.m_A << " " << endl;
	cout << "p.m_B=" << p.m_B << " " << endl;
	return cout;
}

// 只能利用全局函数 重载<<，调用时才能cout在左边
// 本质是 operator<<(cout,p)
static void test1() {
	Person24 p;
	cout << p << endl;
}

int main24() {

	test0();
	test1();

	system("pause");
	return 0;
}