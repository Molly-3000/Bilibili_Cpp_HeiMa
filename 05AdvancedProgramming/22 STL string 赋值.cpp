#include"head.h"
/*
* string 赋值操作
* 
* 函数原型：
*	·string& operator=(const char* s)
*	·string& operator=(const string &s)
*	·string& operator=(char c)
*	·string& assign(const char *s)
* 	·string& assign(const string &s)
* 	·string& assign(const char *s,int n)  ！！ // 把s的前n个字符赋值给当前字符串
*	·string& assign(int n,char c)
*/

#include<string>

static void test() {
	string s1 = "const char *";	// string& operator= (const char * s)
	cout << "s1 = " << s1 << endl;

	string s2 = string("const string & s");				// string& operator= (const string& s)
	cout << "s2 = " << s2 << endl;

	string s3;
	s3 = 'c';					// string& operator= (char c)
	cout << "s3 = " << s3 << endl;

	string s4, s5, s6, s7;
	s4.assign("const char * ");	// string& assign(const char * s)
	cout << "s4 = " << s4 << endl;

	s5.assign(string("const string& s"));				// string& assign(const string& s)
	cout << "s5 = " << s5 << endl;

	s6.assign("123456789",5);	// string& assign(const char * s, int n)
	cout << "s6 = " << s6 << endl;

	s7.assign(7, 'c');			// string& assign(int n, char c)
	cout << "s7 = " << s7 << endl;
}

int main22() {

	test();
	return 0;
}