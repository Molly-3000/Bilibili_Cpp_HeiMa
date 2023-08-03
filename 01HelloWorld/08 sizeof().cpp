#include<iostream>
using namespace std;


int main8() {

	// sizeof() 
	// 作用：统计数据类型所占内存空间
	// 用法：sizeof(数据类型);sizeof(变量名);

	long num1 = 0;
	long long num2 = 0;

	cout << "short 类型所占的内存空间为：" << sizeof(short) <<"字节" << endl;
	cout << "int 类型所占的内存空间为：" << sizeof(int) << "字节" << endl;
	cout << "long 类型所占的内存空间为：" << sizeof(num1) << "字节" << endl;
	cout << "longlong 类型所占的内存空间为：" << sizeof(num2) << "字节" << endl;

	system("pause");

	return 0;

}