#include"head.h"

/*
* ����Ƕ������ 
* 
* ��ά����
*/

#include<vector>
#include<algorithm>

static void print_int(int val) {
	cout << val << endl;
}

static void print_vector_int(vector<int> &v) {
	for_each(v.begin(), v.end(), print_int);
}

static void test() {
	vector<vector<int>> vvint;

	// ����С����
	vector<int> vint1;
	vector<int> vint2;
	vint1.push_back(11);
	vint1.push_back(12);
	vint1.push_back(13);
	vint2.push_back(21);
	vint2.push_back(22);
	vint2.push_back(23);

	// ���ڲ��������뵽�ⲿ����
	vvint.push_back(vint1);
	vvint.push_back(vint2);

	for_each(vvint.begin(), vvint.end(), print_vector_int);

	for (vector<vector<int>>::iterator it = vvint.begin(); it != vvint.end(); it++) {
		// *it �������<>�ڵ����ݣ���vector<int>
		print_vector_int(*it);
	}

	for (vector<vector<int>>::iterator it = vvint.begin(); it != vvint.end(); it++) {
		for (vector<int>::iterator iit = (*it).begin(); iit != (*it).end(); iit++) {
			print_int(*iit);
		}
	}

}

int main20() {
	test();
	return 0;
}