#include"head.h"

/*
* ��Ա���� �� ��Ա���� �� �ֿ��洢��
*/

class Person18 {

	int m_A;		// �Ǿ�̬��Ա������������Ķ���

	static int m_B; // ��̬��Ա��������������Ķ��󣬹���һ�ݣ��洢��static��

	void func() {}	// �Ǿ�̬��Ա�����������ڶ��󣬹���һ�ݣ��洢��

	static void func2() {}	// ��̬��Ա�����������ڶ���

};

int Person18::m_B = 0;

static void test01() {
	Person18 p;
	
	// �������ն���ռ�õ��ڴ�ռ�Ϊ��1
	// 
	// c++���������ô���ն���Ҳ����һ���ֽڵĿռ䣬Ϊ�����ֿն���ռ���ڴ��λ��
	// 
	// ��ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "The size of p = " << sizeof(p) << endl;
}

static void test02() {
	Person18 p;
	cout << "The size of p = " << sizeof(p) << endl;
}


int main18() {

	test02();

	system("pause");
	return 0;
}