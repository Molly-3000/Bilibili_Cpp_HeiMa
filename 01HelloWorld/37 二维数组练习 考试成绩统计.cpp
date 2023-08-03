#include<iostream>
using namespace std;

#include<string>

int main37() {

	int scores[3][3] = {
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};

	string names[3] = { "张三","李四","王五" };

	int sums[3];

	for (int i = 0; i < sizeof(scores) / sizeof(scores[0]); i++) {
		sums[i] = 0;
		for (int j = 0; j < sizeof(scores[0]) / sizeof(scores[0][0]); j++) {
			sums[i] += scores[i][j];
		}

		cout << names[i] << "的总成绩为：" << sums[i] << endl;

	}

	system("pause");
	return 0;
}
