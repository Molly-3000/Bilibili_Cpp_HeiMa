#include<iostream>
using namespace std;

int main17() {

	// 1、前置递增
	int a = 0;
	++a;
	cout << "a = " << a << endl;

	// 2、后置递增
	int b = 10;
	b++;
	cout << "b = " << b << endl;

	// 3、前置后置的区别
	// 前置: 先让变量加1，再进行表达式运算
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << "a2 = " << a2 << endl;
	cout << "b2 = " << b2 << endl;

	// 后置: 先进行表达式运算，再进行变量+1
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << "a3 = " << a3 << endl;
	cout << "b3 = " << b3 << endl;

	system("pause");

	return 0;

}