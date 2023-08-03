#include"head.h"
/*
* STL deque ����
* 
* ���ܣ����㷨��deque������������
* 
* �㷨ԭ�ͣ�
*	��sort(iterator start, iterator end)	// Ĭ�� ����
*		// ��start��end���䣬����ҿ�����Ԫ�ؽ�������
*		// ����֧��������ʵĵ���������������sort����
				��vector
*/

#include<deque>
#include<algorithm>
static void print_deque(const deque<int>& dq) {
	cout << "deque: ";
	for (deque<int>::const_iterator it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

static void test() {
	deque<int> dq;

	for (int i = 0; i < 10; i++) {
		dq.push_back(i);
		dq.push_front(i*2);
	}
	print_deque(dq);

	// ����
	sort(dq.begin(), dq.end());
	print_deque(dq);

}

int main41() {
	test();
	return 0;
}