#include<iostream>
using namespace std;

int main13() {

	// bool ������

	bool flag = true;

	cout << "true(��ֵ)�ı���Ϊ��" << flag << endl;
	cout << "false(��ֵ)�ı���Ϊ��" << false << endl;
	cout << "bool�����ݵĴ�СΪ��" << sizeof(true) << endl;

	flag = 111;
	cout << "�����ִ��ڵ���1ʱ��" << flag << endl;
	flag = -11;
	cout << "������С��0ʱ��" << flag << endl;

	// ���з�0��Ϊtrue��������1��false������0

	system("pause");

	return 0;
}