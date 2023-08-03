#include<iostream>
using namespace std;


int main30() {

	// 跳转语句 break continue
	// break：退出当前循环结构或选择结构
	// continue：跳过本次循环下面的语句 继续下一次循环

	// 1、跳出switch
	int select;
	cin >> select;

	switch (select) {
	case 1: 
		cout << "difficult \n";
		break;
	case 2:
		cout << "normal \n";
		break;
	case 3:
		cout << "easy \n";
	}


	// 2、跳出循环语句

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 5) break;
			cout << i << j << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 5) continue;
			cout << i << j << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}