#include"head.h"
/*
* STL deque ����
* 
* 1����������
* 
*	���ܣ�˫�����飬ͷ����β�������Խ��в����ɾ��	
*		  ~~~~~~~~
*	deque��vector ����
*		��vector����ͷ���Ĳ���ɾ�����������������ƶ���Ч�ʵͣ�������Խ��Ч��Խ��
*		��deque��ͷ���Ĳ���ɾ���ٶȱ�vector��
*		��vector����Ԫ�ص��ٶȱ�deque�죬������ߵ��ڲ�ʵ���й�
*		  ~~~~~~				~~~~~~
*	  �������ڴ�ռ�		�������Ļ����������п�������
* 
*	deque���ڲ�����ԭ��
*		deque�ڲ���һ���п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
*					   ~~~~~~		   ~~~~~~
*		�п���ά��ÿ���������ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�
* 
*	deque�����ĵ�����Ҳ��������ʵ�����
* 
* 2��deque ���캯��
*	
*	����ԭ�ͣ�
*		��deque<T> deqT					// �޲ι���
*		��deque(const deque<T>& deq)	// ��������
*		��deque(const_iterator begin, const_it end) // ����ҿ�������Ԫ��
*		��deque(int n, T elem)			// n��elem����
* 
*/

#include<deque>
#include<algorithm>

static void print_int(int val) {
	cout << val << " ";
}

static void print_deque_int(const deque<int>& dq) {
	cout << "deque: ";

	//for_each(dq.begin(), dq.end(), print_int);

	// const_iterator ֻ���������������ڵ����ݲ����޸�
	for (deque<int>::const_iterator it = dq.begin(); it != dq.end(); it++) {
		print_int(*it);
	}

	cout << endl << endl;
}

static void test() {
	// �޲ι���
	deque<int> deq1;
	deq1.push_back(1);
	deq1.push_back(2);
	deq1.push_front(0);
	print_deque_int(deq1);

	// ��������
	deque<int> deq2(deq1);
	print_deque_int(deq2);

	// ��������ָ���䣬����ҿ�������Ԫ��
	deque<int> deq3(deq1.begin(), deq1.end());
	print_deque_int(deq3);

	// n��elem
	deque<int> deq4(3, 1);
	print_deque_int(deq4);

}

int main36() {
	test();
	return 0;
}