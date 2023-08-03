#include"head.h"
#include<string>
/*
* ��ģ�� ��Ա����������ʵ��
* 
* P.S. ֻ������ģ����ָ��ģ�������Ĭ��ֵ�������Ա�����������ɡ�
* 
*/

template<class T1,class T2 = int>
class Person13 {
public:
	Person13(T1 name,T2 age);
	void showInfo();
public:
	T1 m_name;
	T2 m_age;
};

// ��Ա���� ����ʵ��
template<class Ta,class Tb>
Person13<Ta,Tb>::Person13(Ta name, Tb age) {
	this->m_name = name;
	this->m_age = age;
}

template<class T1,class T2>
void Person13<T1, T2>::showInfo() {
	cout << "The age of " << this->m_name << " is " << this->m_age << "." << endl;
}

static void test() {
	Person13<string, int> p1("zhangsan", 16);
	Person13<string, int> p2 = Person13<string, int>("lisi", 135);
	Person13<string, int> p3 = p2;	// �������ṩ�Ŀ������캯��

	p1.showInfo();
	p2.showInfo();
	p3.showInfo();
}

int main13() {
	test();
	return 0;
}