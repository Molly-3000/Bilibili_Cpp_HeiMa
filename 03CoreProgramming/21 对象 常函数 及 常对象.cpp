#include"head.h"

/*
* ��������const���εĳ�Ա����
* 
*	�ص㣺const���εĳ�Ա�����������޸ĳ�Ա����
*			�����Ҫ�����������޸ĳ�Ա��������Ҫ��mutable�ؼ������γ�Ա����
* 
* ������const���εĶ���
*	
*	�ص㣺1.�����󣬲������޸ĳ�Ա����
*			�����Ҫ�����������޸ĳ�Ա��������Ҫ��mutable�ؼ������γ�Ա����
* 
*		  2.������ֻ�ܵ��ó���������Ϊ�˷�ֹ�ǳ������޸ĳ�Ա������
*/

class Person21 {
public:
	// thisָ��ı�����const pointer��ָ���ָ�򲻱�
	// �������ı��ʾ���const pointer to const,thisָ��ָ���ֵҲ����
	void showPerson() const {
		//m_A = 100;	// �ȼ��� this->m_A = 100;
		m_B = 100;
	}

	void func() {
	}

	int m_A;			// �����������޸�
	mutable int m_B;	// �����������޸�
};

static void test01() {
	Person21 p;
	p.showPerson();
}

static void test02() {
	const Person21 p;
	//p.func();	// error���������ܵ��÷ǳ�����
	p.showPerson();
}

int main21() {

	test01();

	test02();

	system("pause");
	return 0;
}