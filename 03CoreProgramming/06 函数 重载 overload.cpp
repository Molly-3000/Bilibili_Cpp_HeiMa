#include"head.h"

//
// ��������
// 
// ���ã�������������ͬ����ߺ����ĸ�����
// 
// ������1����������ͬ
//		 2��������������������ͬ��ͬȫ��/��/������
//		 3������������������ͬ������������/����/˳��ͬ��
// 
// ע�⣺���ÿ�����Ϊ��������
//

void func06() { cout << "This is func06()." << endl; }
// ������ͬ
void func06(int a, int b) { cout << "This is func06(int a, int b)." << endl; }
// ���Ͳ�ͬ
void func06(int a, double b) { cout << "This is func06(int a, double b)." << endl; }
// ˳��ͬ
void func06(double a, int b) { cout << "This is func06(double a, int b)." << endl; }

// int func06() { return 0; }	// �Ƿ����޷����� ������������ ���ֵ����غ���
int func06(double a, double b) { return 0; }	// �Ϸ�


// ������Ϊ��������
void func06(int& a) { cout << "This is func06(int &a)." << endl; }
void func06(const int& a) { cout << "This is func06(const int &a)." << endl; }

int main06() {

	func06();
	func06(0,0);
	func06(0, 0.0);
	func06(0.0, 0);

	func06(0.0, 0.0);

	cout << "======================" << endl;

	int a = 10;
	const int b = 10;

	func06(a);

	func06(b);
	func06(100); // const int &temp = 100; func06(temp);

	system("pause");
	return 0;
}