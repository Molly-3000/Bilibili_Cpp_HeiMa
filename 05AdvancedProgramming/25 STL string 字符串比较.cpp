#include"head.h"
/*
* STL string �ַ����Ƚ�
* 
* ���ܣ�����˳����ַ���ASCII����жԱ�
*		= ���� 0
*		> ���� 1
*		< ���� -1
* P.S.ͨ�����ڱȽ������ַ����Ƿ���ȡ�
* 
* ����ԭ�ͣ�
*	��int compare(const string& str) const	
*	��int compare(const char* s) const		
*/

#include<string>

template<class T>
static void str_compare(string str,T s) {
	if (str.compare(s) == 0) cout << str << " = " << s << endl;
	else if (str.compare(s) > 0) cout << str << " > " << s << endl;
	else cout << str << " < " << s << endl;
}

static void test() {
	string s1 = "123";
	
	str_compare(s1, "abc");
	str_compare(s1, string("123"));
	str_compare(s1, "111");

	str_compare(s1, "1234");	// ע�ⳤ��

}

int main25() {
	test();
	return 0;
}
