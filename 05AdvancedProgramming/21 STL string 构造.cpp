#include"head.h"
/*
* string����
* 
* �������
* 
* 1��string��C++�����ַ�������������һ����
* 
* 2��string��char*������
*		char* ��һ��ָ�룬C�����е��ַ�������һ��char*
*		string ��һ���࣬���ڲ���װ��char*��������������ַ�����
				string������char*ΪԪ�ص�һ��������
* 
* 3��string�ص㣺
*		string���ڷ�װ�˺ܶ��Ա��������insert\delete\replace\find\copy
*		string�Զ�����char*��������ڴ棬���õ��ĸ�ֵԽ���ȡֵԽ�磬�����ڲ�����ά��
*			  ~~~~~~~~
* 4��string���캯��
*		  string();					// �����յ��ַ���
* 		��string(const string &s);	// �������죬ͨ��string������г�ʼ��
*		��string(const char * s);	// ͨ���ַ���s���г�ʼ��
* 		��string(int n,char c);		// ʹ��n���ַ�c���г�ʼ��
* 
*/

static void test() {
	string s1;						// Ĭ�Ϲ���
	const char* cstr = "cstr";
	string s2 = cstr;
	string s3 = "this is const char * s";
	string s4 = string("this is const string");
	string s5(5, 's');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

}

int main21() {
	test();
	return 0;
}