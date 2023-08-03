#include"head.h"
/*
* STL vector ���� �� ��С
* 
* ���ܣ���vector�����������ʹ�С���в���
*			      capacity >= size
* 
* ����ԭ�ͣ�
*	��bool empty()				// �ж��Ƿ�Ϊ��
*	��int capacity()			// ������������
*	��int size()				// ����������Ԫ�ظ���
*	��void resize(int num)	// ����ָ����������Ϊnum
*			// ��������䳤������Ĭ��ֵ����µ�λ��
*			// ���������̣���ĩβ�������ֵ�Ԫ�ر�ɾ��
*	��void resize(int num,T elem)
*			// ָ�����Ĭ��ֵ
* 
*	��void shrink_to_fit()		// ʹcapacity������size��С
*/

#include<vector>

static void print_vector(vector<int> v) {
	cout << "vector : ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
}

static void test() {
	vector<int> v1;

	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 111);
	}

	if (v1.empty()) {// Ϊ�� v1Ϊ��
		cout << "v1 is empty." << endl;
	}
	else {
		// capacity ���Զ����䣬 ����size
		cout << "the capacity of v1 is " << v1.capacity() << endl;
		cout << "the size of v1 is " << v1.size() << endl;
		print_vector(v1);
	}

	v1.resize(15);	// resize(n)�޸�size��capacity�Ի��Զ�����>=size
	cout << "the capacity of v1 is " << v1.capacity() << endl;
	cout << "the size of v1 is " << v1.size() << endl;
	print_vector(v1);

	v1.resize(20, 999);
	cout << "the capacity of v1 is " << v1.capacity() << endl;
	cout << "the size of v1 is " << v1.size() << endl;
	print_vector(v1);

	v1.resize(5);	// resize()ʹsize��С��capacity����
	cout << "the capacity of v1 is " << v1.capacity() << endl;
	cout << "the size of v1 is " << v1.size() << endl;
	print_vector(v1);

	v1.shrink_to_fit();
	cout << "the capacity of v1 is " << v1.capacity() << endl;
	cout << "the size of v1 is " << v1.size() << endl;
	print_vector(v1);
}

int main31() {
	test();
	return 0;
}