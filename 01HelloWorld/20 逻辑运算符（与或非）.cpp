#include<iostream>
using namespace std;

int main20() {

	// �߼������
	// ���ã��жϱ��ʽΪ�棨1����٣�0��
	
	// �߼��� ��
	int a = 10;
	cout << !a << endl;   // 0
	cout << !!a << endl;  // 1

	cout << 'a' << endl;   // a
	cout << !'a' << endl;  // 0


	cout << true << endl;  // 1

	// �߼��� &&
	cout << (a && a++) << endl;      // 1 
	cout << (a && (a-=11)) << endl;  // 0

	// �߼��� ||
	cout << (a || !a) << endl;       // 1

	system("pause");
	return 0;
}