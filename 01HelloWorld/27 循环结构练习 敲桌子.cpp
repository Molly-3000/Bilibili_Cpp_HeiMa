#include<iostream>
using namespace std;


// 敲桌子 跳7：[1,100]报数，跳过十位或各位有7的、跳过7的倍数
int main27() {
	
	int num = 1;
	bool a, b,c;

	while (num<=100) {
		a = num / 10 == 7;
		b = num % 10 == 7;
		c = num % 7 == 0;
		if (a || b || c) cout << "Knock Knock \n";
		else cout << num << endl;

		num++;
	}

	system("pause");
	return 0;
}