#include<iostream>
using namespace std;


int main30() {

	// ��ת��� break continue
	// break���˳���ǰѭ���ṹ��ѡ��ṹ
	// continue����������ѭ���������� ������һ��ѭ��

	// 1������switch
	int select;
	cin >> select;

	switch (select) {
	case 1: 
		cout << "difficult \n";
		break;
	case 2:
		cout << "normal \n";
		break;
	case 3:
		cout << "easy \n";
	}


	// 2������ѭ�����

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 5) break;
			cout << i << j << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 5) continue;
			cout << i << j << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}