#include"head.h"
/*
* STL vector容器
* 
* 1、vector基本概念
*	功能：vector数据结构和数组类似，也称为单端数组
*						 ~~~~~~~~~		  ~~~~~~~~
*	与数组区别：
*		数组是静态空间，分配内存后无法扩展
*		vector可以动态扩展（尾插和尾删）
*				  ~~~~~~~~
*`!!动态扩展：
*		并不是在原空间之后续借新空间，而是找更大的空间，
*			然后将数据拷贝到新数据空间，并释放原空间
*					  ~~~~  ~~~~~~~~~~
*	 ···| x [ 1 | 2 | 3 | 4 |···| n ] y |···
*		    ↑	↑					    ↑	↑
*		v. rend	begin				 rbegin end  ()
* 
*	vector容器的迭代器（上述几个）是随机访问迭代器
* 
* 
* 2、vector 构造函数
*	
*	功能：创建vector容器
*
*	函数原型：
*		·vector<T> v;					// 指定模板参数实现类实现，默认构造函数
*		·vector(v.begin(),v.end())		// 将【v.begin(),end())区间中的元素，拷贝到自身
*		·vector(n,elem)				// n个elem，拷贝到自身
*		·vector(const vector &vec)		// 拷贝构造
*/

#include<vector>
#include<algorithm>

static void print_int(int val) {
	cout << val << " ";
}

static void print_vector_int(vector<int> v) {

	//for_each(v.begin(), v.end(), print_int);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		print_int(*it);
	}

	cout << endl;
}

static void test() {

	// 默认构造
	vector<int> v1;	

	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 11);
	}
	print_vector_int(v1);

	// 通过区间构造
	vector<int> v2(v1.begin(), v1.end());  // 前闭后开的区间，拷贝
	print_vector_int(v2);

	// n个elem构造
	vector<int> v3(10, 100);
	print_vector_int(v3);

	// 拷贝构造
	vector<int> v4(v3);
	print_vector_int(v4);
}

int main29() {
	test();
	return 0;
}
