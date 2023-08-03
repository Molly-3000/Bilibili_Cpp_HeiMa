#include<iostream>
using namespace std;

// 数组：相同类型数据元素的集合
// 特点：1.每个数据都是相同的数据类型     相同数据类型  数据可重复
//		 2.数组占据的时连续的内存空间     连续内存空间
//		 
//	**** 3.定义数组时必须有初始长度 ***
// 
// 定义方法：（静态数组）
//1、数据类型 数组名[数组长度];
//2、数据类型 数组名[] = {值1，值2，···，值n}；
//3、数据类型 数组名[数组长度] = { 值1，值2，···，值n }；

#include<string>

int main32() {

	int iarr[5];
	// 数组名的用途：
	// 1. sizeof(数组名)，可得到整个数组占用的空间大小
	// 2. 表示数组的内存地址
	// 数组名是常量 不能赋值

	cout << "数组大小：" << sizeof(iarr) << endl;
	cout << "数组首地址：" << iarr << endl;
	cout << "数组第一个元素地址：" << &iarr[0] << endl;   // &为取址符号

	for (int i = 0; i < 5; i++) iarr[i] = i;

	for (int i = 0; i < 5; i++) {
		cout << iarr[i];
	}
	cout << endl;

	char charr[] = { 'a','b','c' };
	for (int i = 0; i < sizeof(charr)/sizeof(char); i++) {
		cout << charr[i];
	}
	cout << endl;

	string starr[4] = { "abc","bca","cab" };  //指名长度但没有初始化时，会自动填充

	for (int i = 0; i < sizeof(starr)/sizeof(starr[0]); i++) {
		cout << starr[i]<<endl;
	}


	system("pause");
	return 0;
}