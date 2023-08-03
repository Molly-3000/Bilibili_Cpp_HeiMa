#include"head.h"
/*
* STL string 插入和删除 insert()、erase()
* 
* 功能：对string字符串进行插入和删除字符的操作
* 
* 插入函数原型：
*	·string& insert(int pos,const char * s)
*	·string& insert(int pos,const string& str)
*	·string& insert(int pos, int n, char c)
* 
* 删除函数原型：
*	·string& erase(int pos,int n=npos)		//删除从[pos]开始的n个字符
*/

#include<string>
static void test_insert() {
	string str = "0123456789";
	cout << str << endl;

	str.insert(1, "aaa");	// 开始插入，包括str[pos]
	cout << str << endl;

	str.insert(4, string("bbb"));
	cout << str << endl;

	str.insert(7, 3, 'c');
	cout << str << endl;
}

static void test_erase() {
	string str = "abcdefg";
	cout << str << endl;
	str.erase(1, 3);
	cout << str << endl;
}

int main27() {
	test_insert();
	test_erase();
	return 0;
}