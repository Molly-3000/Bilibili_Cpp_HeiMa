#include<iostream>
using namespace std;

int main15() {

	short a = 10;
	int b = 3;

	// ��������

	// �Ӽ��˳�

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl; 	// Ĭ�� int/int = int�� ��ȡ���������������룡��
							// ��� ������/���� ����float���߸����ֽڵ��������ͣ����Ϊfloat����ߵ���������
							// ��������Ϊ 0

	float fa = 10.0f;
	float fb = 3.0f;
	double da = 10.0;
	cout << a / fb << endl;
	cout << fa / b << endl;
	cout << sizeof(fa / b) << endl;
	cout << sizeof(fa / fb) << endl;
	cout << da / b << endl;
	cout << sizeof(da / fb) << endl;



	cout << sizeof(a - fb) << endl;
	fb = 2.0f;
	int result = a - fb;
	cout << sizeof(a - fb) << endl;



	cout << endl << endl;
	cout << "sizeof(a - a)��" << sizeof(a - a) << endl;
	cout << "sizeof(a / a)��" << sizeof(a / a) << endl;
	cout << "�˷�";
	cout << "sizeof(a * a)��" << sizeof(a * a) << endl;
	cout << "sizeof(a * b)��" << sizeof(a * b) << endl;
	cout << "sizeof(b * b)��" << sizeof(b * b) << endl;
	cout << "sizeof(fa * a)��" << sizeof(fa * a) << endl;
	cout << "sizeof(fa * fa)��" << sizeof(fa * fa) << endl;
	cout << "sizeof(da * fa)��" << sizeof(da * fa) << endl;
	cout << "sizeof(da * da)��" << sizeof(da * da) << endl;
	cout << "sizeof(a * da)��" << sizeof(a * da) << endl;

	system("pause");

	return 0;

}