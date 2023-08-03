#include"head.h"
/*
* STL deque 大小
* 
* 函数原型：
*	·bool empty()
*	·int size()
*	·deque<T>& resize(int num)
*	·deque<T>& resize(int num, T elem)
*/

#include<deque>
static void print_deque(const deque<int>& dq) {
	cout << "deque: ";
	for (deque<int>::const_iterator it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

static void test() {
	deque<int> dq;
	for (int i = 0; i < 10; i++) {
		dq.push_front(i);
	}

	if (dq.empty()) {
		cout << "the deque is empty!" << endl;
	}
	else {
		cout << "size of the deque is " << dq.size() << endl;
		print_deque(dq);
	}

	// resize(num)
	dq.resize(15);
	print_deque(dq);
	dq.resize(5);
	print_deque(dq);

	// resize(num,elem)
	dq.resize(10, 10);
	print_deque(dq);
}

int main38() {
	test();
	return 0;
}