#include<iostream>
using namespace std;


// function 将一段代码封装起来，减少代码重复
// 1、函数的定义：
// 
// 返回值类型 函数名 (参数列表) {
//		函数体;
//		return 表达式;
//}
// （函数的常见类型：无参无返，有参无返，无参有返，有参有返）
// 
// 
// 2、函数的调用：
// 
// 函数名(参数列表);
//

// 函数定义时，参数为形参
int sum(int num1,int num2) {
	//int result = a + b;
	//return result;
	return num1 + num2;
}

int main38() {

	int a = 111;
	int b = 222;

	// 函数调用时，参数为实参
	// 
	// ** 实参的值会传递给形参
	cout << sum(a, b) << endl;
	cout << sum(111, 222) << endl;

	system("pause");
	return 0;
}