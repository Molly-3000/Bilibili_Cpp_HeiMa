#include<iostream>
using namespace std;

int main13() {

	// bool 布尔型

	bool flag = true;

	cout << "true(真值)的本质为：" << flag << endl;
	cout << "false(假值)的本质为：" << false << endl;
	cout << "bool型数据的大小为：" << sizeof(true) << endl;

	flag = 111;
	cout << "当数字大于等于1时：" << flag << endl;
	flag = -11;
	cout << "当数字小于0时：" << flag << endl;

	// 所有非0即为true，本质是1；false本质是0

	system("pause");

	return 0;
}