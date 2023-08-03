#include"head.h"
#include<string>
/*
* 通常<*>是<*.h>的升级版本，都是c++的标准库，升级后都塞进了std命名空间
* 
* 但<string.h>是c的标准库，用于处理char*类型的字符串
* 而<cstring>是c++用于兼容c标准库中<string.h>的库文件
* <string>是包装了std的C++头文件，对应的是新的string类
*/

/*
* 类模板 与 函数模板 区别
* 
* 1、类模板不能自动类型推导，即类模板只能显示指定类型
* 
* 2、类模板可以在模板参数列表中，有默认参数
*/

template<class NameType,class AgeType = int>
class Person09 {
public:
	Person09(NameType name,AgeType age):m_name(name),m_age(age) {}
	void showInfo() {
		cout << this->m_name << " is " << this->m_age << "." << endl;
	}
	NameType m_name;
	AgeType m_age;
};

// 1、类模板无法自动类型推导
static void test01() {
	//Person09 p1("auto_type", 10);	//err,缺少类模板的参数列表
	
	Person09<string, int> p1("explict_type", 10);
	p1.showInfo();
}

// 2、类模板可以在模板参数列表中，使用默认参数
static void test02() {
	Person09<string> p("default_type", 100);
	p.showInfo();
}

int main09() {
	test01();
	test02();
	return 0;
}


