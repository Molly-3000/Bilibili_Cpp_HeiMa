#include"head.h"

/*
* ****** 栈区 stack
* 
* 存放：局部变量、函数形参、返回值
* 
* 特点：由编译器自动分配和释放
* 
* 注意事项：不要返回局部变量的地址，
*				因为栈区开辟的数据将由编译器自动释放
* 
*/

int* func02(int b) {  // 形参数据 放在栈区
	b = 100;
	int a = 10;		// 局部变量		栈区
	return &a;		// 返回值		栈区
}

int main02() {

	int* p = func02(1);

	cout << "局部变量a为：" << *p << endl;  // 编译器做了保留
	cout << "局部变量a为：" << *p << endl;  // 乱码

	system("pause");

	return 0;
}