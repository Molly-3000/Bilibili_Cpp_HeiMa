#include"head.h"

/*
* 对象成员：一个类的对象，作为另一个类的成员
*		！（互相引用时，其中一个对象成员必须为指针）
* 
*/

class A16{

public:
	A16() {
		cout << "This is A constructor" << endl;
	}
	~A16() {
		cout << "This is A deconstructor" << endl;
	}

};

class B16 {

	A16 a;	// 对象成员

	// 实例化时，将先创建A，后创建B
	// 释放时，将先释放B，后释放A

public:
	B16() {
		cout << "This is B constructor" << endl;
	}
	~B16() {
		cout << "This is B deconstructor" << endl;
	}
	 
};

class C16 {

};

static void test01() {
	B16 b;
}

int main16() {

	test01();

	system("pause");
	return 0;
}