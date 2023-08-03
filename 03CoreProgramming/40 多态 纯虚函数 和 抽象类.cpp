#include "head.h"

/*
* ��̬ ���������ǳ�����
* 
* ���麯���ͳ�����
* 
* ���麯����û��ʵ�ֵ��麯��
*	�﷨�� virtual �������� ������ (�����б�) = 0;
* 
* �����ࣺ�������麯������
*	�ص㣺
*		���޷�ʵ��������
*		��������� ��д �������е� ���д��麯��
*/

// ������
// ���壺ֻҪ�������麯�������ǳ�����
// �ص㣺1���޷�ʵ����
//		 2�����������д �����еĴ��麯��
class Base40 {
public:
	virtual void func() = 0;		// ���麯��
};


class Son40:public Base40 {
public:
	// ������������࣬������д�����еĴ��麯��
	void func() {
		cout << "This is Son::func()." << endl;
	}
	static int m_static;
};

int Son40::m_static = 0;

static void test01() {
	
	//Base40 base;		// error�����麯���޷�ʵ����

	Son40 son;
	son.func();

	//son.m_static = 1;
	//cout << "get the static member via an object." << endl;
	//Son40::m_static = 2;
	//cout << "get the static member via the class." << endl;
}

int main40() {

	test01();

	system("pause");
	return 0;
}