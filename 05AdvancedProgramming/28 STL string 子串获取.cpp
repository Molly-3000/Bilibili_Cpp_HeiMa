#include"head.h"
/*
* STL string 子串
* 
* 功能：从字符串中截取所需的子串
* 
* 函数原型：
*	·string substr(int pos = 0,int n = npos) const 
			// 返回由[pos]开始的n个字符组成的字符串
*/

#include<string>

static void test() {
	string str = "abcd hello 1234";

	string subStr = str.substr(5, 5);

	cout << subStr << endl;
}

// 使用场景
static void test02() {
	string str = "zhangsan@sina.com";
	cout << str << endl;

	int npos = str.find('@');
	string subStr = str.substr(0, npos);
	cout << subStr << endl;

	string subStr2 = str.substr(0, -9);		// c++ 不支持负索引
	cout << subStr2 << endl;
}

int main28() {
	test();
	test02();
	return 0;
}