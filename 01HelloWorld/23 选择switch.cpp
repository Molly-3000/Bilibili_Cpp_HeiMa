#include<iostream>
using namespace std;

int main23() {

	// switch���

	int score;
	cin >> score;

	// switch ֻ���ж����ͻ��ַ���
	// �ŵ��� Ч�ʸ�
	switch (score) {
	case 10:
	case 9:
		cout << "����" << endl;
		break;
	case 8:
	case 7:
		cout << "�Ƚ�����" << endl;
		break;
	case 6:
	case 5:
		cout << "һ��" << endl;
		break;
	default:
		cout << "��Ƭ" << endl;
		break;
	}


	system("pause");
	return 0;
}