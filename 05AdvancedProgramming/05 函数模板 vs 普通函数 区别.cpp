#include"head.h"

/*
* ����ģ�� �� ��ͨ���� ������
* 
* 1����ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
* 2������ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
* 3������ģ�����ʱ�����������ʽ����ָ�������Է�����ʽ����ת��
* 
*	����ָ�� VS �����Ƶ� VS ����ת��
* 
* P.S. ����ʹ�ú���ģ��ʱ����ʾָ������
*/

// 1����ͨ��������ʽ����ת��
int myAdd01(int a, int b) {
	return a + b;
}
static void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';

	cout << myAdd01(a, b) << endl;
	cout << myAdd01(a, c) << endl;	// �ַ�c ת��Ϊ ��ASCII��
}

// ����ģ��
template<typename T>
T addT(T a, T b) {
	return a + b;
}
static void test02() {
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << addT(a, b) << endl;
	// 2���Զ������Ƶ�ʱ��������ʽ����ת��
	//cout << addT(a, c) << endl;  // error,û��������б�ƥ��� ����ģ�� ʵ��
	cout << addT(a, int(c)) << endl;
	
	// 3����ʽָ������ʱ��������ʽ����ת��
	cout << addT<int>(a, c) << endl;
}

int main05() {
	test01();
	test02();
	
	return 0;
}