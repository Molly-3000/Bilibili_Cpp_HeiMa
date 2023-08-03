#include<iostream>
using namespace std;


int main21() {

	// 程序三种基本的流程结构：顺序、选择、循环

	int score,score2;

	cout << "请输入总分（整数）：";
	cin >> score;
	cout << "请输入理综分数（整数）：";
	cin >> score2;


	//if (score > 600) cout << "恭喜!" << endl;
	//else cout << "很遗憾。" << endl;


	// 多条件
	if (score > 650) {
		cout << "恭喜!" << endl;
		if (score > 680) cout << "世一大！" << endl;
		else cout << "Top 5" << endl;
	}
	else if (score > 600) {
		cout << "还不错。" << endl;
		if (score > 630) cout << "Top 10" << endl;
		else if (score > 610) cout << "985" << endl;
		else cout << "211";
	}
	else {
		cout << "很遗憾。" << endl;
	}

	system("pause");
	return 0;

}