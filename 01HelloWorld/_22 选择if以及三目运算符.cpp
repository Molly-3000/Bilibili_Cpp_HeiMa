#include<iostream>
using namespace std;

int main22() {

	int pigs[] = {0,0,0};

	int i = 0;
	do {
		cout << "������С��" << char(i + 65) << "�����أ�";
		cin >> pigs[i];
		i++;
	} while (i < 3);

	cout << pigs[0] << "   \t" << pigs[1] << "   \t" << pigs[2] << "   \n";


	// ��Ŀ�����  ����
	i = pigs[0] > pigs[1] ? (pigs[0] > pigs[2] ? 0 : 2) : (pigs[1] > pigs[2] ? 1 : 2);
	cout << "С��" << char(i + 65) << "���أ����Ա�ҵ��\n";
	i = pigs[0] > pigs[1] ? (pigs[1] > pigs[2] ? 2 : 1) : (pigs[2] > pigs[0]? 0 :2 );
	cout << "С��" << char(i + 65) << "���ᣬ���Ա�ҵ��\n";
	i = pigs[0] > pigs[1] ? (pigs[1] > pigs[2] ? 1 : (pigs[0] > pigs[2] ? 2 : 0)) : (pigs[1] > pigs[2] ? (pigs[0] > pigs[2] ? 0 : 2) : 1);
	cout << "С��" << char(i + 65) << "�еȣ����Ա�ҵ��\n";

	// ��Ŀ����� ���صĽ���Ǳ��� ���Լ�����ֵ
	// ������Ŀ���������Ϊ ��ֵ Ҳ������Ϊ ��ֵ
	pigs[0] > pigs[1] ? pigs[0] : pigs[1] = 0;
	cout << pigs[0] << "   \t" << pigs[1] << "   \t" << pigs[2] << "   \n";


	// ͬʱ����ʱ �Ⱥ�˳�򣿣�
	pigs[0] > pigs[1] ? pigs[0] : pigs[1] = pigs[0] > pigs[1] ? pigs[1] : pigs[0];
	cout << pigs[0] << "   \t" << pigs[1] << "   \t" << pigs[2] << "   \n";

	system("pause");
	return 0;
}