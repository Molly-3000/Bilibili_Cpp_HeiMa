#include<iostream>
using namespace std;

int main22() {

	int pigs[] = {0,0,0};

	int i = 0;
	do {
		cout << "请输入小猪" << char(i + 65) << "的体重：";
		cin >> pigs[i];
		i++;
	} while (i < 3);

	cout << pigs[0] << "   \t" << pigs[1] << "   \t" << pigs[2] << "   \n";


	// 三目运算符  ？：
	i = pigs[0] > pigs[1] ? (pigs[0] > pigs[2] ? 0 : 2) : (pigs[1] > pigs[2] ? 1 : 2);
	cout << "小猪" << char(i + 65) << "最重，可以毕业！\n";
	i = pigs[0] > pigs[1] ? (pigs[1] > pigs[2] ? 2 : 1) : (pigs[2] > pigs[0]? 0 :2 );
	cout << "小猪" << char(i + 65) << "最轻，可以毕业！\n";
	i = pigs[0] > pigs[1] ? (pigs[1] > pigs[2] ? 1 : (pigs[0] > pigs[2] ? 2 : 0)) : (pigs[1] > pigs[2] ? (pigs[0] > pigs[2] ? 0 : 2) : 1);
	cout << "小猪" << char(i + 65) << "中等，可以毕业！\n";

	// 三目运算符 返回的结果是变量 可以继续赋值
	// 所以三目运算可以作为 左值 也可以作为 右值
	pigs[0] > pigs[1] ? pigs[0] : pigs[1] = 0;
	cout << pigs[0] << "   \t" << pigs[1] << "   \t" << pigs[2] << "   \n";


	// 同时出现时 先后顺序？？
	pigs[0] > pigs[1] ? pigs[0] : pigs[1] = pigs[0] > pigs[1] ? pigs[1] : pigs[0];
	cout << pigs[0] << "   \t" << pigs[1] << "   \t" << pigs[2] << "   \n";

	system("pause");
	return 0;
}