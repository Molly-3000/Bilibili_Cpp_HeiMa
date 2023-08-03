#include"head.h"
/*
* STL vector 赋值
* 
* 功能：给vector容器进行赋值
* 
* 函数原型：
*	·vector& operator= (const vector& vec);
*	·vector& assign (begin, end)
*	·vector& assign (n, elem)
*/

#include<vector>

static void print_vector(vector<int> v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

static void test() {
	vector<int> v1, v2, v3;

	// oeprator=
	v1 = vector<int>(10, 100);
	print_vector(v1);

	// assign(begin, end)
	v2.assign(v1.begin(), v1.end());
	print_vector(v2);

	// assign(n, elem)
	v3.assign(10, 33);
	print_vector(v3);
}

int main30() {
	test();
	return 0;
}