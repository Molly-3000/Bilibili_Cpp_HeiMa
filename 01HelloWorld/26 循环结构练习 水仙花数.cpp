#include<iostream>
using namespace std;


// ˮ�ɻ�������һ����λ������ÿλ�ϵ��������η�֮�͵��ڸ�������
// abc = a^3+b^3+c^3
int main26() {

	int num = 100;
	int a, b, c;

	do {
		a = num / 100;                // ȡ��λ
		b = (num / 10) % 10;          // ȡʮλ
		c = num % 10;                 // ȡ��λ
		if (num == (pow(a,3) + pow(b,3) + pow(c,3))) cout << num << endl;
		num++;
	} while (num < 1000);

	system("pause");
	return 0;
}