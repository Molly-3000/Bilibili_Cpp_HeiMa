#include<iostream>
using namespace std;

int main24() {

	int num = 0;

	// 三种循环：do{循环语句;}while(条件表达式);  
	// while(条件表达式){循环语句;}   
	// for(起始表达式;条件表达式;末尾循环体) {循环语句;}

	while (num < 10) {
		cout << num << endl;
		num++;
	}

	do {
		num--;
		cout << num << endl;
	} while (num > 0);


	
	for (; num < 10; num++) {
		cout << num << endl;
	}

	// for循环可做拆分 等价于下面
	//for (; ; ) {
	//	if (num < 10) break;
	//	cout << num << endl;
	//	num++;
	//}

	system("pause");
	return 0;
}