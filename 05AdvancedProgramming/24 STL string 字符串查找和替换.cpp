#include"head.h"
/*
* STL string 字符串查找和替换
* 
* 功能：
*	查找	查找指定字符串是否存在
*	替换	在指定的位置替换字符串
* 
* 查找函数原型：
*	·int find(const string& str,int pos=0) const	
				// 查找str第一次出现位置，从pos开始查找
*	·int find(const char *s, int pos=0)
				// 查找s第一次出现位置，从pos开始查找
*	·int find(const char c,int pos=0)
				// 查找c第一次出现位置，从pos开始查找
*	·int find(const char *s, int pos,int n)			!!!
				// 查找s的前n个字符第一次出现位置，从pos开始查找
*	·int rfind(const string& str,int pos=0) const
				// 查找str最后一次出现位置，从pos开始查找
*	·int rfind(const char *s, int pos=0)
				// 查找s最后一次出现位置，从pos开始查找
*	·int rfind(const char c,int pos=0)
				// 查找c最后一次出现位置，从pos开始查找
*	·int rfind(const char *s, int pos,int n)			!!!
				// 查找s的前n个字符最后一次出现位置，从pos开始向前查找
* 
* 替换函数原型：
*	·string& replace(int pos, int n, const string& str)
				// 替换从pos开始的n个字符为 整个的字符串str		!!!
*	·string& replace(int pos, int n, const char* s)
				// 替换从pos开始的n个字符为 整个的字符串str		!!!
* 
*/

#include<string>
static void test_find() {
	string str = "abcdefg1234567abcdefgabcdefg";

	int pos1 = str.find("de");			// int find(const char* s)
	int pos2 = str.find(string("ed"));	// int find(consts string& str)
	// 未查到返回 -1

	int pos3 = str.find('d');			// int find(char c)
	int pos4 = str.find("123ed", 2, 3);	// int find(const char *s, int pos,int n)
	// 从str[2]开始查找s中的前三个字符

	// find 和 rfind 区别：
	// rfind从右往左查找，find从左往右 ！！！
	int pos5 = str.rfind("abc");
	int pos6 = str.rfind(string("abc"));
	int pos7 = str.rfind('a');
	int pos8 = str.rfind("abc12", 2, 3);	
	// 反向查找，但正向匹配。即查找顺序为str[2]、str[1]、str[0]
	
	cout << pos1 << " " << pos2 << " " << pos3 << " " << pos4 << endl;
	cout << pos5 << " " << pos6 << " " << pos7 << " " << pos8 << endl;
}

static void test_replace() {
	string str = "abcdefg";
	cout << str << endl;
	str.replace(2, 3, "111111");
	cout << str << endl;
	str.replace(2, 5, string("aa"));
	cout << str << endl;
}

int main24() {
	test_find();
	test_replace();
	return 0;
}