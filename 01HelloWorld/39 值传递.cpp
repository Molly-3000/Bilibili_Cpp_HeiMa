#include<iostream>
using namespace std;

// 值传递：函数调用时，实参的值传递给形参
// 
// *** 值传递时，形参的变化不影响实参
// 
// 形参和实参是不同的地址空间，传递是一种值拷贝

void swap(int num1,int num2) {
	cout << "before: " << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "after: " << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	//return;    // void函数可以不写return
}

int main39() {

	int a = 10;
	int b = 20;

	cout << "before: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	swap(a, b);
	cout << "after: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;


	system("pause");
	return 0;
}