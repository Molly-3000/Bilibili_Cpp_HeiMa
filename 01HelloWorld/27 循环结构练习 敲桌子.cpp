#include<iostream>
using namespace std;


// ������ ��7��[1,100]����������ʮλ���λ��7�ġ�����7�ı���
int main27() {
	
	int num = 1;
	bool a, b,c;

	while (num<=100) {
		a = num / 10 == 7;
		b = num % 10 == 7;
		c = num % 7 == 0;
		if (a || b || c) cout << "Knock Knock \n";
		else cout << num << endl;

		num++;
	}

	system("pause");
	return 0;
}