#include"head.h"
/*
* STL string �ַ������Һ��滻
* 
* ���ܣ�
*	����	����ָ���ַ����Ƿ����
*	�滻	��ָ����λ���滻�ַ���
* 
* ���Һ���ԭ�ͣ�
*	��int find(const string& str,int pos=0) const	
				// ����str��һ�γ���λ�ã���pos��ʼ����
*	��int find(const char *s, int pos=0)
				// ����s��һ�γ���λ�ã���pos��ʼ����
*	��int find(const char c,int pos=0)
				// ����c��һ�γ���λ�ã���pos��ʼ����
*	��int find(const char *s, int pos,int n)			!!!
				// ����s��ǰn���ַ���һ�γ���λ�ã���pos��ʼ����
*	��int rfind(const string& str,int pos=0) const
				// ����str���һ�γ���λ�ã���pos��ʼ����
*	��int rfind(const char *s, int pos=0)
				// ����s���һ�γ���λ�ã���pos��ʼ����
*	��int rfind(const char c,int pos=0)
				// ����c���һ�γ���λ�ã���pos��ʼ����
*	��int rfind(const char *s, int pos,int n)			!!!
				// ����s��ǰn���ַ����һ�γ���λ�ã���pos��ʼ��ǰ����
* 
* �滻����ԭ�ͣ�
*	��string& replace(int pos, int n, const string& str)
				// �滻��pos��ʼ��n���ַ�Ϊ �������ַ���str		!!!
*	��string& replace(int pos, int n, const char* s)
				// �滻��pos��ʼ��n���ַ�Ϊ �������ַ���str		!!!
* 
*/

#include<string>
static void test_find() {
	string str = "abcdefg1234567abcdefgabcdefg";

	int pos1 = str.find("de");			// int find(const char* s)
	int pos2 = str.find(string("ed"));	// int find(consts string& str)
	// δ�鵽���� -1

	int pos3 = str.find('d');			// int find(char c)
	int pos4 = str.find("123ed", 2, 3);	// int find(const char *s, int pos,int n)
	// ��str[2]��ʼ����s�е�ǰ�����ַ�

	// find �� rfind ����
	// rfind����������ң�find�������� ������
	int pos5 = str.rfind("abc");
	int pos6 = str.rfind(string("abc"));
	int pos7 = str.rfind('a');
	int pos8 = str.rfind("abc12", 2, 3);	
	// ������ң�������ƥ�䡣������˳��Ϊstr[2]��str[1]��str[0]
	
	cout << pos1 << " " << pos2 << " " << pos3 << " " << pos4 << endl;
	cout << pos5 << " " << pos6 << " " << pos7 << " " << pos8 << endl;
}

static void test_replace() {
	string str = "abcdefg";
	cout << str << endl;
	str.replace(2, 3, "111111");
	cout << str << endl;
	str.replace(2, 5, string("aa"));
	cout << str << endl;
}

int main24() {
	test_find();
	test_replace();
	return 0;
}