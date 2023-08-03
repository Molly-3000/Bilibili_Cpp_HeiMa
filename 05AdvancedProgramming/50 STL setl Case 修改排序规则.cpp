#include"head.h"
/*
* STL set ���� ����/�Զ����������� 
* 
* ע�⣺set�ڲ���ʱ���Զ���������
*		���Բ������źú�ı����������Ҫ�ڴ���ʱ��ָ������
*											 ~~~~
* �������º���
* 
*	P.S. bool operator() (int v1, int v2) const {}
*										  ~~~~~
*/

#include<set>

class MyCompare50 {
public:
	// �º�����������()����
	bool operator() (int v1, int v2) const{
		return v1 > v2;
	}
};

// ������������
static void test() {

	// Ĭ�Ϲ��죬Ԫ����������
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

	// ͨ���º���
	// ָ���������Ϊ����
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

// �Զ�����������
static void test_my() {
	set<Person50, PersonCompare> myS;

	myS.insert(Person50("�ﲮ��", 25)); //175
	myS.insert(Person50("����ı", 18)); //182
	myS.insert(Person50("����Զ", 31)); //169
	myS.insert(Person50("˾��ܲ", 21)); //179

	for (set<Person50>::iterator it = myS.begin(); it != myS.end(); it++) {
		cout << (*it).m_name << " is " << (*it).m_age << endl;
	}

}

int main50() {
	test();
	test_my();
	return 0;
}