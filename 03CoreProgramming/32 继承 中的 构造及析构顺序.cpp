#include"head.h"

/*
* 继承 中的 构造及析构顺序
* 
* 子类继承父类后，当创建子类对象时，也会调用父类的构造函数
* 
* 创建对象时，先父类构造，后子类构造
* 销毁对象时，析构顺序与构造顺序相反
* 
*/

class Base32 {
public:
	Base32() { cout << " This is the constructor form Base class." << endl; }
	~Base32() { cout << " This is the deconstructor form Base class." << endl; }
};

class Son32:public Base32 {
public:
	Son32() { cout << " This is the constructor form Son class." << endl; }
	~Son32() { cout << " This is the deconstructor form Son class." << endl; }
};

static void test01() {
	Son32 son;
}

int main32() {

	test01();
		
	system("pause");
	return 0;
}