#include"head.h"
#include<string>
/*
* 类模板 分文件编写
* 
* 问题：类模板中，成员函数的创建时机是调用阶段
*			所以分文件编写，会链接不到类模板的成员函数
* 
* 解决：两种方式
*		1、直接包含(实现了成员函数的)cpp源文件		（此cpp链接该cpp链接hpp）
*		2、将声明和实现写到同一个文件中，并将文件后缀改为.hpp		（此cpp直接链接hpp）
*			 ~~~~~~~~~~	   ~~~~~~~~~~					 ~~~~~
*/
#include"14 person.cpp"
#include"14 class template head.hpp"

static void test() {
	Person14<string> p1("zhangsan", 16);
	Person14<string> p2 = p1;
	Person14<string> p3 = Person14<string>("lisi", 16);
	p1.showInfo();
	p2.showInfo();
	p3.showInfo();
}

int main14() {
	test();
	return 0;
}
