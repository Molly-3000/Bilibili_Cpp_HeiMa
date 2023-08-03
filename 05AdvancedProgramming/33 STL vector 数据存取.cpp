#include"head.h"
/*
* STL vector 数据存取	(除了迭代器)
* 
* 函数原型：
*	·operator[]		// 
*	·at(int idx)		//
*	·front()			// 返回容器中第一个元素
*	·back()			// 返回容器中最后一个元素
*/

#include<vector>

static void test() {
	vector<int> v;

	v.assign(10, 1);

	v.push_back(999);

	v.insert(v.begin(), 0);

	// 通过operator[] 访问
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// 通过at()访问
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;

	// front() 返回第一个元素
	cout << "the first element is " << v.front() << endl;

	// back() 返回最后一个元素
	cout << "the last element is " << v.back() << endl;
}

int main33() {
	test();
	return 0;
}