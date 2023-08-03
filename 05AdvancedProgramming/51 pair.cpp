#include"head.h"
/*
* pair 队组数据
* 
* 功能：成对出现的数据，利用队组可以让函数返回两个数据
* 
* 创建：
*	·pair<type, type> p (value1,value2)
*	·pair<type, type> p = make_pair(value1, value2)
*/

static void test() {

	// 创建队组
	pair<string, int> p(string("孙策"), 21);
	pair<string, int> p2 = make_pair(string("孙权"), 17);

	// 队组数据访问
	cout << p.first << " 今年 " << p.second << endl;
	cout << p2.first << " 今年 " << p2.second << endl;

}

int main51() {
	test();
	return 0;
}