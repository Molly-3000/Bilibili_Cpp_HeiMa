#include"head.h"
/*
* string容器
* 
* 基本概念：
* 
* 1、string是C++风格的字符串，本质上是一个类
* 
* 2、string和char*的区别：
*		char* 是一个指针，C语言中的字符串就是一个char*
*		string 是一个类，类内部封装了char*，并管理着这个字符串。
				string类是以char*为元素的一种容器。
* 
* 3、string特点：
*		string类内封装了很多成员方法，如insert\delete\replace\find\copy
*		string自动管理char*所分配的内存，不用担心赋值越界和取值越界，由类内部进行维护
*			  ~~~~~~~~
* 4、string构造函数
*		  string();					// 创建空的字符串
* 		·string(const string &s);	// 拷贝构造，通过string对象进行初始化
*		·string(const char * s);	// 通过字符串s进行初始化
* 		·string(int n,char c);		// 使用n个字符c进行初始化
* 
*/

static void test() {
	string s1;						// 默认构造
	const char* cstr = "cstr";
	string s2 = cstr;
	string s3 = "this is const char * s";
	string s4 = string("this is const string");
	string s5(5, 's');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

}

int main21() {
	test();
	return 0;
}