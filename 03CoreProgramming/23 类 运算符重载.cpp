#include"head.h"

/*
* ���������
* 
* ���ã������е�������������¶��壬������һ�ֹ��ܣ�����Ӧ��ͬ����������
* 
* �﷨���������� operator����� (�����б�) {}
* 
* ע�⣺��Ա����������������� �� ͨ��ȫ�ֺ�����������
*		1.��������д����ͬ
*		2.���÷�ʽ��ͬ�������ʲ�ͬ
* 
* 1�������������� �� ��������� ��������
* 2����Ҫ�������������
*  
*/

class Person23 {
public:
	int m_A;
	int m_B;

	//Person23 operator+ (Person23& p);	// ͨ����Ա��������+

};
//
//// ͨ����Ա��������+
//Person23 Person23::operator+(Person23& p) {
//	Person23 per;
//	per.m_A = this->m_A + p.m_A;
//	per.m_B = this->m_B + p.m_B;
//	return per;
//}

// ͨ��ȫ�ֺ�������+
Person23 operator+ (Person23& p1, Person23& p2) {
	Person23 per;
	per.m_A = p1.m_A + p2.m_A;
	per.m_B = p1.m_B + p2.m_B;
	return per;
}

// ��������� �� ��������
Person23 operator+ (Person23& p1, int num) {
	Person23 per;
	per.m_A = p1.m_A + num;
	per.m_B = p1.m_B + num;
	return per;
}

static void test01() {
	Person23 p1, p2, p3, p4;
	p1.m_A = 10;
	p1.m_B = 20;
	p2.m_A = 20;
	p2.m_B = 10;

	p3 = p1 + p2;
	//p4 = p1.operator+(p2);	// ͨ����Ա�������أ����õı���

	p4 = operator+(p1, p2);

	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
	cout << "p4.m_A = " << p4.m_A << endl;
	cout << "p4.m_B = " << p4.m_B << endl;

	Person23 p5 = p1 + 10;
	cout << "p5.m_A = " << p5.m_A << endl;
	cout << "p5.m_B = " << p5.m_B << endl;

}

int main23() {

	test01();

	system("pause");
	return 0;
}