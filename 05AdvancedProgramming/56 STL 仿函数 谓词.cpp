#include"head.h"
/*
* STL �º��� ν��
* 
* �������bool���͵ķº�������Ϊν��
*		���operator()����һ����������ô��ΪһԪν��
*			operator()����������������Ϊ��Ԫν��
* 
*/

#include<vector>
#include<algorithm>

// һԪν�ʣ�����ֵbool���ͣ�����1��
class MyGreater {
public:
	MyGreater(int v = 0) { _v = v; }
	bool operator() (int v) {
		return v > _v;
	}
	int _v;
};

static void test1() {
	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i * i);
	}

	int base = 5;
	// find_if(const_it start, const_it end, _Pred)
	// _Pred ��ν��

	vector<int>::iterator it = find_if(v.begin(), v.end(), MyGreater(base));

	if (it == v.end()) cout << "Not found." << endl;

	else while (it != v.end()) {
		cout << "Found element greater than" << base << " : " << *it << endl;
		it = find_if(++it, v.end(), MyGreater(base));
	}

}

// ��Ԫν�ʣ�����ֵbool���ͣ�����2��
class MyConstraint {
public:
	MyConstraint(int v1, int v2) :_v1(v1), _v2(v2) {}
	bool operator() (int v) {
		return v > _v1 && v < _v2;
	}

	int _v1, _v2;
	int v;
};

static void test2() {
	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i * i);
	}

	MyConstraint cons(5, 50);
	vector<int>::iterator it = find_if(v.begin(), v.end(), cons);

	if (it == v.end()) cout << "Not found." << endl;

	else while (it != v.end()) {
		cout << "Found element that > " << cons._v1
			<< " and < " << cons._v2 << " : " << *it << endl;
		it = find_if(++it, v.end(), cons);
	}

}

class MySort56 {
public:
	bool operator() (int v1, int v2) {
		return v1 > v2;
	}
};

static void test3() {
	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		v.push_back(i * i);
	}

	sort(v.begin(), v.end(), MySort56());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main56() {

	test1();
	test2();
	test3();
	return 0;
}