#include<iostream>
using namespace std;


int main8() {

	// sizeof() 
	// ���ã�ͳ������������ռ�ڴ�ռ�
	// �÷���sizeof(��������);sizeof(������);

	long num1 = 0;
	long long num2 = 0;

	cout << "short ������ռ���ڴ�ռ�Ϊ��" << sizeof(short) <<"�ֽ�" << endl;
	cout << "int ������ռ���ڴ�ռ�Ϊ��" << sizeof(int) << "�ֽ�" << endl;
	cout << "long ������ռ���ڴ�ռ�Ϊ��" << sizeof(num1) << "�ֽ�" << endl;
	cout << "longlong ������ռ���ڴ�ռ�Ϊ��" << sizeof(num2) << "�ֽ�" << endl;

	system("pause");

	return 0;

}