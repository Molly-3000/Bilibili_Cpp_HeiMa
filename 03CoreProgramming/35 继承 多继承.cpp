#include"head.h"

/*
* ��̳У�һ��������Լ̳ж������
* 
* �﷨��
*		class ���� : �̳з�ʽ ����1, �̳з�ʽ ����2,... {} 
* 
* ע�⣺������ʹ�ö�̳У���Ϊ����֮�����׳���ͬ����Ա��
* 									����Ҫ��������������
* 
*/

class Base35_1 {
public:
	Base35_1() {
		m_A = 100;
	}
	int m_A;
};

class Base35_2 {
public:
	Base35_2() {
		m_B = 200;
	}
	int m_B;
};

class Son35 :public Base35_1, public Base35_2 {
public:
	Son35() {
		m_C = 300;
		m_D = 400;
	}
	int m_C, m_D;
};

static void test01() {
	Son35 son;
	cout << "sizeof son = " << sizeof(Son35) << endl;
}

int main35() {

	test01();

	system("pause");
	return 0;
}