#include"head.h"
/*
* STL �����㷨������ ��ʶ
*
* Case��vector����Զ�����������
*
*		����   --  vector
*		�㷨   --  for_each
*		������ --  vector<int>::iterator
*
*/
#include<vector>
#include<algorithm>

// �Զ�����������
class Person19 {
public:
	Person19(string name, int age) :mAge(age), mName(name) {}
	string mName;
	int mAge;
};

static void printPerson(Person19 &p) {
	cout << p.mName << " is " << p.mAge << "." << endl;
}

static void test() {
	vector<Person19> vperson;

	vperson.push_back(Person19("zhangsan", 12));
	vperson.push_back(Person19("lisi", 21));
	vperson.push_back(Person19("wangwu", 16));

	for_each(vperson.begin(), vperson.end(), printPerson);

}

static void printPerson2(Person19* p) {
	cout << p->mName << " is " << p->mAge << "." << endl;
}

static void test2() {
	vector<Person19*> vperson;

	Person19 p1("zhangsan", 12);
	Person19 p2 = Person19("lisi", 21);
	Person19 *p3 = new Person19("wangwu", 16);
	vperson.push_back(&p1);
	vperson.push_back(&p2);
	vperson.push_back(p3);
	vperson.push_back(new Person19("zhaoliu",11));

	for_each(vperson.begin(), vperson.end(), printPerson2);

}

int main19() {
	test();
	test2();
	return 0;
}
