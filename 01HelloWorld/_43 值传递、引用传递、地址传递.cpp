#include "head.h"

// 值传递，不修改实参
void swap0(int a, int b) {

	int temp = a;
	a = b;
	b = temp;

}

// 引用传递，修改实参
void swap1(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;

}

// 地址传递，修改实参
void swap2(int* pa, int* pb) {

	int temp = *pa;
	*pa = *pb;
	*pb = temp;

}

// 地址传递
int main43() {

	int num1 = 111, num2 = 222;
	int* pNum1 = &num1, * pNum2 = &num2;

	cout << "before: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
	swap0(num1, num2);	    // 传值
	 
	cout << "after: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
	swap1(num1, num2);	    // 传引用


	cout << "after: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
	swap2(pNum1, pNum2);	// 传地址


	cout << "after: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;
	swap2(&num1, &num2);	// 传地址


	cout << "after: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;

	system("pause");

	return 0;
}