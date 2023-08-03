#include "head.h"

int main42() {

	// 利用指针访问数组中的元素

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	
	int* p = arr;

	p = arr;

	cout << "利用指针访问第1个元素: " << *p << endl;  // 所以arr其实也是一个指针，指向数组首地址

	p++;	// 让指针向后偏移四个字节 ！

	cout << "利用指针访问第2个元素: " << *p << endl;

	// 利用指针遍历数组

	system("pause");

	return 0;
}