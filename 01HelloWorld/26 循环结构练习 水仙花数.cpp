#include<iostream>
using namespace std;


// 水仙花数：是一个三位数，且每位上的数的三次方之和等于该数本身
// abc = a^3+b^3+c^3
int main26() {

	int num = 100;
	int a, b, c;

	do {
		a = num / 100;                // 取百位
		b = (num / 10) % 10;          // 取十位
		c = num % 10;                 // 取个位
		if (num == (pow(a,3) + pow(b,3) + pow(c,3))) cout << num << endl;
		num++;
	} while (num < 1000);

	system("pause");
	return 0;
}