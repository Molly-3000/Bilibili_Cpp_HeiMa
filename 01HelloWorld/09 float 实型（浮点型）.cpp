#include<iostream>
using namespace std;


int main9() {

	// 浮点型
	// 1、单精度 float  4字节  有效数字7位
	// 2、双精度 double  8字节  有效数字15-16位

	float f0 = 3.14;
	float f1 = 3.1415916f; // 编译器默认小数是double类型，所以要在后面加f，进行转换
						
	double d1 = 3.1415916; // c++默认情况下 输出小数时 最多显示6位有效数字

	cout << "f1 = " << f1 << endl;
	cout << "d1 = " << d1 << endl;

	cout << "float 占用的内存空间(Byte)为：" << sizeof(float) << endl;
	cout << "double 占用的内存空间(Byte)为：" << sizeof(d1) << endl;


	// 科学计数法
	float f2 = 3e2;  // 3 * 10^2  
	float f3 = 3e-2;  // 3 * 10^(-2)

	cout << "f2 = " << f2 << endl;
	cout << "f3 = " << f3 << endl;

	system("pause");

	return 0; 

} 