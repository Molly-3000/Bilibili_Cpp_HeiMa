#include<iostream>
#define PI 3.14
#define Day 7
using namespace std;

//常量的定义2种方式

/*
1、#define 宏常量
	#define 常量名 常量值

2、const 修饰的变量 也是常量
	const 数据类型 变量名 = 常量值
*/

int main4() {

	cout << "One Week = " << Day << " Days" << endl;

	const int month = 12;

	cout << "One Year = " << month << " Months" << endl;

	system("pause");

	return 0;

}