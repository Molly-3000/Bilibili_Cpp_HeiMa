#include"head.h"
/*
* 函数模板
* 
* 注意事项：
*		1、自动类型推导时，必须能推导出一致的数据类型T
*		2、模板必须要确定出T的数据类型，才能使用
*/

template<class T>	// typename可以替换为class
void swapT2(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// 1、推导出的T数据类型必须一致
static void test01() {
	int a = 10;
	int b = 20;
	float bf = 20.f;

	swapT2(a, b);
	//swapT2(a, bf);	// error,没有与参数列表（int,float）匹配的函数模板T2
}

// 2、必须确定T的数据类型
template<class T>
void func() {
	cout << "template func()" << endl;
}

static void test02() {
	//func(); // error,没有与参数列表匹配的函数模板T2
			  // 即没法自动推导出T的类型
	func<int>();	// 必须指定T的类型	
	func<float>();
	func<string>();
}

int main03() {
	test01();
	test02();
	return 0;
}