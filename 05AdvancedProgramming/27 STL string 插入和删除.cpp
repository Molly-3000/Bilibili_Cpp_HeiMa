#include"head.h"
/*
* STL string �����ɾ�� insert()��erase()
* 
* ���ܣ���string�ַ������в����ɾ���ַ��Ĳ���
* 
* ���뺯��ԭ�ͣ�
*	��string& insert(int pos,const char * s)
*	��string& insert(int pos,const string& str)
*	��string& insert(int pos, int n, char c)
* 
* ɾ������ԭ�ͣ�
*	��string& erase(int pos,int n=npos)		//ɾ����[pos]��ʼ��n���ַ�
*/

#include<string>
static void test_insert() {
	string str = "0123456789";
	cout << str << endl;

	str.insert(1, "aaa");	// ��ʼ���룬����str[pos]
	cout << str << endl;

	str.insert(4, string("bbb"));
	cout << str << endl;

	str.insert(7, 3, 'c');
	cout << str << endl;
}

static void test_erase() {
	string str = "abcdefg";
	cout << str << endl;
	str.erase(1, 3);
	cout << str << endl;
}

int main27() {
	test_insert();
	test_erase();
	return 0;
}