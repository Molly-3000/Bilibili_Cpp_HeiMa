#include"head.h"

// 
// 引用
// 
// 作用：给变量起别名，但操作的是同一块内存空间
//
// 本质：引用在c++内部实现就是一个常量指针（const pointer），即指针指向的地址空间不变
//			e.g.	int& ref = a; ref = 20;
//					int * const ref = &a; *ref = 20;	// 编译器内部转化
// 
//					
// 
// 语法：数据类型& 别名 = 原名;
// 
// 注意事项：1、引用必须初始化		（即 int &b;  //不合法
//					且指向合法的内存空间（stack 或 heap 或static）。
//			 2、引用创建后，不可更改（即 b = c;  //不合法，此时 = 是赋值
// 
// 用法：1、作为函数参数
//				特点：函数传参时，可以利用引用来让形参修饰实参
//				优点：简化指针，即不需要通过指针修改实参
//						*修饰：形参的改变影响实参
// 
//		 2、作为函数返回值
//				特点：·不要返回局部变量的引用
//					  ·函数的调用可以作为左值
//										   ^ ^
//		 3、常量引用
//				作用：用const修饰引用，防止形参改变实参
//						const int& ref = a;
//						const int * const ref = &a; // 编译器内部转化
//						此时 a = 10: 合法
//							 ref = 10; 不合法
// 
// 
// 

// 引用作为函数参数
void yinyongchuandi(int& b) { b = 100; }

void dizhichuandi(int* b) { *b = 0; }

void zhichuandi(int b) { b = 1; }


// 引用作为函数返回值
int& reflocal() {
	int a = 111;		// local变量存放在栈区，会被编译器自动释放
	return a;
}

int& refstatic() {
	static int a = 222;		// static变量存放在全局/静态区，程序结束时OS回收
	return a;
}

void constref(const int& ref) {
	//ref = 999;	// 报错 常量引用不能修改
	cout << "ref = " << ref << endl;
}

int main04() {

	int a = 10;
	int& b = a;

	b = 20;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	zhichuandi(a);				// 值传递，形参不修饰实参
	yinyongchuandi(a);			// 引用传递，形参修饰实参
	dizhichuandi(&a);			// 地址传递，形参修饰实参

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	int c = 30;
	
	b = c;				// 赋值操作，而不是修改引用
	//b = &c;			// 不合法，此时 & 是取址符号，引用无关
	b = (int &)c;		// 赋值操作，而不是修改引用
	
	c = 1000;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	cout << "================================" << endl;

	int& ref_local_a = reflocal();
	cout << "ref_local_a = " << ref_local_a << endl;	// 编译器做了一次保留，但不会一直保留
	cout << "ref_local_a = " << ref_local_a << endl;
	cout << "ref_local_a = " << ref_local_a << endl;

	int& ref_static_a = refstatic();
	cout << "ref_static_a = " << ref_static_a << endl;
	cout << "ref_static_a = " << ref_static_a << endl;
	cout << "ref_static_a = " << ref_static_a << endl;

	// 作为左值
	// 函数返回值a存放在栈区，是ref_static_a的别名
	int& ref_static_a_2 = refstatic();
	refstatic() = 333;	// 本质是 a = 333，也就是 ref_static_a = 333
	cout << "ref_static_a_2 = " << ref_static_a_2 << endl;
	cout << "ref_static_a_2 = " << ref_static_a_2 << endl;
	cout << "ref_static_a_2 = " << ref_static_a_2 << endl;

	cout << "================================" << endl;

	//int& ref = 10;		// 不合法

	const int& ref = 10;	//合法
	// 编译器将代码改为 int temp =10; const int& ref = temp;

	return 0;
}