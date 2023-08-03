#include"head.h"

// �̳��� ͬ����̬��Ա�Ĵ���ʽ 
// 1��ͨ��������ʣ��� ͬ���Ǿ�̬��Ա һ��
// 2��ͨ����������

class Base34 {
public: 
	static int m_A;
	static void func() {
		cout << "Base func()" << endl;
	}
	static void func(int num) {
		cout << "Base func(int)" << endl;
	}
};

int Base34::m_A = 0;	// ��̬��Ա ���������������ʼ��

class Son34 : public Base34{
public:
	static int m_A;
	static void func() {
		cout << "Son func()" << endl;
	}
};

int Son34::m_A = 1;

// ͬ����̬��Ա����
static void test01() {
	Son34 son;

	// 1��ͨ���������
	cout << "Son::m_A = " << son.m_A << endl;
	cout << "Base::m_A = " << son.Base34::m_A << endl;

	// 2��ͨ����������
	cout << "Son::m_A = " << Son34::m_A<< endl;
	cout << "Base::m_A = " << Base34::m_A << endl;
	// ��һ��::��ʾͨ��Son��������
	// �ڶ���::��ʾBase34������
	cout << "Base::m_A = " << Son34::Base34::m_A << endl;
}

// ͬ����̬��Ա����
static void test02() {
	Son34 son;

	// 1��ͨ���������
	son.func();
	son.Base34::func();

	// 2��ͨ����������
	Son34::func();
	Base34::func();
	Son34::Base34::func();

	// ����ͬ�����������и���ͬ������������
	Son34::Base34::func(1);
}

int main34() {

	test01();

	system("pause");
	return 0;
}