#include<iostream>
using namespace std;


int main9() {

	// ������
	// 1�������� float  4�ֽ�  ��Ч����7λ
	// 2��˫���� double  8�ֽ�  ��Ч����15-16λ

	float f0 = 3.14;
	float f1 = 3.1415916f; // ������Ĭ��С����double���ͣ�����Ҫ�ں����f������ת��
						
	double d1 = 3.1415916; // c++Ĭ������� ���С��ʱ �����ʾ6λ��Ч����

	cout << "f1 = " << f1 << endl;
	cout << "d1 = " << d1 << endl;

	cout << "float ռ�õ��ڴ�ռ�(Byte)Ϊ��" << sizeof(float) << endl;
	cout << "double ռ�õ��ڴ�ռ�(Byte)Ϊ��" << sizeof(d1) << endl;


	// ��ѧ������
	float f2 = 3e2;  // 3 * 10^2  
	float f3 = 3e-2;  // 3 * 10^(-2)

	cout << "f2 = " << f2 << endl;
	cout << "f3 = " << f3 << endl;

	system("pause");

	return 0; 

} 