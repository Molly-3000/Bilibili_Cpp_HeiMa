#include"head.h"
/*
* STL vector 预留空间
* 
* 功能：减少vector在动态扩展容量时的扩展次数
* 
* 函数原型：
*	·reserve(int len)	// 容器预留len个元素长度
			// 预留位置不初始化，元素不可访问
*/

#include<vector>
#include<algorithm>
static void print_int(int val) {
	cout << val << " ";
}

static void print_vector(vector<int> v) {
	cout << "vector : ";
	for_each(v.begin(), v.end(), print_int); // end()=size()
	cout << endl;
}

static void test() {
	vector<int> v;

	int count = 0;
	int* p = nullptr;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			count++;
		}
	}

	cout << "allocate times : " << count << endl << endl;

	vector<int> v2;
	v2.reserve(5);
	cout << "the capacity of v2 is " << v2.capacity() << endl;
	cout << "the size of v2 is " << v2.size() << endl << endl;

	int count2 = 0;
	p = NULL;
	for (int i = 0; i < 10; i++) {
		v2.push_back(i);
		if (p != &v2[0]) {
			p = &v2[0];
			count2++;
		}
	}
	cout << "allocate times : " << count2 << endl;
	cout << "the capacity of v2 is " << v2.capacity() << endl;
	cout << "the size of v2 is " << v2.size() << endl << endl;

	v2.reserve(5);	// 当前size>reserve，reserve()不起作用
	cout << "the capacity of v2 is " << v2.capacity() << endl;
	cout << "the size of v2 is " << v2.size() << endl << endl;

	v2.reserve(15);	// 当前size<reserve时，new capacity = reserve
	cout << "the capacity of v2 is " << v2.capacity() << endl;
	cout << "the size of v2 is " << v2.size() << endl;
}

int main35() {
	test();
	return 0;
}