#include<iostream>
using namespace std;

int main31() {

	// 跳转语句 goto
	// 作用：可以无条件跳转语句   一般不用 影响代码逻辑结构
	// 语法：goto 标记名
	// 需要加标记

	cout << "111\n";

	cout << "222\n";
	goto FLAG;

	cout << "333\n";

	cout << "444\n";

	FLAG:
	cout << "555\n";

	system("pause");
	return 0;
}