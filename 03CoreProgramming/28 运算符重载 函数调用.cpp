#include"head.h"

/*
* 函数调用运算符 重载
* 
* ()
* 
* 因为重载后的使用方式，非常像函数的调用，因此也称为 仿函数
* 
* 仿函数没有固定的写法，非常灵活
* 
* !!! 注意：运算符不能是静态成员函数，即重载不能用static修饰
*				   ~~~~~~~~~~~~~~~~~
*			（因为需要访问成员变量，默认传入this指针。如+、-等）
* 
*/

class MyPrint {
public:
	// 重载函数调用 运算符
	void operator() (string s) {
		cout << s << endl;
	}
	// 仿函数非常灵活，返回数据类型、参数列表没有固定写法
	int operator() (int a, int b) {
		return a + b;
	}

	//// ！！!报错，运算符不能是静态成员函数
	//static int operator() (int a) {}

};


static void test01() {
	MyPrint myPrint;
	myPrint("test");	// 重载函数调用运算符 的使用，用起来形式像函数调用
	cout << myPrint(1, 2) << endl;

	// 可以通过匿名对象调用
	cout << MyPrint()(11, 22) << endl;
	//// 不能通过类调用
	//cout << MyPrint.operator("error") << endl;
}


int main28() {

	test01();

	system("pause");
	return 0;
}