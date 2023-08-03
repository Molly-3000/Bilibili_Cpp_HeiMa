#include"head.h"
#include<string>
/*
* 类模板
* 
* 作用：创建一个通用类，类中的成员 数据类型不具体指定，
*		  用一个虚拟的类型来代表 ~~~~~~~~
*				~~~~~~~~~~
* 语法：template<typename T1,typename T2>;	//typename 可以用 class 代替
*		class myClass{};
* 
* P.S. 注意类模板 的实例化语法
*	   myClass<T1 p1, T2 p2> p0();
*	   myClass<T1 p1, T2 p2> p1 = myClass<T1 p1, T2 p2>();
*	   myClass<T1 p1, T2 p2> p2 = p1;
* 
*/

// template的参数列表，可以有多个虚拟类型
template<typename NameType,typename AgeType>
class Person08 {
public:
	Person08() {}
	Person08(NameType name, AgeType age) :m_Name(name),m_Age(age) {}
	void showInfo() {
		cout << this->m_Name << " is " << this->m_Age << "." << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

static void test() {
	Person08<string, int> p1 = Person08<string, int>("zhangsan", 16);
	Person08<string, int> p2("lisi",18);
	Person08<string, int> p();

	p1.showInfo();
	p2.showInfo();

}

int main08() {
	test();
	return 0;
}
