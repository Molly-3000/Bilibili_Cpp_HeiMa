#include<iostream>
using namespace std;

// ֵ���ݣ���������ʱ��ʵ�ε�ֵ���ݸ��β�
// 
// *** ֵ����ʱ���βεı仯��Ӱ��ʵ��
// 
// �βκ�ʵ���ǲ�ͬ�ĵ�ַ�ռ䣬������һ��ֵ����

void swap(int num1,int num2) {
	cout << "before: " << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "after: " << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	//return;    // void�������Բ�дreturn
}

int main39() {

	int a = 10;
	int b = 20;

	cout << "before: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	swap(a, b);
	cout << "after: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;


	system("pause");
	return 0;
}