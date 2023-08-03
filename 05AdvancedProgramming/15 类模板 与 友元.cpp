#include"head.h"
#include<string>
/*
* ��ģ�� �� ��Ԫ����
* 
* ��Ԫ��������ĳ�Ա�������Է������˽�С�������Ա
* 
* ȫ�ֺ���������ʵ�֣�
*		ȫ�ֺ���ֱ������������+ʵ��
* 
* ȫ�ֺ���������ʵ�֣�
*		1����Ҫ�ñ�������ǰ֪�� ��ģ��
*		2����Ҫ�ñ�������ǰ֪�� ����ģ��
*		3����ģ��Ķ���	+ �����Ԫ��Ҫ�ӿ�ģ������б�����
*		4��ȫ�ֺ���������ʵ��
* 
*/


template<class T1, class T2>
class Person15;

template<class T1, class T2>
void printPerson2(Person15<T1, T2>& p);

template<class T1,class T2>
class Person15 {
public:
	Person15(T1 name, T2 age) :m_name(name), m_age(age) {}

	// ��Ԫ����������ʵ��
	friend void printPerson1(Person15<T1, T2>& p) {
		cout << "This is friend func definited outside the class." << endl;
	}

	// ��Ԫ����������ʵ��
	// ��Ҫ��� ��ģ������б�
	friend void printPerson2<>(Person15<T1, T2>& p);

private:
	T1 m_name;
	T2 m_age;

};

// ����ʵ��
// ע�� ����һ��ģ�庯��
template<class T1, class T2>
void printPerson2(Person15<T1, T2>& p) {
	cout << "This is friend definited outside the class."<<endl;
}

static void test() {
	Person15<string, int> p1("zhangsan", 15);
	printPerson1(p1);
	printPerson2(p1);
}

int main15() {
	test();
	return 0;
}