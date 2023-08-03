#include"head.h"
#include<string>
/*
* 类模板 与 友元函数
* 
* 友元：不是类的成员，但可以访问类的私有、保护成员
* 
* 全局函数，类内实现：
*		全局函数直接在类内声明+实现
* 
* 全局函数，类外实现：
*		1、需要让编译器提前知道 类模板
*		2、需要让编译器提前知道 函数模板
*		3、类模板的定义	+ 添加友元（要加空模板参数列表！！）
*		4、全局函数的类外实现
* 
*/


template<class T1, class T2>
class Person15;

template<class T1, class T2>
void printPerson2(Person15<T1, T2>& p);

template<class T1,class T2>
class Person15 {
public:
	Person15(T1 name, T2 age) :m_name(name), m_age(age) {}

	// 友元函数，类内实现
	friend void printPerson1(Person15<T1, T2>& p) {
		cout << "This is friend func definited outside the class." << endl;
	}

	// 友元函数，类外实现
	// 需要添加 空模板参数列表
	friend void printPerson2<>(Person15<T1, T2>& p);

private:
	T1 m_name;
	T2 m_age;

};

// 类外实现
// 注意 这是一个模板函数
template<class T1, class T2>
void printPerson2(Person15<T1, T2>& p) {
	cout << "This is friend definited outside the class."<<endl;
}

static void test() {
	Person15<string, int> p1("zhangsan", 15);
	printPerson1(p1);
	printPerson2(p1);
}

int main15() {
	test();
	return 0;
}