#include"head.h"

// 函数 の 默认参数 和 占位参数
// 
// ->默认参数
// 
//		语法：返回类型 函数名 (参数类型 参数名, .. , 参数类型 参数名 = 缺省值,..)
//				
//		注意：1、没有缺省值的参数 必须位于 缺省参数 前
//					即 int func05(int a=10, int b, int c = 30)  // error
//			  2、当函数的定义拆分为 声明 和 实现 时，二者只能其一有默认参数
//					otherwise，error：重定义默认参数
// 
// ->占位参数
// 
//		语法：返回类型 函数名 (数据类型，...) {}
//					*占位参数还可以有默认值 e.g. (int = 10)
//		作用：用于占位。调用参数时必须填补该位置
//						 ^^^
// 

// 函数的声明
int func05(int a, int b, int c);
// 函数的实现
int func05(int a, int b = 20, int c = 30) {
	return a + b + c;
}

// 占位参数
void func05(int , int b, int , int, int = 10) {
	cout << "This is func05." << endl;
}

int main05() {

	cout << func05(10) << endl;

	cout << func05(10, 100) << endl;

	cout << func05(10, 100, 1000) << endl;


	func05(1, 1, 1, 1);		// 没有默认值的必须填补，

	system("pause");
	return 0;
}
