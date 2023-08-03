#include"head.h"
#include<string>
/*
* ��ģ����� ����������
* 
* ����ģ��ʵ�������Ķ��󣬿�����Ϊ��������
* 
* ���ִ��䷽ʽ��
*		1��ָ����������		ֱ��ָ���������������
*		2������ģ�廯		�������еĲ��� ��Ϊģ����д���
*		3��������ģ�廯		������������� ģ�廯���д���
* 
*		��һ�����
* 
* P.S. ��ʾ�����Ƶ��ĺ����� typeid(para).name();
*/

template<class NameType,class AgeType = int>
class Person11 {
public:
	Person11(NameType name, AgeType age) :m_name(name), m_age(age) {}
	void show() {
		cout << this->m_name << " is " << this->m_age << endl;
	}
	NameType m_name;
	AgeType m_age;
};

// 1��ָ�����������	ֱ����ʾ�������������
static void show1(Person11<string,int> &p) {
	cout << "This is show 1." << endl;
	p.show();
}

// 2������ģ�廯		�������еĲ��� ��Ϊģ����д���
template<class T>
void show2(Person11<T> &p) {
	cout << "This is show 2." << endl;
	p.show();
	cout << "type inference of T: " << typeid(T).name() << endl;
}

// 3��������ģ�廯		������������� ģ�廯���д���
template<class T>
void show3(T &p) {
	cout << "This is show 3." << endl;
	p.show();
	cout << "type inference of T: " << typeid(T).name() << endl;
}

static void test() {
	Person11<string> p("zhangsan", 18);

	show1(p);	// ��ʱ��ʾ����ָ��

	show2(p);	// ��ʱ�Զ��Ƶ� T Ϊ string

	show3(p);	// ��ʱ�Զ��Ƶ� T Ϊ Person<string,int>
}

int main11() {
	test();
	return 0;
}