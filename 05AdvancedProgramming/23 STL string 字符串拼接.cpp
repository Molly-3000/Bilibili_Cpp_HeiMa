#include"head.h"
/*
* STL string �ַ���ƴ��
* 
* ���ܣ�ʵ���ַ���ĩβƴ���ַ���
* 
* ����ԭ�ͣ�
*	��string& oeprator+=(const char * s)
*	��string& operator+=(const string& s)
*	��string& operator+=(char c)
*	��string& append(const char * s)
*	��string& append(const string& s) 
*	��string& append(const char *s, int n)	// ĩβƴ��s��ǰn���ַ�
*	��string& append(const string& s,int pop,int n)	// ƴ��s��pop��ʼ��n������s[pop],��������s[pop+n-1]
*	��string& append(int n, char c)	// ƴ��n���ַ�c
*/

#include<string>
static void test() {
	string s1 = "s1";
	s1 += (" += (const char * s)");
	cout << s1 << endl;

	string s2 = "s2";
	s2 += (string(" += (const string& s)"));
	cout << s2 << endl;

	string s3 = "s3 += (const char c";
	s3 += (char(')'));
	cout << s3 << endl;

	string s4 = "s4";
	s4.append(".append(const char* s)");
	cout << s4 << endl;

	string s5 = "s5";
	s5.append(string(".append(const string& s)"));
	cout << s5 << endl;

	string s6 = "s6";
	s6.append(".append(const char* s,int n)31", 28);	// �ַ���Ĭ����'\n'Ϊ��β��ռһ���ַ�
	cout << s6 << endl;

	string s7 = "s7";
	s7.append(string(".append(const string& s, int pop, int n)43"), 0, 40);
	cout << s7 << endl;

	string s8 = "s8";
	s8.append(5, 's');
	cout << s8 << endl;

}

int main23() {
	test();
	return 0;
}