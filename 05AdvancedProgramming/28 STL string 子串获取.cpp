#include"head.h"
/*
* STL string �Ӵ�
* 
* ���ܣ����ַ����н�ȡ������Ӵ�
* 
* ����ԭ�ͣ�
*	��string substr(int pos = 0,int n = npos) const 
			// ������[pos]��ʼ��n���ַ���ɵ��ַ���
*/

#include<string>

static void test() {
	string str = "abcd hello 1234";

	string subStr = str.substr(5, 5);

	cout << subStr << endl;
}

// ʹ�ó���
static void test02() {
	string str = "zhangsan@sina.com";
	cout << str << endl;

	int npos = str.find('@');
	string subStr = str.substr(0, npos);
	cout << subStr << endl;

	string subStr2 = str.substr(0, -9);		// c++ ��֧�ָ�����
	cout << subStr2 << endl;
}

int main28() {
	test();
	test02();
	return 0;
}