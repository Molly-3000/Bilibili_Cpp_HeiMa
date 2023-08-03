#include"head.h"
/*
*  ****** 堆区 heap
* 
* 特点：由程序员进行分配和释放
*			如果程序员不释放，在程序结束时，OS进行回收
* 
* 分配：使用 new 关键字
* 
*		语法：数据类型 * 变量名 = new 数据类型(初始化数据);
* 
* 释放：使用 delete 关键字
* 
*		语法：delete 变量名; // 本质上删除的是堆数据的指针
* 
*/

int* func03() {

	// 指针pa本质是局部变量，存放在栈区，指针指向的数据在堆区
	// new 的返回值是 该数据类型的指针
	int* pa = new int(10);

	return pa;
}


int * createIntArrayInStack(int len) {
	// 在堆区开辟一段连续空间
	int* arr = new int[len];

	// 访问方式 和 栈上的数组一样
	for (int i = 0; i < len; i++) {
		arr[i] = i + 100;
	}

	return arr;
}

int main03() {

	int* p;
	p = func03();

	cout << "局部变量a为：" << *p << endl;
	cout << "局部变量a为：" << *p << endl;
	cout << "局部变量a为：" << *p << endl;      // 堆上的数据，编译器不会进行释放

	delete p;									// 程序员主动释放
	//cout << "局部变量a为：" << *p << endl;    // 非法


	int len = 10;
	int * arr = createIntArrayInStack(len);

	// 访问方式 和 栈上的数组一样
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}

	// 释放堆上的数组
	//	特别的 要加一个[]，告诉编译器要释放的是个数组
	delete[] arr;

	// 如果没加 []
	arr = createIntArrayInStack(len);
	int * temp = arr;

	cout << arr << endl;
	delete arr;
	cout << arr << endl;         // 已经变成野指针
	//cout << *arr << endl;	     // 变成野指针,报错
	cout << *(temp+4) << endl;	 // 可以发现，其实也释放了内存（原本的104变成了新的数字）


	// 关于 delete 和 delete []
	// https://www.cnblogs.com/simplepaul/p/6861210.html
	// 
	// 一般来说使用new分配的对象，用delete来释放。用new[] 分配的内存用delete [] 来逐个释放。
	// 
	// 当我们用new [] 分配的对象是 基本数据 类型时，用delete和delete [] 没有区别。
	// 原因在于：分配简单类型内存时，内存大小已经确定，系统可以记忆并且进行管理，在析构时，系统并不会调用析构函数，
	// 它直接通过指针可以获取实际分配的内存空间，哪怕是一个数组内存空间
	// (在分配过程中 系统会记录分配内存的大小等信息，此信息保存在结构体_CrtMemBlockHeader中
	// 
	// 当用new [] 分配的对象是 自定义对象 时，二者不能通用。
	// 调用delete的时候，系统会自动调用已分配的对象的析构函数。
	// delete[] 用来释放指针指向的内存，并逐一调用数组中每个对象的destructor
	// 
	// 最关键的区别在于调用析构函数上。
	// 影响取决于此程序的类没有使用操作系统的系统资源，比如文件、端口、线程等。这些资源的释放必须依靠这些类的析构函数。
	// 比如使用了线程，但不被释放，它将总在后台运行，浪费内存和CPU资源。

	system("pause");

	return 0;
}