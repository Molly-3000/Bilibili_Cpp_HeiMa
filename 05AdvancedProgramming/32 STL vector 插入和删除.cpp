#include"head.h"
/*
* STL vector �����ɾ��
* 
* ���ܣ���vector�������в��롢ɾ������
* 
* ����ԭ�ͣ�
*	��push_back(elem)		// β��
*	��pop_back()			// ɾ�����һ��Ԫ��
*	��insert(const_iterator pos,T elem)	
			// �ڵ�����ָ��λ�ã�����elem
*	��insert(const_iterator pos,int count, T elem) 
			// �ڵ�����ָ��λ�ã�����count��elem

*	��erase(const_iterator pos)		
			// ɾ��������ָ��λ�õ�Ԫ��
*	��erase(const_iterator start, const_iterator end) 
			// ɾ����������start��end������ҿ�����Ԫ��

*	��clear()	// ɾ������Ԫ��
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
	print_vector(v);

	for (int i = 0; i < 10; i++) {
		v.push_back(i * 111);	// β��
	}
	print_vector(v);

	v.pop_back();	// βɾ
	print_vector(v);

	// insert(const_iterator, elem)
	v.insert(v.begin(), 1000);
	print_vector(v);

	// insert(const_iterator, int count, T elem)
	v.insert(v.begin()+1, 2, 100);
	print_vector(v);

	// erase(const_iterator)
	v.erase(v.begin());		// ɾ��1000
	print_vector(v);

	// erase(const_iterator start ,const_iterator end)
	v.erase(v.begin(), v.begin() + 3);
	print_vector(v);

	v.clear();
	print_vector(v);

}

int main32() {
	test();
	return 0;
}