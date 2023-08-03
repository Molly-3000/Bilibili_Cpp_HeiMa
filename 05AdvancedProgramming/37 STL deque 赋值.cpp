#include"head.h"
/*
* STL deque 赋值
* 
* 函数原型：
*	·deque<T>& operator= (const deque<T>& dq)
*	·deque<T>& assign(const_iterator start, const_it end)
*	·deque<T>& assign(int n, T elem)
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
	deque<int> dq1;
	for (int i = 0; i < 10; i++) {
		dq1.push_front(i);
	}
	print_deque(dq1);

	// operator=
	deque<int> dq2 = dq1;
	print_deque(dq2);

	// assign(const_iterator start, const_iterator end)
	deque<int> dq3;
	dq3.assign(dq1.begin(), dq1.end() - 5);
	print_deque(dq3);

	// aasign(n,elem)
	deque<int> dq4;
	dq4.assign(5, 1);
	print_deque(dq4);
}

int main37() {
	test();
	return 0;
}