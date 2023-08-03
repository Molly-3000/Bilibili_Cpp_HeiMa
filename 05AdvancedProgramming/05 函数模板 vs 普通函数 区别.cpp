#include"head.h"

/*
* 函数模板 和 普通函数 的区别
* 
* 1、普通函数调用时可以发生自动类型转换（隐式类型转换）
* 2、函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
* 3、函数模板调用时，如果利用显式类型指定，可以发生隐式类型转换
* 
*	类型指定 VS 类型推导 VS 类型转换
* 
* P.S. 建议使用函数模板时，显示指定类型
*/

// 1、普通函数，隐式类型转换
int myAdd01(int a, int b) {
	return a + b;
}
static void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';

	cout << myAdd01(a, b) << endl;
	cout << myAdd01(a, c) << endl;	// 字符c 转化为 其ASCII码
}

// 函数模板
template<typename T>
T addT(T a, T b) {
	return a + b;
}
static void test02() {
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << addT(a, b) << endl;
	// 2、自动类型推导时，不能隐式类型转换
	//cout << addT(a, c) << endl;  // error,没有与参数列表匹配的 函数模板 实例
	cout << addT(a, int(c)) << endl;
	
	// 3、显式指定类型时，可以隐式类型转换
	cout << addT<int>(a, c) << endl;
}

int main05() {
	test01();
	test02();
	
	return 0;
}