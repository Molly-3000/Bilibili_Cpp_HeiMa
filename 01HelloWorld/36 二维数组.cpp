#include<iostream>
using namespace std;

int main36() {

	// ��ά���� m��n��
	// ���巽ʽ��
	//		1���������� ������[m][n];
	//		2���������� ������[m][n] = {{x1y1,...,x1yn},{x2y1,...,x2yn},...,{xmy1,...,xmyn}};
	//		3���������� ������[m][n] = {x1y1,...,x1yn,x2y1,...,x2yn,...,xmy1,...,xmyn};
	//	*** 4���������� ������[][n] = {x1y1,...,x1yn,x2y1,...,x2yn,...,xmy1,...,xmyn};
	//  *** ����ʱ����ʡ������ ����ʡ������
	// 
	// ����������;��
	//		1�����Բ鿴����ռ���ڴ�ռ��С
	//		2�����Բ鿴��ά������׵�ַ
	//

	int a[2][3];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i*3 + j+1;
			cout << a[i][j];
		}
	}
	cout << endl;

	int a2[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i*3 + j;
			cout << a2[i][j];
		}
	}
	cout << endl;


	int a3[][3] = {
	{1,2,3},
	{4,5,6}
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i*3 + j;
			cout << a3[i][j];
		}
	}
	cout << endl;


	int a4[2][3] = { 1,2,3,4,5,6 };

	cout << "a4:" << a4 << endl;
	cout << "&a4[0]:" << &a4[0] << endl;
	cout << "a4[0]:" << a4[0] << endl; 
	cout << "&a4[0][0]:" << &a4[0][0] << endl;
	cout << endl;

	// a4   ��const int *�� �洢����a4[0][0]���׵�ַ,��a4=&a4[0][0]
	// a4[i] == a4+j*i == &a4[i][0]
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			*(a4[i]+j) = i*3 + j;
			//*(a4+i*3+j) = i * 3 + j;     // ������ ��Ȼ�����Ϻ�line 68�ȼ�   ���Ƿ�
			cout << a4[i][j];
		}
	}
	cout << endl;

	cout << "����arr1�׵�ַΪ��" << a << endl;
	cout << "����arr1�׵�ַΪ��" << &a[0][0] << endl;
	cout << "����arr1��СΪ��" << sizeof(a) << endl;
	cout << "����arr1��Ԫ�ظ���Ϊ��" << sizeof(a) / sizeof(a[0][0]) << endl;
	cout << "����arr1��һ�еĴ�СΪ��" << sizeof(a[0]) << endl;
	cout << "����arr1��һ�е�Ԫ�ظ���Ϊ��" << sizeof(a[0]) / sizeof(a[0][0]) << endl;
	cout << "����arr1��һ�еĴ�СΪ��" << sizeof(a[0][0]) * sizeof(a) / sizeof(a[0]) << endl;
	cout << "����arr1����Ϊ��" << sizeof(a) / sizeof(a[0]) << endl;
	cout << "����arr1����Ϊ��" << sizeof(a[0]) / sizeof(a[0][0]) << endl;

	system("pause");
	return 0;
}