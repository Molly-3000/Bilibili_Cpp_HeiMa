#include<iostream>
using namespace std;

int main31() {

	// ��ת��� goto
	// ���ã�������������ת���   һ�㲻�� Ӱ������߼��ṹ
	// �﷨��goto �����
	// ��Ҫ�ӱ��

	cout << "111\n";

	cout << "222\n";
	goto FLAG;

	cout << "333\n";

	cout << "444\n";

	FLAG:
	cout << "555\n";

	system("pause");
	return 0;
}