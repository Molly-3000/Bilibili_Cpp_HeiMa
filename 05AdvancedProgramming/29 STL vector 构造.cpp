#include"head.h"
/*
* STL vector����
* 
* 1��vector��������
*	���ܣ�vector���ݽṹ���������ƣ�Ҳ��Ϊ��������
*						 ~~~~~~~~~		  ~~~~~~~~
*	����������
*		�����Ǿ�̬�ռ䣬�����ڴ���޷���չ
*		vector���Զ�̬��չ��β���βɾ��
*				  ~~~~~~~~
*`!!��̬��չ��
*		��������ԭ�ռ�֮�������¿ռ䣬�����Ҹ���Ŀռ䣬
*			Ȼ�����ݿ����������ݿռ䣬���ͷ�ԭ�ռ�
*					  ~~~~  ~~~~~~~~~~
*	 ������| x [ 1 | 2 | 3 | 4 |������| n ] y |������
*		    ��	��					    ��	��
*		v. rend	begin				 rbegin end  ()
* 
*	vector�����ĵ�������������������������ʵ�����
* 
* 
* 2��vector ���캯��
*	
*	���ܣ�����vector����
*
*	����ԭ�ͣ�
*		��vector<T> v;					// ָ��ģ�����ʵ����ʵ�֣�Ĭ�Ϲ��캯��
*		��vector(v.begin(),v.end())		// ����v.begin(),end())�����е�Ԫ�أ�����������
*		��vector(n,elem)				// n��elem������������
*		��vector(const vector &vec)		// ��������
*/

#include<vector>
#include<algorithm>

static void print_int(int val) {
	cout << val << " ";
}

static void print_vector_int(vector<int> v) {

	//for_each(v.begin(), v.end(), print_int);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		print_int(*it);
	}

	cout << endl;
}

static void test() {

	// Ĭ�Ϲ���
	vector<int> v1;	

	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 11);
	}
	print_vector_int(v1);

	// ͨ�����乹��
	vector<int> v2(v1.begin(), v1.end());  // ǰ�պ󿪵����䣬����
	print_vector_int(v2);

	// n��elem����
	vector<int> v3(10, 100);
	print_vector_int(v3);

	// ��������
	vector<int> v4(v3);
	print_vector_int(v4);
}

int main29() {
	test();
	return 0;
}
