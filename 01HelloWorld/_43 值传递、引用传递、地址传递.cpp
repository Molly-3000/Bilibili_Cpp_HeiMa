#include "head.h"

// ֵ���ݣ����޸�ʵ��
void swap0(int a, int b) {

	int temp = a;
	a = b;
	b = temp;

}

// ���ô��ݣ��޸�ʵ��
void swap1(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;

}

// ��ַ���ݣ��޸�ʵ��
void swap2(int* pa, int* pb) {

	int temp = *pa;
	*pa = *pb;
	*pb = temp;

}

// ��ַ����
int main43() {

	int num1 = 111, num2 = 222;
	int* pNum1 = &num1, * pNum2 = &num2;

	cout << "before: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
	swap0(num1, num2);	    // ��ֵ
	 
	cout << "after: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
	swap1(num1, num2);	    // ������


	cout << "after: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
	swap2(pNum1, pNum2);	// ����ַ


	cout << "after: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
	swap2(&num1, &num2);	// ����ַ


	cout << "after: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;

	system("pause");

	return 0;
}