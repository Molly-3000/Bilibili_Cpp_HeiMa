#include"head.h"
/*
* pair ��������
* 
* ���ܣ��ɶԳ��ֵ����ݣ����ö�������ú���������������
* 
* ������
*	��pair<type, type> p (value1,value2)
*	��pair<type, type> p = make_pair(value1, value2)
*/

static void test() {

	// ��������
	pair<string, int> p(string("���"), 21);
	pair<string, int> p2 = make_pair(string("��Ȩ"), 17);

	// �������ݷ���
	cout << p.first << " ���� " << p.second << endl;
	cout << p2.first << " ���� " << p2.second << endl;

}

int main51() {
	test();
	return 0;
}