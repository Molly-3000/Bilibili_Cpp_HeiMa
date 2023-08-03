#include"head.h"
/*
* STL set 排序 内置/自定义数据类型 
* 
* 注意：set在插入时，自动排序（升序）
*		所以不能在排好后改变排序规则，需要在创建时就指定规则
*											 ~~~~
* 方法：仿函数
* 
*	P.S. bool operator() (int v1, int v2) const {}
*										  ~~~~~
*/

#include<set>

class MyCompare50 {
public:
	// 仿函数，即重载()符号
	bool operator() (int v1, int v2) const{
		return v1 > v2;
	}
};

// 内置数据类型
static void test() {

	// 默认构造，元素升序排列
	set<int> s1;

	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// 通过仿函数
	// 指定排序规则为降序
	set<int, MyCompare50> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(50);
	s2.insert(30);

	for (set<int, MyCompare50>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}


class Person50 {
public:
	Person50(string name, int age):m_age(age),m_name(name) {}
	string m_name;
	int m_age;
};

class PersonCompare {
public:
	bool operator() (const Person50& p1,const Person50& p2) const{
		return p1.m_age < p2.m_age;
	}
};

// 自定义数据类型
static void test_my() {
	set<Person50, PersonCompare> myS;

	myS.insert(Person50("孙伯符", 25)); //175
	myS.insert(Person50("孙仲谋", 18)); //182
	myS.insert(Person50("张文远", 31)); //169
	myS.insert(Person50("司马懿", 21)); //179

	for (set<Person50>::iterator it = myS.begin(); it != myS.end(); it++) {
		cout << (*it).m_name << " is " << (*it).m_age << endl;
	}

}

int main50() {
	test();
	test_my();
	return 0;
}