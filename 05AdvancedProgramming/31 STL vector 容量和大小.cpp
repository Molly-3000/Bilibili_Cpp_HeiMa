#include"head.h"
/*
* STL vector 容量 和 大小
* 
* 功能：对vector容器的容量和大小进行操作
*			      capacity >= size
* 
* 函数原型：
*	·bool empty()				// 判断是否为空
*	·int capacity()			// 返回容器容量
*	·int size()				// 返回容器内元素个数
*	·void resize(int num)	// 重新指定容器长度为num
*			// 如果容器变长，则以默认值填充新的位置
*			// 如果容器变短，则末尾超出部分的元素被删除
*	·void resize(int num,T elem)
*			// 指定填充默认值
* 
*	·void shrink_to_fit()		// 使capacity收缩到size大小
*/

#include<vector>

static void print_vector(vector<int> v) {
	cout << "vector : ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
}

static void test() {
	vector<int> v1;

	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 111);
	}

	if (v1.empty()) {// 为真 v1为空
		cout << "v1 is empty." << endl;
	}
	else {
		// capacity 会自动扩充， 大于size
		cout << "the capacity of v1 is " << v1.capacity() << endl;
		cout << "the size of v1 is " << v1.size() << endl;
		print_vector(v1);
	}

	v1.resize(15);	// resize(n)修改size，capacity仍会自动扩充>=size
	cout << "the capacity of v1 is " << v1.capacity() << endl;
	cout << "the size of v1 is " << v1.size() << endl;
	print_vector(v1);

	v1.resize(20, 999);
	cout << "the capacity of v1 is " << v1.capacity() << endl;
	cout << "the size of v1 is " << v1.size() << endl;
	print_vector(v1);

	v1.resize(5);	// resize()使size变小，capacity不变
	cout << "the capacity of v1 is " << v1.capacity() << endl;
	cout << "the size of v1 is " << v1.size() << endl;
	print_vector(v1);

	v1.shrink_to_fit();
	cout << "the capacity of v1 is " << v1.capacity() << endl;
	cout << "the size of v1 is " << v1.size() << endl;
	print_vector(v1);
}

int main31() {
	test();
	return 0;
}