#include<iostream>
using namespace std;

int main19() {

	// �Ƚ������
	// ==    !=    <    >    <=    >=
	// ���ã����ڱ��ʽ�ıȽϣ�������һ����ֵ��1�����ֵ��0��

	int a = 1;
	float fa = 1.0f;
	double da = 1.0;
	bool ba = true;
	char ca = '1';
	string sa = "1";


	cout << (a == fa) << endl;    // 1
	cout << (a == da) << endl;    // 1
	cout << (fa == da) << endl;   // 1
	cout << (fa == ba) << endl;   // 1
	cout << (a == ca) << endl;    // 0

	cout << int(ca) << endl;      // 49
	cout << (ca == int(ca)) << endl;   // 1
	//cout << (a == sa) << endl;   // sa���ܱȽ�
	//cout << (ca == sa) << endl;


	system("pause");
	return 0;
}