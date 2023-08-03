#include"head.h"

/*
* 容器嵌套容器 
* 
* 多维数组
*/

#include<vector>
#include<algorithm>

static void print_int(int val) {
	cout << val << endl;
}

static void print_vector_int(vector<int> &v) {
	for_each(v.begin(), v.end(), print_int);
}

static void test() {
	vector<vector<int>> vvint;

	// 创建小容器
	vector<int> vint1;
	vector<int> vint2;
	vint1.push_back(11);
	vint1.push_back(12);
	vint1.push_back(13);
	vint2.push_back(21);
	vint2.push_back(22);
	vint2.push_back(23);

	// 将内部容器插入到外部容器
	vvint.push_back(vint1);
	vvint.push_back(vint2);

	for_each(vvint.begin(), vvint.end(), print_vector_int);

	for (vector<vector<int>>::iterator it = vvint.begin(); it != vvint.end(); it++) {
		// *it 就是外层<>内的内容，即vector<int>
		print_vector_int(*it);
	}

	for (vector<vector<int>>::iterator it = vvint.begin(); it != vvint.end(); it++) {
		for (vector<int>::iterator iit = (*it).begin(); iit != (*it).end(); iit++) {
			print_int(*iit);
		}
	}

}

int main20() {
	test();
	return 0;
}