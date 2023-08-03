#include<iostream>
using namespace std;

int main20() {

	// 逻辑运算符
	// 作用：判断表达式为真（1）或假（0）
	
	// 逻辑非 ！
	int a = 10;
	cout << !a << endl;   // 0
	cout << !!a << endl;  // 1

	cout << 'a' << endl;   // a
	cout << !'a' << endl;  // 0


	cout << true << endl;  // 1

	// 逻辑与 &&
	cout << (a && a++) << endl;      // 1 
	cout << (a && (a-=11)) << endl;  // 0

	// 逻辑或 ||
	cout << (a || !a) << endl;       // 1

	system("pause");
	return 0;
}