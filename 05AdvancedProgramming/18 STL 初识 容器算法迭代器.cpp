#include"head.h"
/*
* STL �����㷨������ ��ʶ
* 
* Case��vector���������������
* 
*		����   --  vector
*		�㷨   --  for_each
*		������ --  vector<int>::iterator
* 
*/

#include<vector>
#include<algorithm>

static void myPrint(int val) {
	cout << val << endl;
}

static void test() {
	// ����һ��vector���������int����
	vector<int> vint;

	// �������в�������
	vint.push_back(11);
	vint.push_back(354);
	vint.push_back(53);
	vint.push_back(134);

	{
	// ͨ�����������������е�����
	// ��ʼ��������ָ�������е�һ��Ԫ��
	vector<int>::iterator itBegin = vint.begin();
	// ������������ָ�����������һ��Ԫ�ص� ��һ��λ��	!!!
	vector<int>::iterator itEnd = vint.end();

	// ��һ�ֱ�����ʽ
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}
	}

	// �ڶ��֣���for��huan
	for (vector<int>::iterator it = vint.begin(); it != vint.end(); it++) {
		cout << *it << endl;
	}

	// �����У���STL�㷨
	// for_each()������������ʼ������������������������
	//		�����ص�������Ҫд����
	for_each(vint.begin(), vint.end(), myPrint);
}

int main18() {

	test();

	system("pause");

	return 0;
}
