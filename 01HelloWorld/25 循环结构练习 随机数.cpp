#include<iostream>
using namespace std;

#include<ctime>

int main25() {

	// c++����������������� srand()
	// ���ݵ�ǰϵͳʱ����������� ��ֹÿ�������һ��
	// ��Ҫinclude <ctime>
	srand((unsigned int)time(NULL));

	// c++�����  rand()
	int result = rand()%100;   // ����[0-99]
	result++;
 
	int num;

	do {
		cin >> num;
		if (result > num) cout << "С�� \n";
		else if (result < num) cout << "���� \n";
		else break;   // ��ѭ���� ��������break �˳���ǰѭ��
	} while (1);
	cout << "��ϲ��\n\n";

	result = rand() % 100 + 1;
	while (1) {
		cin >> num;
		if (result > num) cout << "С�� \n";
		else if (result < num) cout << "���� \n";
		else break;
	}
	cout << "��ϲ��\n";

	system("pause");

	return 0;

}