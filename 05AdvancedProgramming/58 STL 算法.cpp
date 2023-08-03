#include"head.h"
/*
* STL �㷨
* 
* 1������
*		�㷨��Ҫ����ͷ�ļ�<algorithm>��<functional>��<numeric>���
*		��<algorithm>������STLͷ�ļ�������һ����
				��Χ�漰���Ƚϡ����������ҡ���������ֵ���޸�
*		��<numeric>�ļ���С��ֻ���������������������
				����ѧ�����ģ�庯��  ~~~~~~~
							  ~~~~~~~~
*		��<functional>������һЩģ���࣬����������������
*								~~~~~~
* 2�������㷨��
*		
*	������
*		��for_each(const_it begin, const_it end, _Pred)	// ��������
*		��transform(const_it beg1, const_it end1, const_it beg2, _func)	
				// �����ݰ��˵���һ��������_func���ڰ��˹�����������

*	���ң�
*		��iterator find(begin, end, T elem)	// ����Ԫ��
*		��find_if(begin, end, _Pred)		// ��������
				// _func ��ν�ʣ�������bool�ĺ�������
				// ��bool����
*		��adjacent_find(begin, end)			// �������ڵ��ظ�Ԫ�أ����ص�һ��λ�õ�it
*		��bool binary_search(begin, end, T elem) // ���ַ�����
				// ��������Ϊbool
				// P.S. �����������в���ʹ��

*	ͳ�ƣ�
*		��int count(begin, end, T elem)			// ͳ��Ԫ�ظ���
*		��int count_if(begin, end, _Pred)		// ������ͳ��
*				// _func ��ν�ʣ�������bool�ĺ�������
*				// ��bool����
* 
*	����
*		��sort(begin, end, _Pred)		// ����Ĭ������
				// ����ͨ�� _Pred��Ԫν�ʣ��޸��������
*		��random_shuffle(begin, end)	// ����
*		��merge(beg1, end1, beg2, end2, dest)	// �ϲ�
				// dest ΪĿ��������ʼ������
				// �ϲ�ǰ������2���������У��ϲ�����Ȼ����
				// �ϲ�ǰҪ��Ŀ���������ٿռ�
*		��reverse(begin, end)			// ��ת
*	
*	����
*		��copy(begin, end, dest)
*				// ����ǰҪ��Ŀ���������ٿռ�
*	�滻
*		��replace(begin, end, old_val, new_val)
*		��replace_if(begin, end, _Pred, new_val)
*				// _PredΪһԪν��
* 
*	����
*		��swap(container c1, container c2)
* 
*	���� ���
*		��accumulate(begin, end, val)
*							// val Ϊ��ʼ�ۼ�ֵ
*	���� ���
*		��fill(begin, end, val)
*							// val Ϊ���ֵ
* 
*	���� ������
*		��set_intersection(beg1, end1, beg2, end2, dest)
							// �����������Ľ���
*		��set_union(beg1, end1, beg2, end2, dest)		// ����
*		��set_difference(beg1, end1, beg2, end2, dest)	
							// �
*/

#include<vector>
#include<algorithm>

/// <summary>
/// �����㷨
/// for_each(const_it begin, const_it end, _func)
/// P.S. _func�����Ǻ�������Ҳ�����Ǻ�������
/// </summary>
static void print_int(int val) {
	cout << val << " ";
}
class myPrint {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};
static void test_for_each() {
	vector<int> v,v2;
	for (int i = 0; i < 10; i++) {
		v.push_back(i*i);
	}

	// for_each(begin, end, _func) 
	// ������
	for_each(v.begin(), v.end(), print_int);
	cout << endl;
	// ��������
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

/// <summary>
/// ����
/// transform(const_it beg1, const_it end1,const_it beg2, _func)
/// P.S. ����ǰ Ҫ���ٿռ�
/// </summary>
static int trans_int(int val) {
	return ++val;
}
class myTransForm {
public:
	int operator() (int val){
		return ++val;
	}
};
static void test_transform() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * i);
	}
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;

	vector<int> v2,v3;

	// transform
	// ������
	v2.resize(v1.size());	// transformǰ Ҫ���ٿռ�
	transform(v1.begin(), v1.end(), v2.begin(), trans_int);
	for_each(v2.begin(), v2.end(), print_int);
	cout << endl;
	// ��������
	v3.resize(v2.size());	// transformǰ Ҫ���ٿռ�
	transform(v2.begin(), v2.end(), v3.begin(), myTransForm());
	for_each(v3.begin(), v3.end(), myPrint());
	cout << endl;

}


/// <summary>
/// ���� find(beg, end, elem)
/// P.S. �ҵ� ���ص�������δ�ҵ� ����end
/// P.P.S. �Զ����������� ��Ҫ����operator== �Թ�find���бȽ�
/// </summary>
static void test_find() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i * i);
	}
	vector<int>::iterator res = find(v.begin(), v.end(), 5);
	if (res != v.end()) {
		cout << "found element" << *res << endl;
	}
	else {
		cout << "not found" << endl;
	}

}

class Person58 {
public:
	// ����== , �ײ�find��Ҫ֪����ζԱ�person����
	//bool operator== (const Person58& p) {
	//	return (this->m_name == p.m_name) && (this->m_age == p.m_age);
	//}

	bool operator== (const Person58& p) {
		return (this->m_age == p.m_age);
	}

	Person58(string name, int age):m_name(name),m_age(age) {}
	string m_name;
	int m_age;
};
// �Զ����������� ��Ҫ����operator== �Թ�find���бȽ�
static void test_find_my() {
	vector<Person58> vp;
	vp.push_back(Person58("a", 11));
	vp.push_back(Person58("b", 33));
	vp.push_back(Person58("c", 22));
	vp.push_back(Person58("d", 22));

	vector<Person58>::iterator it = find(vp.begin(), vp.end(), Person58("c", 22));

	if (it != vp.end()) {
		cout << "found elemnt: " << it->m_name << " is " << it->m_age << endl;
	}
	else {
		cout << "not found" << endl;
	}

}

/// <summary>
/// ���� find_if(begin, end, _Pred)
/// _Pred��Ҫ�Ǹ�ν��
/// </summary>
static bool greater_five(int val) {
	return val > 5;
}
class MyGreater {
public:
	MyGreater(int v) :val(v) {}
	bool operator() (int v) {
		return v > val;
	}
	int val;
};
static void test_find_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i * i);
	}

	// find_if
	// ������
	vector<int>::iterator it = find_if(v.begin(), v.end(), greater_five);
	while (it != v.end()) {
		cout << "found element > 5 : " << *it << endl;
		// ��������
		it = find_if(++it, v.end(), MyGreater(5));
	}
}

static bool age_greater_20(const Person58& p) {
	return p.m_age > 20;
}
class MyPersonGreater{
public:
	MyPersonGreater(int v) :val(v) {}
	bool operator() (Person58& p) {
		return p.m_age > val;
	}
	int val;
};
void test_find_if_my() {
	vector<Person58> vp;
	vp.push_back(Person58("aaa", 22));
	vp.push_back(Person58("bbb", 17));
	vp.push_back(Person58("ccc", 34));
	vp.push_back(Person58("ddd", 11));
	
	// ������
	vector<Person58>::iterator it = find_if(vp.begin(), vp.end(), age_greater_20);
	while (it != vp.end()) {
		cout << "found person age > 20 :" << it->m_name << endl;
		// ��������
		it = find_if(++it, vp.end(), MyPersonGreater(20));
	}

}

/// <summary>
/// ���� adjacent_find(begin, end)
/// </summary>
static void test_adjacent_find() {
	vector<int> v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		cout << "No adjacent repeatation." << endl;
	}
	else {
		cout << "Found first adjacent element: " << *it << endl;
	}
}
// �Զ����������� ��Ҫ����operator== �Թ�find���бȽ�
static void test_adjacent_find_my() {
	vector<Person58> vp;
	vp.push_back(Person58("aa", 11));
	vp.push_back(Person58("bb", 33));
	vp.push_back(Person58("cc", 22));
	vp.push_back(Person58("cc", 22));

	vector<Person58>::iterator it = adjacent_find(vp.begin(), vp.end());
	if (it == vp.end()) {
		cout << "No adjacent repeatation." << endl;
	}
	else {
		cout << "Found first adjacent element: " << it->m_name << endl;
	}
}

/// <summary>
/// ���� bool binary_search(begin, end, value)
/// P.S. �������в��ܲ���
/// </summary>
static void test_binary_search() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	bool res = binary_search(v.begin(), v.end(),9);
	if (res) cout << "found" << endl;
	else cout << "not found" << endl;

	// ������������У����ؽ����һ����ȷ
	v.push_back(2);		// ���ַ�����һ�κ����һ��Ԫ�ؽ��бȽ�
	res = binary_search(v.begin(), v.end(), 9);
	if (res) cout << "found" << endl;
	else cout << "not found" << endl;

}


/// <summary>
/// ͳ�� int count(begin, end, T elem)
/// P.S. �Զ����������� ��Ҫ����operator== �Թ�find���бȽ�
/// </summary>
static void test_count() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		v.push_back(i * i);
		v.push_back(i * i * i);
	}

	int cn = count(v.begin(), v.end(), 0);
	cout << "the number of element 0 : " << cn << endl;
	cout << "the number of element 2 : " << count(v.begin(), v.end(), 2) << endl;
	cout << "the number of element 4 : " << count(v.begin(), v.end(), 4) << endl;

}
// �Զ����������ͣ���Ҫ����operator==(const MyData& my)
static void test_count_my() {
	vector<Person58> vp;
	vp.push_back(Person58("aa", 11));
	vp.push_back(Person58("bb", 33));
	vp.push_back(Person58("cc", 22));
	vp.push_back(Person58("cc", 22));

	Person58 p1("aa", 10);
	Person58 p2("cc", 22);
	int cn = count(vp.begin(), vp.end(), p1);
	cout << "the number of person age 10 is " << cn << endl;
	cn = count(vp.begin(), vp.end(), p2);
	cout << "the number of person age 22 is " << cn << endl;

}


/// <summary>
/// ͳ�� int count_if(begin, end, _Pred)
/// _Pred�Ǹ�ν��
/// </summary>
static void test_count_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	int cn = count_if(v.begin(), v.end(), greater_five);
	cout << "the nember of element > 5 : " << cn << endl;

	cn = count_if(v.begin(), v.end(), MyGreater(7));
	cout << "the nember of element > 7 : " << cn << endl;
}
static void test_count_if_my() {
	vector<Person58> vp;
	vp.push_back(Person58("aa", 11));
	vp.push_back(Person58("bb", 33));
	vp.push_back(Person58("cc", 22));
	vp.push_back(Person58("cc", 16));

	// ������
	int cn = count_if(vp.begin(), vp.end(), age_greater_20);
	cout << "the number of person age > 20 : " << cn << endl;
	// ��������
	cn = count_if(vp.begin(), vp.end(), MyPersonGreater(10));
	cout << "the number of person age > 10 : " << cn << endl;
}


/// <summary>
/// ���� sort(begin, end, _Pred)
/// _Pred �Ƕ�Ԫν�ʣ�Ĭ������
/// </summary>
static void test_sort() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
		v.push_back(i * i);
	}

	// Ĭ������
	sort(v.begin(), v.end());

	for_each(v.begin(), v.end(), print_int);
	cout << endl;

	// ��Ϊ����
	// �����ڽ���������
	sort(v.begin(), v.end(),greater<int>());

	for_each(v.begin(), v.end(), print_int);
	cout << endl;

}
class MyPersonGreaterP {
public:
	bool operator() (const Person58& p1,const Person58& p2) {
		return p1.m_age > p2.m_age;
	}
};
void print_Person(const Person58& p) {
	cout << p.m_name << " " << p.m_age << endl;
}
static void test_sort_my() {
	vector<Person58> vp;
	vp.push_back(Person58("aa", 11));
	vp.push_back(Person58("bb", 33));
	vp.push_back(Person58("cc", 22));
	vp.push_back(Person58("cc", 16));

	sort(vp.begin(), vp.end(), MyPersonGreaterP());

	for_each(vp.begin(), vp.end(), print_Person);
}


/// <summary>
/// ���� random_shuffle(begin, end)
/// ��ת reverse(begin, end)
/// </summary>
static void test_random_shuffle() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print_int);
	cout << endl;

	// ����
	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), print_int);
	cout << endl;

	// ��ת
	reverse(v.begin(), v.end());

	for_each(v.begin(), v.end(), print_int);
	cout << endl;

}


/// <summary>
/// �ϲ� merge(beg1, end1, beg2, end2, target.beg)
/// P.S. ������������Ϊ��������
///		 �ϲ�����Ȼ����
/// </summary>
static void test_merge() {
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i * i);
	}
	for_each(v1.begin(), v1.end(), print_int);
	cout << endl;
	for_each(v2.begin(), v2.end(), print_int);
	cout << endl;

	// �ϲ�����Ҫ��ǰ��_dest���ٿռ�
	vector<int> v;
	v.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	
	for_each(v.begin(), v.end(), print_int);

}


/// <summary>
/// ���� copy(begin, end, dest)
/// P.S. ����ǰ��Ҫ�ȸ�Ŀ���������ٿռ�
/// </summary>
static void test_copy() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), print_int);
	cout << endl;

	// ����ǰ Ҫ���ٿռ�
	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), print_int);

}

/// <summary>
/// �滻 replace(begin, end, old_val, new_val)
/// </summary>
static void test_replace() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
		v.push_back(i*i);
	}
	for_each(v.begin(), v.end(), print_int);
	cout << endl;

	replace(v.begin(), v.end(), 0, 999);
	for_each(v.begin(), v.end(), print_int);
	cout << endl;
}

/// <summary>
/// �滻 replace_if(begin, end, _Pred, new_val)
/// </summary>
static void test_replace_if() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
		v.push_back(i * i);
	}
	for_each(v.begin(), v.end(), print_int);
	cout << endl;

	replace_if(v.begin(), v.end(), MyGreater(5), 999);
	for_each(v.begin(), v.end(), print_int);
	cout << endl;
}

/// <summary>
/// ���� swap(container c1, container c2)
/// P.S. �����ı�����ͬ�������������Դ�С��ͬ
/// </summary>
static void test_swap() {
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
	}

	for (int i = 0; i < 10; i++) {
		v2.push_back(i * i);
	}
	
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	// ����
	swap(v1, v2);
	cout << "after swap()..." << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}


#include<numeric>

/// <summary>
/// ������� accumulate(begin, end, val)
///	P.S. val Ϊ��ʼֵ�ۼ�ֵ��ͨ��Ϊ0
/// </summary>
static void test_accumulate() {
	vector<int> v;

	for (int i = 0; i < 100; i++) {
		v.push_back(i * i);
	}

	// ���
	int res = accumulate(v.begin(), v.end(), 0);

	cout << "sum = " << res << endl;
}

/// <summary>
/// ��� fill(begin, end, val)
/// </summary>
static void test_fill() {
	vector<int> v;

	v.resize(10);		// resize�����Ĭ��ֵ 0
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	// ��� 999
	fill(v.begin()+5, v.end(), 999);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}


/// <summary>
/// ���� �����������Ľ���������
/// set_intersection(beg1, end1, beg2, end2, dest)
/// set_union(beg1, end1, beg2, end2, dest)
/// set_difference(beg1, end1, beg2, end2, dest)
/// P.S. ԭ���� ����Ϊ ��������
///		 ��Ҫ��ǰΪĿ������ ���ٿռ�
///		 ����ֵ Ϊ ���󼯺�ĩβԪ�صĵ����� ��һ��= ������end
/// </summary>
static void test_set_() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i * i);
	}
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	// Ŀ��������Ҫ��ǰ���ٿռ�
	vector<int> v3;
	v3.resize(v1.size() < v2.size() ? v1.size() : v2.size());
	cout << "set_intersection()..." << endl << endl;

	// ����λ�õ�����
	vector<int>::iterator itEnd;
	itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, myPrint());
	cout << endl << endl;

	v3.resize(v1.size() + v2.size());
	cout << "set_union()..." << endl;
	itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, myPrint());
	cout << endl << endl;

	v3.resize(v1.size());
	cout << "v1 v2 difference..." << endl;
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, myPrint());
	cout << endl << endl;

	v3.resize(v2.size());
	cout << "v2 v1 difference..." << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for_each(v3.begin(), itEnd, myPrint());
	cout << endl << endl;

}

int main58() {

	//test_for_each();

	//test_transform();

	//test_find();
	//test_find_my();

	//test_find_if();
	//test_find_if_my();

	//test_adjacent_find();
	//test_adjacent_find_my();

	//test_binary_search();

	//test_count();
	//test_count_my();

	//test_count_if();
	//test_count_if_my();

	//test_sort();
	//test_sort_my();

	//srand((unsigned int)time(NULL));
	//test_random_shuffle();

	//test_merge();

	//test_copy();

	//test_replace();
	//test_replace_if();

	//test_swap();

	//test_accumulate();

	//test_fill();

	test_set_();

	return 0;
}