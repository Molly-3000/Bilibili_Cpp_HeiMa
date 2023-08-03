#include<iostream>
using namespace std;

#include<string>

int main12() {

	// 字符串

	// 1、C风格型字符串
	// char 字符串名[] = "zifuchuan"
	char str1[] = "abcd in C";

	// 2、C++风格字符串
	// string 字符串名 = "zifuchuan"
	// 使用前要包含头文件 string
	string str2 = "abcd in C++";

	cout << "C字符串：" << str1 << endl;
	cout << "C++字符串：" << str2 << endl;

	system("pause");

	return 0;
}