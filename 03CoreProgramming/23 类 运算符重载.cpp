#include"head.h"

/*
* 运算符重载
* 
* 作用：对已有的运算符进行重新定义，赋予另一种功能，以适应不同的数据类型
* 
* 语法：数据类型 operator运算符 (参数列表) {}
* 
* 注意：成员函数进行运算符重载 和 通过全局函数进行重载
*		1.函数参数写法不同
*		2.调用方式相同，但本质不同
* 
* 1、内置数据类型 的 运算符计算 不能重载
* 2、不要滥用运算符重载
*  
*/

class Person23 {
public:
	int m_A;
	int m_B;

	//Person23 operator+ (Person23& p);	// 通过成员函数重载+

};
//
//// 通过成员函数重载+
//Person23 Person23::operator+(Person23& p) {
//	Person23 per;
//	per.m_A = this->m_A + p.m_A;
//	per.m_B = this->m_B + p.m_B;
//	return per;
//}

// 通过全局函数重载+
Person23 operator+ (Person23& p1, Person23& p2) {
	Person23 per;
	per.m_A = p1.m_A + p2.m_A;
	per.m_B = p1.m_B + p2.m_B;
	return per;
}

// 运算符重载 的 函数重载
Person23 operator+ (Person23& p1, int num) {
	Person23 per;
	per.m_A = p1.m_A + num;
	per.m_B = p1.m_B + num;
	return per;
}

static void test01() {
	Person23 p1, p2, p3, p4;
	p1.m_A = 10;
	p1.m_B = 20;
	p2.m_A = 20;
	p2.m_B = 10;

	p3 = p1 + p2;
	//p4 = p1.operator+(p2);	// 通过成员函数重载，调用的本质

	p4 = operator+(p1, p2);

	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
	cout << "p4.m_A = " << p4.m_A << endl;
	cout << "p4.m_B = " << p4.m_B << endl;

	Person23 p5 = p1 + 10;
	cout << "p5.m_A = " << p5.m_A << endl;
	cout << "p5.m_B = " << p5.m_B << endl;

}

int main23() {

	test01();

	system("pause");
	return 0;
}