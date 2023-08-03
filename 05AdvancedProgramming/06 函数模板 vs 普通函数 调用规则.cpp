#include "head.h"
/*
* 函数模板 与 普通函数 的调用规则
* 
* 1、如果函数模板和普通函数都可以调用，优先调用普通函数
* 2、可以通过空模板参数列表，强制调用函数模板
* 3、函数模板也可以重载
* 4、如果函数模板可以产生更好的匹配，优先调用函数模板
* 
* P.S.如果写了函数模板，最好就不要写同名的普通函数。
*/

void myPrint(int a, int b) {
	cout << "调用普通函数" << endl;
}

// 函数模板 重载
template<class T>
void myPrint(T a, T b) {
	cout << "函数模板" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "函数模板,重载" << endl;
}

static void test() {
	int a = 10;
	int b = 20;
	char ac = 'a';
	char bc = 'b';


	myPrint(a, b);	// 1、都可以调用，优先调用普通函数
					// 注意，如果普通函数只有声明没有实现，仍会调用普通函数
					//		编译时报错，无法解析的外部符号
	
	myPrint<>(a, b);	// 2、空模板参数列表，强制调用函数模板
	
	myPrint(a, b, 100);	// 3、函数模板 重载

	myPrint(ac, bc);	// 4、函数模板可以产生更好的匹配
						//		普通函数需要进行隐式类型转换char->int
						//		函数模板 编译器可以自动推导出 T就是char 而不需要进行类型转换
}

int main06() {
	test();
	return 0;
}