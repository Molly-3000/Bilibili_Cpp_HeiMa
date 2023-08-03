#include"head.h"
/*
* 函数template
* 
* 定义：建立一个通用函数，使其返回值类型和参数类型不固定
*							  ~~~~~~~~~~  ~~~~~~~~
*							用一个虚拟的类型来表示
* 语法：template<typename T>
*		T funcname(T param1,...){}
* 
* 使用（两种）：1、自动类型推导
*				2、显式指定类型
* 
*/

// 函数模板 声明
template<typename T>	// 声明一个模板，告诉编译器后面紧跟的代码中T不要报错，代表一个通用的数据类型
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// 函数模板 使用
static void test() {
	int a = 10;
	int b = 20;

	// 1、自动类型推导
	mySwap(a, b);

	// 2、显示指定类型
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

// 交换两个整形
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// 交换两个浮点型
void swapFloat(float& a, float& b) {
	float temp = a;
	a = b;
	b = temp;
}

static void test01() {
	int a = 10;
	int b = 20;

	swapInt(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	float af = 10.0f;
	float bf = 20.0f;

	swapFloat(af, bf);
	cout << "af = " << af << endl;
	cout << "bf = " << bf << endl;
}

int main02() {
	test();
	return 0;
}