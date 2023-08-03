#include"head.h"

/*
* �������������
* 
* ���ã��Զ����������
* 
*/

class Person24 {

	// ��Ԫ���� �Է���˽������
	friend ostream& operator<< (ostream& cout, Person24& p);

private:
	int m_A = 10;
	int m_B = 20;

	// ���ó�Ա���� �������������
	// ͨ��������ô����<<����Ϊ�޷�ʵ��cout�����
	// 
	// cout �Ǳ�׼�����(ostream)����ȫ��ֻ����һ��
	// ������Ϊ(istream)
	// ��������Ϊostream&��������cout����Ϊ����ʽ���
public:
	ostream& operator<< (ostream &cout) {	// cout Ҫ������
		cout << "p.m_A=" << this->m_A << " " << endl;
		cout << "p.m_B=" << this->m_B << " " << endl;
		return cout;
	}

};

// ͨ����Ա���� ����<<�����÷�ʽ
// ������ p.operator<<(cout)
static void test0() {
	Person24 p;
	p << cout;
}

// ��������Ϊostream&��������cout����Ϊ����ʽ���
ostream& operator<< (ostream &cout, Person24& p) {
	cout << "p.m_A=" << p.m_A << " " << endl;
	cout << "p.m_B=" << p.m_B << " " << endl;
	return cout;
}

// ֻ������ȫ�ֺ��� ����<<������ʱ����cout�����
// ������ operator<<(cout,p)
static void test1() {
	Person24 p;
	cout << p << endl;
}

int main24() {

	test0();
	test1();

	system("pause");
	return 0;
}