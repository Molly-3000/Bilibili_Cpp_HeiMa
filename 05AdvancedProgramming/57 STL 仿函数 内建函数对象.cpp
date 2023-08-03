#include"head.h"
/*
* STL �º��� �ڽ���������
* 
* 1�����STL �ڽ���һЩ��������
* 
*	 ���ࣺ�����º���	��ϵ�º���	�߼��º���
* 
*	 �÷�����Ҫ����ͷ�ļ�		#include<functional>
*		   ��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
* 
* 2�������º���
* 
*	 ���ܣ�ʵ����������
*		   ����negate��һԪ���㣬�����Ƕ�Ԫ����
* 
*	 ����ԭ�ͣ�
*		��template<class T> T plus(const T& t1,const T& t2)		// ��
*		��template<class T> T minus(const T& t1,const T& t2)	// ��
*		��template<class T> T multiplies(const T& t1,const T& t2)// ��
*		��template<class T> T divides(const T& t1,const T& t2)	// ��
*		��template<class T> T modulus(const T& t1,const T& t2)	// ȡģ
*		��template<class T> T negate(const T& t)				// ȡ��
* 
* 3����ϵ�º���
* 
*	 ���ܣ�ʵ�ֹ�ϵ�Ƚ�
* 
*	 ����ԭ�ͣ�
*		��template<T> bool equal_to(const T& t1,const T& t2)
*		��template<T> bool not_equal_to(const T& t1,const T& t2)
*		��template<T> bool greater(const T& t1,const T& t2)
*		��template<T> bool greater_equal(const T& t1,const T& t2)
*		��template<T> bool less(const T& t1,const T& t2)
*		��template<T> bool less_equal(const T& t1,const T& t2)
* 
* 4���߼��º���
* 
*	 ���ܣ��߼�����
* 
*	 ����ԭ�ͣ�
*		��template<T> bool logical_and(const T& t1,const T& t2)	// ��
*		��template<T> bool logical_or(const T& t1,const T& t2)	// ��
*		��template<T> bool logical_not(const T& t)	// ��
* 
*/

#include<functional>		// ����ͷ�ļ�

// �����º���
static void test_calculation() {
	
	// ��Ԫ����
	int v1 = 11, v2 = 22;
	cout << "v1 = " << v1 << " v2 = " << v2 << endl;
	// ��
	plus<int> p;
	cout << p(v1, v2) << endl;

	// minus
	minus<int> m;
	cout << m(v1, v2) << endl;

	//multiplies
	cout << multiplies<int>()(v1, v2) << endl;

	// divides
	cout << divides<int>()(v1, v2) << endl;

	// modulus
	cout << modulus<int>()(v1, v2) << endl;

	// һԪ����
	// negate
	cout << negate<int>()(v1) << endl;

}

#include<vector>
#include<algorithm>

// ��ϵ�º���
class MyCompare57 {
public:
	bool operator()(int v1, int v2) {
		return v1 < v2;
	}
};

static void test_relation() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
		v.push_back(i*i);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// ���� ʹ���Զ��庯������ MyCompare57(
	sort(v.begin(), v.end(), MyCompare57());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// ʹ���ڽ��������� greater<int>()
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

// �߼��º���
static void test_logical() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);

	for (int i = 0; i < v.size(); i++) {
		cout << " true & " << v[i] << " is " <<
			logical_and<bool>()(true,v[i]) << endl;
		cout << " true or " << v[i] << " is " <<
			logical_or<bool>()(true, v[i]) << endl;
		cout << " not " << v[i] << " is " <<
			logical_not<bool>()(v[i]) << endl;
	}
	
	vector<bool>v2;
	v2.resize(v.size());	// ����ǰ��Ҫ���ٿռ�

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";
	}
}


int main57() {
	
	test_calculation();
	test_relation();
	test_logical();

	return 0;
}