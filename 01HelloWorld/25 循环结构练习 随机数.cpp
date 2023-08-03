#include<iostream>
using namespace std;

#include<ctime>

int main25() {

	// c++利用种子生成随机数 srand()
	// 根据当前系统时间生成随机数 防止每次随机都一样
	// 需要include <ctime>
	srand((unsigned int)time(NULL));

	// c++随机数  rand()
	int result = rand()%100;   // 生成[0-99]
	result++;
 
	int num;

	do {
		cin >> num;
		if (result > num) cout << "小了 \n";
		else if (result < num) cout << "大了 \n";
		else break;   // 在循环中 可以利用break 退出当前循环
	} while (1);
	cout << "恭喜！\n\n";

	result = rand() % 100 + 1;
	while (1) {
		cin >> num;
		if (result > num) cout << "小了 \n";
		else if (result < num) cout << "大了 \n";
		else break;
	}
	cout << "恭喜！\n";

	system("pause");

	return 0;

}