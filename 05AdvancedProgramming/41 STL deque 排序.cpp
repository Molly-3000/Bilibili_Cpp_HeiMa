#include"head.h"
/*
* STL deque 排序
* 
* 功能：用算法对deque容器进行排序
* 
* 算法原型：
*	·sort(iterator start, iterator end)	// 默认 升序
*		// 对start到end区间，左闭右开，的元素进行排序
*		// 对于支持随机访问的迭代器，都可以用sort排序
				如vector
*/

#include<deque>
#include<algorithm>
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
		dq.push_back(i);
		dq.push_front(i*2);
	}
	print_deque(dq);

	// 升序
	sort(dq.begin(), dq.end());
	print_deque(dq);

}

int main41() {
	test();
	return 0;
}