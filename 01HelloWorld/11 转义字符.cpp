#include<iostream>
using namespace std;

int main11() {

	// \ 转义字符
	// 作用：表示一些不能输出的ASCII字符，比如：换行\n, 反斜杠\\, 水平制表\t，回车\r

	cout << "Hello World\n";  // c语言里没有endl，用\n进行换行

	cout << "\\\n";

	cout << "aaa\tHello World\n";   // 作用是整齐地输出数据，补空格，左对齐
	cout << "aaaaaa\tHello World\n";
	cout << "aaaa\tHello World\n";

	system("pause");


	return 0;
}