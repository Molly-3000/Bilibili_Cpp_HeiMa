#include"head.h"

/*
* 拷贝构造 的 调用时机
*		三种情况：
*				·使用 一个已经创建完毕的对象 来 初始化一个新对象
*				·以 值传递 的方式给函数 参数传值
*				·以 值返回 的方式 返回局部对象
* 
*/

class Person12 {
	int age;
public:
	Person12(){
		cout << " This is default constructor. " << endl;
	}
	Person12(int a) {
		age = a; 
		cout << " This is a parameter constructor." << endl;
	}
	Person12(const Person12& p) {
		age = p.age; 
		cout << " This is a copy constructor." << endl;
	}

	~Person12() {
		cout << " This is deconstructor." << endl;
	}
};

// 通过 static 让函数仅在 当前cpp 可使用
// 1、用 一个已经创建完毕的对象 来初始化 一个新对象
static void test01() {
	Person12 p1(10);
	Person12 p2(p1);
	Person12 p3 = Person12(p2);
	Person12 p4 = p3;
}

// 2、用 值传递 的方式给 函数传参
//		 值传递的本质是 创建一个临时的副本，对于类对象来说，就是拷贝构造
void doCopyForFunc(Person12 p){}
static void test02() {
	Person12 p;
	doCopyForFunc(p);
}

// 3、用 值返回 返回 局部对象
//		 值返回的本质是 也是创建一个临时的副本，对于类对象来说，就是拷贝构造
Person12 doCopyForReturn() {
	Person12 p;	// 局部对象，并不会返回
	cout << (int*)&p << endl;
	return p;
}
static void test03() {
	//doCopyForReturn();
	//Person12 p = doCopyForReturn();
	//cout << (int*)&p << endl;
	Person12 p2(doCopyForReturn());
}

int main12() {

	//test01();
	//test02();
	test03();

	system("pause");
	return 0;
}