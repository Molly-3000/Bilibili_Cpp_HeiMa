#include"head.h"
/*
* STL string �ַ���ȡ
* 
* �����ַ���ȡ��ʽ������ԭ�ͣ���
*	��char& operator[] (int n)	// ͨ��[n]�±��ȡ
*	��char& at(int n)			// ͨ��at(n)������ȡ
* 
*/

static void test() {
	string str = "hello";

	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i);
	}
	cout << endl;

	cout << str[str.size()] << endl;		// ����������null

	str[0] = '0';
	str.at(3) = 'k';
	cout << str << endl;
}

int main26() {
	test();
	return 0;
}