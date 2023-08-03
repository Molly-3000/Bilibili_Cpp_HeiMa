#include"head.h"
/*
* STL vector 互换容器
* 
* 功能：交换两个容器内的元素
* 
* 函数原型：
*	·vector<T>& swap(vector<T>& vec)
*/

#include<vector>
#include<algorithm>

static void print_int(int val) {
	cout << val << " ";
}

static void print_vector(vector<int> v) {
	for_each(v.begin(), v.end(), print_int);
	cout << endl;
}

static void test() {
	vector<int> v1, v2;
	
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 111);
	}
	v2.assign(5, 55);

	cout << "before swap:" << endl;
	cout << "v1:";
	print_vector(v1);
	cout << "the capacity of v1 is " << v1.capacity();
	cout << " the size of v1 is " << v1.size() << endl;

	cout << "v2:";
	print_vector(v2);
	cout << "the capacity of v2 is " << v2.capacity();
	cout << " the size of v2 is " << v2.size() << endl;

	v1.swap(v2);
	cout << endl << "after swap:" << endl;
	cout << "v1:";
	print_vector(v1);
	cout << "the capacity of v1 is " << v1.capacity();
	cout << " the size of v1 is " << v1.size() << endl;

	cout << "v2:";
	print_vector(v2);
	cout << "the capacity of v2 is " << v2.capacity();
	cout << " the size of v2 is " << v2.size() << endl;
}

// 2、实际用途
// 巧用swap可以收缩内存空间
static void test_() {
	vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}
	cout << "the capacity of v is " << v.capacity() << endl; // >10000
	cout << "the size of v is " << v.size() << endl; // 10000

	v.resize(3);
	cout << "the capacity of v is " << v.capacity() << endl; // 不变
	cout << "the size of v is " << v.size() << endl; // 3

	// 通过swap来收缩内存
	// 通过v拷贝构造出匿名对象，该对象capacity = size = v.size()
	//		且匿名对象调用swap(v)
	//		匿名对象 将在当前行执行完后 自动释放
	vector<int>(v).swap(v); // 等价于 v.shrink_to_fit()
	cout << "the capacity of v is " << v.capacity() << endl; // 不变
	cout << "the size of v is " << v.size() << endl; // 3
}

int main34() {
	test();
	system("pause");

	test_();
	return 0;
}
