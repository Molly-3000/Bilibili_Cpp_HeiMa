#include"head.h"
/*
* STL vector Ԥ���ռ�
* 
* ���ܣ�����vector�ڶ�̬��չ����ʱ����չ����
* 
* ����ԭ�ͣ�
*	��reserve(int len)	// ����Ԥ��len��Ԫ�س���
			// Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
*/

#include<vector>
#include<algorithm>
static void print_int(int val) {
	cout << val << " ";
}

static void print_vector(vector<int> v) {
	cout << "vector : ";
	for_each(v.begin(), v.end(), print_int); // end()=size()
	cout << endl;
}

static void test() {
	vector<int> v;

	int count = 0;
	int* p = nullptr;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			count++;
		}
	}

	cout << "allocate times : " << count << endl << endl;

	vector<int> v2;
	v2.reserve(5);
	cout << "the capacity of v2 is " << v2.capacity() << endl;
	cout << "the size of v2 is " << v2.size() << endl << endl;

	int count2 = 0;
	p = NULL;
	for (int i = 0; i < 10; i++) {
		v2.push_back(i);
		if (p != &v2[0]) {
			p = &v2[0];
			count2++;
		}
	}
	cout << "allocate times : " << count2 << endl;
	cout << "the capacity of v2 is " << v2.capacity() << endl;
	cout << "the size of v2 is " << v2.size() << endl << endl;

	v2.reserve(5);	// ��ǰsize>reserve��reserve()��������
	cout << "the capacity of v2 is " << v2.capacity() << endl;
	cout << "the size of v2 is " << v2.size() << endl << endl;

	v2.reserve(15);	// ��ǰsize<reserveʱ��new capacity = reserve
	cout << "the capacity of v2 is " << v2.capacity() << endl;
	cout << "the size of v2 is " << v2.size() << endl;
}

int main35() {
	test();
	return 0;
}