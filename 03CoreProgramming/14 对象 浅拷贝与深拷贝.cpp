#include"head.h"

/*
* 浅拷贝 vs 深拷贝
* 
* 浅拷贝：简单的数值拷贝。编译器提供的拷贝构造就是浅拷贝。
* 
* 深拷贝：在堆区开辟新的内存空间，进行拷贝操作。
* 
* 浅拷贝的问题：堆区的内存重复释放
* 
*/

class Person14 {
public:
	Person14(){
		cout << "This is default constructor." << endl;
	}

	Person14(int _age, int _height) {
		age = _age;
		height = new int(_height);
		cout << "This is parameter constructor." << endl;
	}

	// 编译器提供的拷贝构造函数be like:
	// 
	//Person14(const Person14& p) {
	//	age = p.age;
	//	height = p.height;		// shadow copy
	//	cout << "This is shadow copy constructor." << endl;
	//}

	Person14(const Person14& p) {
		age = p.age;
		height = new int(*p.height);	// deep copy
		cout << "This is deep copy constructor." << endl;
	}

	~Person14() {
		// 析构函数，可以在释放对象时，释放堆区开辟的空间
		if (height != NULL) {
			delete height;
			height = NULL;		// 置空，以避免野指针
		}
		cout << "This is deconstructor." << endl;
	}
	int age;
	int* height;
};

static void test01() {
	Person14 p1(18,165);
	cout << "The height of person1 is " << *p1.height << endl;
	Person14 p2 = p1;
	cout << "The height of person2 is " << *p2.height << endl;

	// p1 p2 都是栈区对象（指针）,先进后出
	// 当 test01()退出时，先释放p2，后释放p1
	// p1 执行deconstructor 释放指针
	// if shadow copy：
	//		p2 执行deconstructor释放指针，重复释放，所以报错
	// else deep copy:
	//		p2 执行deconstructor释放指针，释放与p1不同的内存
	//
}

int main14() {

	test01();

	system("pause");
	return 0;
}