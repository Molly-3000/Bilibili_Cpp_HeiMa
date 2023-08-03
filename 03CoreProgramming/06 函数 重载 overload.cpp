#include"head.h"

//
// 函数重载
// 
// 作用：函数名可以相同，提高函数的复用性
// 
// 条件：1、函数名相同
//		 2、重名函数的作用域相同（同全局/类/作用域）
//		 3、重名函数的声明不同（即参数类型/个数/顺序不同）
// 
// 注意：引用可以作为重载条件
//

void func06() { cout << "This is func06()." << endl; }
// 个数不同
void func06(int a, int b) { cout << "This is func06(int a, int b)." << endl; }
// 类型不同
void func06(int a, double b) { cout << "This is func06(int a, double b)." << endl; }
// 顺序不同
void func06(double a, int b) { cout << "This is func06(double a, int b)." << endl; }

// int func06() { return 0; }	// 非法，无法重载 仅按返回类型 区分的重载函数
int func06(double a, double b) { return 0; }	// 合法


// 引用作为重载条件
void func06(int& a) { cout << "This is func06(int &a)." << endl; }
void func06(const int& a) { cout << "This is func06(const int &a)." << endl; }

int main06() {

	func06();
	func06(0,0);
	func06(0, 0.0);
	func06(0.0, 0);

	func06(0.0, 0.0);

	cout << "======================" << endl;

	int a = 10;
	const int b = 10;

	func06(a);

	func06(b);
	func06(100); // const int &temp = 100; func06(temp);

	system("pause");
	return 0;
}