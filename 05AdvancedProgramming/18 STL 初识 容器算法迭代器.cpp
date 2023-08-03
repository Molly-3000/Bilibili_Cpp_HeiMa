#include"head.h"
/*
* STL 容器算法迭代器 初识
* 
* Case：vector存放内置数据类型
* 
*		容器   --  vector
*		算法   --  for_each
*		迭代器 --  vector<int>::iterator
* 
*/

#include<vector>
#include<algorithm>

static void myPrint(int val) {
	cout << val << endl;
}

static void test() {
	// 创建一个vector容器，存放int数组
	vector<int> vint;

	// 向容器中插入数据
	vint.push_back(11);
	vint.push_back(354);
	vint.push_back(53);
	vint.push_back(134);

	{
	// 通过迭代器访问容器中的数据
	// 起始迭代器，指向容器中第一个元素
	vector<int>::iterator itBegin = vint.begin();
	// 结束迭代器，指向容器中最后一个元素的 下一个位置	!!!
	vector<int>::iterator itEnd = vint.end();

	// 第一种遍历方式
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}
	}

	// 第二种，用for勛huan
	for (vector<int>::iterator it = vint.begin(); it != vint.end(); it++) {
		cout << *it << endl;
	}

	// 第三中，用STL算法
	// for_each()三个参数：起始迭代器、结束迭代器、函数
	//		函数回调，不需要写参数
	for_each(vint.begin(), vint.end(), myPrint);
}

int main18() {

	test();

	system("pause");

	return 0;
}
