#include<iostream>
using namespace std;

//给变量或常量命名时的规则

/*
1、不能是关键字
2、只能由数字、字母、下划线组成
3、开头不能是数字（第一个字符必须是字母或下划线）
4、标识符区分大小写

	命名最好见名知义
*/

int main6() {

	int _,ab,ab_,_Ab,a1b_, _1ab;

	_ = true;

	cout << "if valid: " << _ << endl;

	system("pause");

	return 0;
}