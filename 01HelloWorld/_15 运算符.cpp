#include<iostream>
using namespace std;

int main15() {

	short a = 10;
	int b = 3;

	// 算数运算

	// 加减乘除

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl; 	// 默认 int/int = int， 即取整（不是四舍五入！）
							// 如果 被除数/除数 中有float或者更高字节的数据类型，结果为float或最高的数据类型
							// 除数不能为 0

	float fa = 10.0f;
	float fb = 3.0f;
	double da = 10.0;
	cout << a / fb << endl;
	cout << fa / b << endl;
	cout << sizeof(fa / b) << endl;
	cout << sizeof(fa / fb) << endl;
	cout << da / b << endl;
	cout << sizeof(da / fb) << endl;



	cout << sizeof(a - fb) << endl;
	fb = 2.0f;
	int result = a - fb;
	cout << sizeof(a - fb) << endl;



	cout << endl << endl;
	cout << "sizeof(a - a)：" << sizeof(a - a) << endl;
	cout << "sizeof(a / a)：" << sizeof(a / a) << endl;
	cout << "乘法";
	cout << "sizeof(a * a)：" << sizeof(a * a) << endl;
	cout << "sizeof(a * b)：" << sizeof(a * b) << endl;
	cout << "sizeof(b * b)：" << sizeof(b * b) << endl;
	cout << "sizeof(fa * a)：" << sizeof(fa * a) << endl;
	cout << "sizeof(fa * fa)：" << sizeof(fa * fa) << endl;
	cout << "sizeof(da * fa)：" << sizeof(da * fa) << endl;
	cout << "sizeof(da * da)：" << sizeof(da * da) << endl;
	cout << "sizeof(a * da)：" << sizeof(a * da) << endl;

	system("pause");

	return 0;

}