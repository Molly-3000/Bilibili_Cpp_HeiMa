#include<iostream>
using namespace std;

// ���飺��ͬ��������Ԫ�صļ���
// �ص㣺1.ÿ�����ݶ�����ͬ����������     ��ͬ��������  ���ݿ��ظ�
//		 2.����ռ�ݵ�ʱ�������ڴ�ռ�     �����ڴ�ռ�
//		 
//	**** 3.��������ʱ�����г�ʼ���� ***
// 
// ���巽��������̬���飩
//1���������� ������[���鳤��];
//2���������� ������[] = {ֵ1��ֵ2����������ֵn}��
//3���������� ������[���鳤��] = { ֵ1��ֵ2����������ֵn }��

#include<string>

int main32() {

	int iarr[5];
	// ����������;��
	// 1. sizeof(������)���ɵõ���������ռ�õĿռ��С
	// 2. ��ʾ������ڴ��ַ
	// �������ǳ��� ���ܸ�ֵ

	cout << "�����С��" << sizeof(iarr) << endl;
	cout << "�����׵�ַ��" << iarr << endl;
	cout << "�����һ��Ԫ�ص�ַ��" << &iarr[0] << endl;   // &Ϊȡַ����

	for (int i = 0; i < 5; i++) iarr[i] = i;

	for (int i = 0; i < 5; i++) {
		cout << iarr[i];
	}
	cout << endl;

	char charr[] = { 'a','b','c' };
	for (int i = 0; i < sizeof(charr)/sizeof(char); i++) {
		cout << charr[i];
	}
	cout << endl;

	string starr[4] = { "abc","bca","cab" };  //ָ�����ȵ�û�г�ʼ��ʱ�����Զ����

	for (int i = 0; i < sizeof(starr)/sizeof(starr[0]); i++) {
		cout << starr[i]<<endl;
	}


	system("pause");
	return 0;
}