#include"head.h"
#include<string>
/*
* ��ģ�� ���ļ���д
* 
* ���⣺��ģ���У���Ա�����Ĵ���ʱ���ǵ��ý׶�
*			���Է��ļ���д�������Ӳ�����ģ��ĳ�Ա����
* 
* ��������ַ�ʽ
*		1��ֱ�Ӱ���(ʵ���˳�Ա������)cppԴ�ļ�		����cpp���Ӹ�cpp����hpp��
*		2����������ʵ��д��ͬһ���ļ��У������ļ���׺��Ϊ.hpp		����cppֱ������hpp��
*			 ~~~~~~~~~~	   ~~~~~~~~~~					 ~~~~~
*/
#include"14 person.cpp"
#include"14 class template head.hpp"

static void test() {
	Person14<string> p1("zhangsan", 16);
	Person14<string> p2 = p1;
	Person14<string> p3 = Person14<string>("lisi", 16);
	p1.showInfo();
	p2.showInfo();
	p3.showInfo();
}

int main14() {
	test();
	return 0;
}
