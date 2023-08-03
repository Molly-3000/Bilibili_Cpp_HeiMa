#include"head.h"
/*
* STL deque 数据存取
* 
* 函数原型：
*	·operator[idx]
*	·at(idx)
*	·fornt()
*	·back()
*/

#include<deque>
static void print_deque(const deque<int>& dq) {
	cout << "deque :";
	for (deque<int>::const_iterator it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

static void test() {
	deque<int> dq;
	for (int i = 0; i < 10; i++) {
		dq.push_back(i);
		dq.push_front(i);
	}

	// operator[idx]
	for (int i = 0; i < 10; i++) {
		cout << "dq[" << i << "]" << " = " << dq[i] << endl;
	}

	// at(idx)
	for (int i = 10; i < dq.size(); i++) {
		cout << "dq.at(" << i << ")" << " = " << dq.at(i) << endl;
	}

	// front()
	cout << "the first element is " << dq.front() << endl;
	
	// back()
	cout << "the last element is " << dq.back() << endl;
}

int main40() {
	test();
	return 0;
}