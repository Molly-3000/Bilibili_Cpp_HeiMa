#include"head.h"
/*
* STL vector ���ݴ�ȡ	(���˵�����)
* 
* ����ԭ�ͣ�
*	��operator[]		// 
*	��at(int idx)		//
*	��front()			// ���������е�һ��Ԫ��
*	��back()			// �������������һ��Ԫ��
*/

#include<vector>

static void test() {
	vector<int> v;

	v.assign(10, 1);

	v.push_back(999);

	v.insert(v.begin(), 0);

	// ͨ��operator[] ����
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// ͨ��at()����
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;

	// front() ���ص�һ��Ԫ��
	cout << "the first element is " << v.front() << endl;

	// back() �������һ��Ԫ��
	cout << "the last element is " << v.back() << endl;
}

int main33() {
	test();
	return 0;
}