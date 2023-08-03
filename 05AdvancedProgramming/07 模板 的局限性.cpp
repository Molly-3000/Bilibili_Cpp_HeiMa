#include "head.h"
#include <string>
/*
* ģ�� �ľ�����
* 
* ͨ�ò��������ܵģ���Щ�ض��������ͣ���Ҫ�ṩ����ʵ��
*						~~~~~~~~~~~~          ~~~~~~~~
*			���� ������������ �� ����/�Զ������� ��ģ�� ��������ͨ��
* 
* ͨ�����廯��ģ�壬���Խ���Զ������͵�ͨ�û�
*	  ~~~~~~
* P.S.ѧϰģ�岻��Ϊ��дģ�壬��Ϊ�˻���STL�е�ģ��
*/

class Person07 {
public:
	Person07(int age,string name):m_age(age),m_name(name) {}
	int m_age;
	string m_name;
};

template<class T>
bool myEqual(T& a, T& b) {
	return a == b;
}

//// 1�����������
//bool operator== (Person07 &p1, Person07 &p2) {
//	return (p1.m_age == p2.m_age && p1.m_name == p2.m_name);
//}

// 2�����þ��廯Person�������͵ĺ���ģ�壬���廯���ȵ���
template<> bool myEqual(Person07 &p1, Person07 &p2) {
	return (p1.m_age == p2.m_age && p1.m_name == p2.m_name);
}


static void test01() {
	int a = 10;
	int b = 20;
	bool ret = myEqual(a, b);
	if (ret) cout << "a = b" << endl;
	else cout << "a != b" << endl;
}

static void test02() {
	Person07 p1(10, "Tom");
	Person07 p2 = Person07(12, "Tom");
	p2 = p1;
	bool ret = myEqual(p1, p2);			// ��������廯ģ�壬����ʱ����
	if (ret) cout << "p1 = p2" << endl;
	else cout << "p1 != p2" << endl;
}

int main07() {
	test01();
	test02();
	return 0;
}