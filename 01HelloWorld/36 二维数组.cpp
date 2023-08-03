#include<iostream>
using namespace std;

int main36() {

	// 二维数组 m行n列
	// 定义方式：
	//		1、数据类型 数组名[m][n];
	//		2、数据类型 数组名[m][n] = {{x1y1,...,x1yn},{x2y1,...,x2yn},...,{xmy1,...,xmyn}};
	//		3、数据类型 数组名[m][n] = {x1y1,...,x1yn,x2y1,...,x2yn,...,xmy1,...,xmyn};
	//	*** 4、数据类型 数组名[][n] = {x1y1,...,x1yn,x2y1,...,x2yn,...,xmy1,...,xmyn};
	//  *** 定义时可以省略行数 不能省略列数
	// 
	// 数组名的用途：
	//		1、可以查看数组占用内存空间大小
	//		2、可以查看二维数组的首地址
	//

	int a[2][3];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i*3 + j+1;
			cout << a[i][j];
		}
	}
	cout << endl;

	int a2[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i*3 + j;
			cout << a2[i][j];
		}
	}
	cout << endl;


	int a3[][3] = {
	{1,2,3},
	{4,5,6}
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = i*3 + j;
			cout << a3[i][j];
		}
	}
	cout << endl;


	int a4[2][3] = { 1,2,3,4,5,6 };

	cout << "a4:" << a4 << endl;
	cout << "&a4[0]:" << &a4[0] << endl;
	cout << "a4[0]:" << a4[0] << endl; 
	cout << "&a4[0][0]:" << &a4[0][0] << endl;
	cout << endl;

	// a4   是const int *， 存储的是a4[0][0]的首地址,即a4=&a4[0][0]
	// a4[i] == a4+j*i == &a4[i][0]
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			*(a4[i]+j) = i*3 + j;
			//*(a4+i*3+j) = i * 3 + j;     // ！！！ 虽然理论上和line 68等价   但非法
			cout << a4[i][j];
		}
	}
	cout << endl;

	cout << "数组arr1首地址为：" << a << endl;
	cout << "数组arr1首地址为：" << &a[0][0] << endl;
	cout << "数组arr1大小为：" << sizeof(a) << endl;
	cout << "数组arr1的元素个数为：" << sizeof(a) / sizeof(a[0][0]) << endl;
	cout << "数组arr1第一行的大小为：" << sizeof(a[0]) << endl;
	cout << "数组arr1第一行的元素个数为：" << sizeof(a[0]) / sizeof(a[0][0]) << endl;
	cout << "数组arr1第一列的大小为：" << sizeof(a[0][0]) * sizeof(a) / sizeof(a[0]) << endl;
	cout << "数组arr1行数为：" << sizeof(a) / sizeof(a[0]) << endl;
	cout << "数组arr1列数为：" << sizeof(a[0]) / sizeof(a[0][0]) << endl;

	system("pause");
	return 0;
}