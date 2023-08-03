#include"head.h"

// 对象的 初始化 和 清理
// 
// 初始化->构造函数
//		在声明对象时，编译器自动调用，且只调用一次
// 语法：类名(){}
//		1、不写返回值类型，写return
//		2、函数名和类名相同
//		3、可以写参数，可以重载
// 
// 清理->析构函数
//		在对象销毁前，编译器自动调用，且只调用一次   // 这也是堆数组必须 delete[]的原因，每个对象要调用一次
// 语法：~类名(){}
//		1、不写返回值，不写return
//		2、函数名与类名相同，前面加~符号
//		3、不能写参数，不能重载
// 
// constructor 和 destructor 都是必须实现的
//		如果程序员没有实现，将由编译器提供一个空实现的函数
//


class Test1 {
public:
	Test1() { cout << "This is stack object constructor." << endl; }
	~Test1() { cout << "This is stack object dectructor." << endl; }
};

class Test2 {
public:
	Test2() { cout << "This is heap object constructor." << endl; }
	~Test2() { cout << "This is heap object dectructor." << endl; }
};

void heapTest() {
	Test2 heapT;  // 栈对象，在函数（也就是该局部变量的作用域）退出前，对象就会被销毁
}

int main10() {

	Test1 stackT;

	heapTest();

	system("pause");
	return 0;
}