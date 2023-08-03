#include<iostream>
using namespace std;

// 嵌套循环：循环中的循环
int main28() {

	// 打印10*10的星号矩阵
	// 外层执行一次 内层执行一周
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << "* ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}