#include"head.h"
/*
* STL deque 容器
* 
* 1、基本概念
* 
*	功能：双端数组，头部和尾部都可以进行插入和删除	
*		  ~~~~~~~~
*	deque和vector 区别：
*		·vector对于头部的插入删除（本质上是数据移动）效率低，数据量越大，效率越低
*		·deque对头部的插入删除速度比vector快
*		·vector访问元素的速度比deque快，这和两者的内部实现有关
*		  ~~~~~~				~~~~~~
*	  连续的内存空间		非连续的缓冲区，由中控器管理
* 
*	deque的内部工作原理：
*		deque内部有一个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
*					   ~~~~~~		   ~~~~~~
*		中控器维护每个缓冲区的地址，使得使用deque时像一片连续的内存空间
* 
*	deque容器的迭代器也是随机访问迭代器
* 
* 2、deque 构造函数
*	
*	函数原型：
*		·deque<T> deqT					// 无参构造
*		·deque(const deque<T>& deq)	// 拷贝构造
*		·deque(const_iterator begin, const_it end) // 左闭右开，拷贝元素
*		·deque(int n, T elem)			// n个elem拷贝
* 
*/

#include<deque>
#include<algorithm>

static void print_int(int val) {
	cout << val << " ";
}

static void print_deque_int(const deque<int>& dq) {
	cout << "deque: ";

	//for_each(dq.begin(), dq.end(), print_int);

	// const_iterator 只读迭代器，容器内的数据不可修改
	for (deque<int>::const_iterator it = dq.begin(); it != dq.end(); it++) {
		print_int(*it);
	}

	cout << endl << endl;
}

static void test() {
	// 无参构造
	deque<int> deq1;
	deq1.push_back(1);
	deq1.push_back(2);
	deq1.push_front(0);
	print_deque_int(deq1);

	// 拷贝构造
	deque<int> deq2(deq1);
	print_deque_int(deq2);

	// 迭代器所指区间，左闭右开，拷贝元素
	deque<int> deq3(deq1.begin(), deq1.end());
	print_deque_int(deq3);

	// n个elem
	deque<int> deq4(3, 1);
	print_deque_int(deq4);

}

int main36() {
	test();
	return 0;
}