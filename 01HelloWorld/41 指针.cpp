#include "head.h"

// 指针：指针是一种数据类型，存储的值为一段目的地址编号
// 
// 作用：通过指针可以 间接 地访问内存
// 
// 内存地址编号从0开始，一般用16进制表示。
// 
// 可以利用指针变量或指针常量保存地址。
// 
// 指针就是一个地址
// 
// 声明一个指针：
//		指向的数据类型 * 指针名;
// 

int main41() {

	int a = 10;

	// 1、定义一个指针
	int* p = &a;  // & 取地址

	cout << "a为：" << a << endl;
	cout << "a的地址为：" << &a << endl;
	cout << "p为：" << p << endl;
	cout << "p指向的对象为：" << *p << endl;

	// 2、指针的使用
	//		通过解引用的方式来找到指针指向的内存
	//		指针前加 * ，就是解引用，可以得出指针所指向的对象

	*p = 20; // * 取值，即找到指针指向的内存中的数据
	cout << "a的值为：" << a << endl;


	// 3、指针的大小，不管是什么数据类型
	//		在32位操作系统中，指针占四个字节
	//		在64位操作系统中，指针占八个字节

	cout << "指针占用的内存空间大小：" << sizeof(p) << endl;
	cout << "指针占用的内存空间大小：" << sizeof(int *) << endl;
	cout << "指针占用的内存空间大小：" << sizeof(double*) << endl;
	cout << "指针占用的内存空间大小：" << sizeof(string*) << endl;


	// 4、空指针和野指针
	//		空指针：指向内存编号为0的红箭
	//		  用处：初始化指针变量
	//		  *** 空指针是不可读的。  没有语法错误，但运行错误。
	// 
	//		  *** 0~255的编号是系统占用的，都不可访问
	// 
	//		野指针：未初始化的指针
	//        *** 指向非法的内存空间。（未申请，没有访问权限）

	int* nullp = NULL;
	int* wildp = (int * )0x11ff;

	cout << "nullptr: " << nullp << endl;
	//cout << "*nullptr: " << *nullp << endl;     // 运行错 读取访问权限冲突
	cout << "wildptr: " << wildp << endl;
	//cout << "*wildptr: " << *wildp << endl;		  // 运行错 读取访问权限冲突


	// 5、const 修饰指针（三种情况，就近原则/从右往左）
	//		A：const 修饰指针 ----常量指针 const pointer
	//		B：const 修饰常量 ----指针常量 pointer to const
	//		C：const 修饰常量和常量


	// A：const 修饰指针 ----常量指针
	//		指针本身是个常量，必须初始化，且不可更改。
	//			但指针指向的对象的值可以更改。
	int num = 0;
	int* const p0 = &num;


	// B：const 修饰常量 ----指针常量
	//      指针本身是个变量，可以更改，指向的对象的值不可更改。
	const int num2 = 0;
	const int* p2;
	p2 = &num2;

	// C：const 修饰常量和常量
	//      指针的指向，和指向的对象的值都不可更改，必须初始化。
	const int* const p3 = &num2;

	system("pause");

	return 0;
}