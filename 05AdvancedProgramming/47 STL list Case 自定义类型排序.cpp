#include"head.h"
/*
* STL Case for list
* 
* CD：将Person自定义数据类型进行排序，Person中成员属性有姓名、年龄、升高
* 
* SORT：年龄升序，如果年龄相同则按身高降序
* 
*/

#include<list>

class Person47 {
public:
	Person47(string name, int age, double height) {
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	double m_height;
};

static void print_list_Person(const list<Person47>& l) {
	cout << "Person list:" << endl;
	for (list<Person47>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << it->m_name << " " << it->m_age << " " << it->m_height << endl;
	}
	cout << endl;
}

static bool my_compare(Person47& p1, Person47& p2) {
	if (p1.m_age < p2.m_age) return true;
	if (p1.m_age > p2.m_age)return false;
	return p1.m_height > p2.m_height;
}

static void test() {
	list<Person47> lst;
	lst.push_back(Person47("zhangsan", 15, 1.65));
	lst.push_back(Person47("lisi", 17, 1.8));
	lst.push_back(Person47("wangwu", 15, 1.6));
	lst.push_back(Person47("zhaoliu", 18, 1.7));

	print_list_Person(lst);

	cout << "after sory by age↑ and height↓..." << endl;
	lst.sort(my_compare);
	print_list_Person(lst);

}

int main47() {
	test();
	return 0;
}