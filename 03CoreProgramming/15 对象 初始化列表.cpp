#include"head.h"

/*
* ��ʼ���б�
*		���ڳ�ʼ����������
*	�﷨��
*		���캯��():attribute1(value1),attribute2(value2)...{}
*/

class Person15 {

public:

	// ���ó�ʼ���б� ��ʼ������
	Person15() :m_A(1), m_B(2), m_C(3) {}		// �޲ι���

	Person15(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}

	int m_A, m_B, m_C;
};

static void test01() {
	Person15 p(10, 20, 30);

	cout << " member attribute 1:" << p.m_A << endl;
	cout << " member attribute 2:" << p.m_B << endl;
	cout << " member attribute 3:" << p.m_C << endl;

}

int main15() {

	test01();

	system("pause");
	return 0;
}