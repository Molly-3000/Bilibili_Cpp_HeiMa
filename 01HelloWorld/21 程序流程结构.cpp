#include<iostream>
using namespace std;


int main21() {

	// �������ֻ��������̽ṹ��˳��ѡ��ѭ��

	int score,score2;

	cout << "�������ܷ֣���������";
	cin >> score;
	cout << "���������۷�������������";
	cin >> score2;


	//if (score > 600) cout << "��ϲ!" << endl;
	//else cout << "���ź���" << endl;


	// ������
	if (score > 650) {
		cout << "��ϲ!" << endl;
		if (score > 680) cout << "��һ��" << endl;
		else cout << "Top 5" << endl;
	}
	else if (score > 600) {
		cout << "������" << endl;
		if (score > 630) cout << "Top 10" << endl;
		else if (score > 610) cout << "985" << endl;
		else cout << "211";
	}
	else {
		cout << "���ź���" << endl;
	}

	system("pause");
	return 0;

}