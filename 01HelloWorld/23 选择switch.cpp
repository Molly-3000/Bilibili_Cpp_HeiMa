#include<iostream>
using namespace std;

int main23() {

	// switch语句

	int score;
	cin >> score;

	// switch 只能判断整型或字符型
	// 优点是 效率高
	switch (score) {
	case 10:
	case 9:
		cout << "满意" << endl;
		break;
	case 8:
	case 7:
		cout << "比较满意" << endl;
		break;
	case 6:
	case 5:
		cout << "一般" << endl;
		break;
	default:
		cout << "烂片" << endl;
		break;
	}


	system("pause");
	return 0;
}