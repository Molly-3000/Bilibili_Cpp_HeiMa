#include<iostream>
using namespace std;


int main7() {

	//����

	// 1��������  2 Byte  [-32768,32767]
	short num1 = 32768;

	// 2������    4 Byte  
	int num2 = 32768;

	// 3��������  4 Byte for Windows; 4 Byte for Linux32; 8 Byte for Linux64  
	long num3 = 32768;

	// 4����������   8 Byte
	long long num4 = 32768;

	cout << "short num1 = " << num1<<endl;
	cout << "int num2 = " << num2 << endl;
	cout << "long num3 = " << num3 << endl;
	cout << "long long num4 = " << num4 << endl;

	system("pause");

	return 0;
}