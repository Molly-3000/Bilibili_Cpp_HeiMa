#include"head.h"
#include<string>
/*
* 类模板与继承
* 
* 1、当子类继承的父类是类模板时，子类声明的时候，需要指定出父类的 T
*		如果不指定，编译器无法给子类分配内存
* 
* 2、如果想灵活指定父类中 T 的类型，子类也需要变成类模板
*/

template<class T>
class Base12 {
public:
	Base12() {
		cout << "This is Base12." << endl;
		cout << "The type of T in Base12 is :" << endl;
		cout << typeid(T).name() << endl;
	}
	T m;
};

// 1、子类不是类模板，则需要指定父类的T
class Son12_ :public Base12<int> {
public:
	Son12_() {
		cout << "This is Son2_, not a template." << endl;
	}
};

// 2、子类也是类模板，不需要指定父类的T
template<class T,class T2>
class Son12 :public Base12<T> {	//T属于父类模板
public:
	Son12() {
		cout << "This is Son12, a template." << endl;
		cout << "Type of T in Son12 is :" << endl;
		cout << typeid(T2).name() << endl;
	}
	T2 t;	// T2 属于子类模板
};

static void test() {
	Son12_ son1;
	Son12<int,string> son2;
}

int main12() {
	test();
	return 0;
}
