#include"head.h"
/*
* STL vector 插入和删除
* 
* 功能：对vector容器进行插入、删除操作
* 
* 函数原型：
*	·push_back(elem)		// 尾插
*	·pop_back()			// 删除最后一个元素
*	·insert(const_iterator pos,T elem)	
			// 在迭代器指定位置，插入elem
*	·insert(const_iterator pos,int count, T elem) 
			// 在迭代器指定位置，插入count个elem

*	·erase(const_iterator pos)		
			// 删除迭代器指向位置的元素
*	·erase(const_iterator start, const_iterator end) 
			// 删除迭代器从start到end，左闭右开，的元素

*	·clear()	// 删除所有元素
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
	print_vector(v);

	for (int i = 0; i < 10; i++) {
		v.push_back(i * 111);	// 尾插
	}
	print_vector(v);

	v.pop_back();	// 尾删
	print_vector(v);

	// insert(const_iterator, elem)
	v.insert(v.begin(), 1000);
	print_vector(v);

	// insert(const_iterator, int count, T elem)
	v.insert(v.begin()+1, 2, 100);
	print_vector(v);

	// erase(const_iterator)
	v.erase(v.begin());		// 删除1000
	print_vector(v);

	// erase(const_iterator start ,const_iterator end)
	v.erase(v.begin(), v.begin() + 3);
	print_vector(v);

	v.clear();
	print_vector(v);

}

int main32() {
	test();
	return 0;
}