#include<iostream>
using namespace std;


int main10() {

	// char 字符型变量
	// 作用：表示单个字符
	// 语法：char ch = 'a';
	// 1、只能用单引号
	// 2、引号中间只能有单个字符 

	char ch = 'a';  // 存储单元并不存储字符，而是存储对应的ASCII编码

	cout << "char字符型变量所占内存空间：" << sizeof(ch) << endl;

	// 输出字符的ASCII编码
	cout << "字符a对应的ASCII码为：" << (int)ch << endl;  // 强制类型转换   //97
	cout << "字符A对应的ASCII码为：" << (int)'A' << endl;  // 强制类型转换    //65
	cout << "字符@对应的ASCII码为：" << (int)'@' << endl;  // 强制类型转换    //65

	// ASCII编码
	/*
	非打印字符：0-31分配给了控制字符，用于控制打印机等一些外围设备
	打印字符：32-126分配给了键盘上能找到的字符
	*/

	system("pause");

	return 0;

}