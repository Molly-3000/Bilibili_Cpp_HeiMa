#include"head.h"

/*
* ��̬��Ա��������̬��Ա����
* 
* static��Ա������
*	�����ж�����ͬһ��	��������ĳ�����󣬿���ͨ���������������򣬷��ʣ�
*	���ڱ���׶η����ڴ�	����̬�������洢�ھ�̬ȫ������
*	�������������������ʼ��
* 
* static��Ա������
*	�����ж�����ͬһ��
*	��ֻ�ܷ���static��Ա��������Ϊû��thisָ�룬���Ǿ�̬������this->�ģ�
* 
*/

class Person17 {

public:
	static int m_A;		// ��������
	int m_B;			

	static void func1() {
		m_A *= 2;		// static��Ա���� ֻ�ܷ��� static��Ա����
		//m_B *= 2;		// error
	}

	// ����ͨ�����εķ�ʽ������ ��static����Ա�����������޷��޸ģ���Ϊû�з���Ȩ�ޣ�
	static void func3(int m_B) {
		cout << "static with non-static paramter." << endl;
	}

private:
	static int func2() { return 0; }
};

int Person17::m_A = 99;	// �����ʼ��

static void test01() {
	Person17 p1,p2;
	cout << p1.m_A << endl;

	p2.m_A = 100;
	cout << p1.m_A << endl;	// ��������

	cout << Person17::m_A << endl;
}

static void test02() {
	Person17 p;
	p.m_A = 2;
	cout << p.m_A << endl;

	p.func1();
	cout << p.m_A << endl;

	Person17::func1();
	cout << p.m_A << endl;

	//Person17::func2();  // error, private��Ա���� ���ɷ���
	
	Person17::func3(1);

}

int main17() {

	test01();

	system("cls");

	test02();

	system("pause");
	return 0;
}