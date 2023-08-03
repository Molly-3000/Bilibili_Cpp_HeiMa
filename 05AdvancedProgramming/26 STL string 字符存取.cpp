#include"head.h"
/*
* STL string 字符存取
* 
* 单个字符存取方式（函数原型）：
*	·char& operator[] (int n)	// 通过[n]下标获取
*	·char& at(int n)			// 通过at(n)方法获取
* 
*/

static void test() {
	string str = "hello";

	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i);
	}
	cout << endl;

	cout << str[str.size()] << endl;		// 超过，返回null

	str[0] = '0';
	str.at(3) = 'k';
	cout << str << endl;
}

int main26() {
	test();
	return 0;
}