#include"head.h"

/*
* ������͸��� ���� ͬ����Աʱ
* 
* �������Ա(����/����)����ֱ�ӷ���
* �������Ա(����/����)����Ҫ�������� 
* 
* ע�⣺
*		��������г��ֺ͸���ͬ���ĳ�Ա������
*			����ĳ�Ա���������ص����������е�ͬ����Ա�������������أ�
*				���Է��ʸ����ͬ���������������صģ��������������
*/

class Base33 {
public:
	Base33() { m_A = 1; }
	void func() { cout << " This is Base func()." << endl; }
	void func(int a) { cout << " This is Base override func(int a)." << endl; }
	int m_A;
};

class Son33 :public Base33 {
public:
	Son33() { m_A = 2; }
	void func() { cout << " This is Son func()." << endl; }
	int m_A;
};

static void test01() {
	Son33 son;
	cout << "Son m_A=" << son.m_A << endl;			// �����Ա��ֱ�ӷ���
	cout << "Base m_A=" << son.Base33::m_A << endl;	// �����Ա����������
	son.func();
	son.Base33::func();

	//son.func(1);	// error�������е�ͬ���������������أ������������أ�����ֱ�ӵ���
	son.Base33::func(1);
}

int main33() {

	test01();

	system("pause");
	return 0;
}