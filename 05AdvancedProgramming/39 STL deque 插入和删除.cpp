#include"head.h"
/*
* STL deque �����ɾ��
* 
* ���˲��룺
*	��push_front()
*	��push_back()
*	��pop_fornt()
*	��pop_back()
* 
* ָ��λ�ò�����
*	��insert(const_it pos, T elem)
*	��insert(const_it pos,int n, T elem)
*	��insert(const_it pos, const_it start, const_it end)
* 	��erase(const_it pos)
*	��erase(const_it start, const_it end)
*	��clear()
*/

#include<deque>
static void print_deque(const deque<int>& dq) {
	cout << "deque :";
	for (deque<int>::const_iterator it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

static void test(){
	deque<int> dq(10,1);

	// ���˲���
	// ����
	dq.push_front(0);
	dq.push_back(9);
	print_deque(dq);

	// ɾ��
	dq.pop_front();
	dq.pop_back();
	print_deque(dq);

	// ָ��λ��
	// ����
	// insert(const_it pos, T elem)
	dq.insert(dq.begin() + 5, 2);
	print_deque(dq);

	// insert(const_it pos, int n, T elem)
	dq.insert(dq.begin() + 6, 4, 3);
	print_deque(dq);

	// insert(const_it pos, const_it start, const_it end)
	dq.insert(dq.begin() + 10, dq.begin(), dq.begin() + 5);
	print_deque(dq);

	// ɾ��
	// erase(const_it pos)
	dq.erase(dq.begin() + 5);
	print_deque(dq);

	// erase(const_it start, const_it end)
	dq.erase(dq.begin() + 5, dq.begin() + 14);
	print_deque(dq);

	dq.clear();
	print_deque(dq);
}

int main39() {
	test();
	return 0;
}