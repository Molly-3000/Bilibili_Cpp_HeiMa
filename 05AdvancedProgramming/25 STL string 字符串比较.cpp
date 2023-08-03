#include"head.h"
/*
* STL string 字符串比较
* 
* 功能：按照顺序对字符的ASCII码进行对比
*		= 返回 0
*		> 返回 1
*		< 返回 -1
* P.S.通常用于比较两个字符串是否相等。
* 
* 函数原型：
*	·int compare(const string& str) const	
*	·int compare(const char* s) const		
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

	str_compare(s1, "1234");	// 注意长短

}

int main25() {
	test();
	return 0;
}
