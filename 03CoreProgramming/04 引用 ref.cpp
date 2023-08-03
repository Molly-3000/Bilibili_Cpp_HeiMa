#include"head.h"

// 
// ����
// 
// ���ã������������������������ͬһ���ڴ�ռ�
//
// ���ʣ�������c++�ڲ�ʵ�־���һ������ָ�루const pointer������ָ��ָ��ĵ�ַ�ռ䲻��
//			e.g.	int& ref = a; ref = 20;
//					int * const ref = &a; *ref = 20;	// �������ڲ�ת��
// 
//					
// 
// �﷨����������& ���� = ԭ��;
// 
// ע�����1�����ñ����ʼ��		���� int &b;  //���Ϸ�
//					��ָ��Ϸ����ڴ�ռ䣨stack �� heap ��static����
//			 2�����ô����󣬲��ɸ��ģ��� b = c;  //���Ϸ�����ʱ = �Ǹ�ֵ
// 
// �÷���1����Ϊ��������
//				�ص㣺��������ʱ�������������������β�����ʵ��
//				�ŵ㣺��ָ�룬������Ҫͨ��ָ���޸�ʵ��
//						*���Σ��βεĸı�Ӱ��ʵ��
// 
//		 2����Ϊ��������ֵ
//				�ص㣺����Ҫ���ؾֲ�����������
//					  �������ĵ��ÿ�����Ϊ��ֵ
//										   ^ ^
//		 3����������
//				���ã���const�������ã���ֹ�βθı�ʵ��
//						const int& ref = a;
//						const int * const ref = &a; // �������ڲ�ת��
//						��ʱ a = 10: �Ϸ�
//							 ref = 10; ���Ϸ�
// 
// 
// 

// ������Ϊ��������
void yinyongchuandi(int& b) { b = 100; }

void dizhichuandi(int* b) { *b = 0; }

void zhichuandi(int b) { b = 1; }


// ������Ϊ��������ֵ
int& reflocal() {
	int a = 111;		// local���������ջ�����ᱻ�������Զ��ͷ�
	return a;
}

int& refstatic() {
	static int a = 222;		// static���������ȫ��/��̬�����������ʱOS����
	return a;
}

void constref(const int& ref) {
	//ref = 999;	// ���� �������ò����޸�
	cout << "ref = " << ref << endl;
}

int main04() {

	int a = 10;
	int& b = a;

	b = 20;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	zhichuandi(a);				// ֵ���ݣ��ββ�����ʵ��
	yinyongchuandi(a);			// ���ô��ݣ��β�����ʵ��
	dizhichuandi(&a);			// ��ַ���ݣ��β�����ʵ��

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	int c = 30;
	
	b = c;				// ��ֵ�������������޸�����
	//b = &c;			// ���Ϸ�����ʱ & ��ȡַ���ţ������޹�
	b = (int &)c;		// ��ֵ�������������޸�����
	
	c = 1000;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	cout << "================================" << endl;

	int& ref_local_a = reflocal();
	cout << "ref_local_a = " << ref_local_a << endl;	// ����������һ�α�����������һֱ����
	cout << "ref_local_a = " << ref_local_a << endl;
	cout << "ref_local_a = " << ref_local_a << endl;

	int& ref_static_a = refstatic();
	cout << "ref_static_a = " << ref_static_a << endl;
	cout << "ref_static_a = " << ref_static_a << endl;
	cout << "ref_static_a = " << ref_static_a << endl;

	// ��Ϊ��ֵ
	// ��������ֵa�����ջ������ref_static_a�ı���
	int& ref_static_a_2 = refstatic();
	refstatic() = 333;	// ������ a = 333��Ҳ���� ref_static_a = 333
	cout << "ref_static_a_2 = " << ref_static_a_2 << endl;
	cout << "ref_static_a_2 = " << ref_static_a_2 << endl;
	cout << "ref_static_a_2 = " << ref_static_a_2 << endl;

	cout << "================================" << endl;

	//int& ref = 10;		// ���Ϸ�

	const int& ref = 10;	//�Ϸ�
	// �������������Ϊ int temp =10; const int& ref = temp;

	return 0;
}