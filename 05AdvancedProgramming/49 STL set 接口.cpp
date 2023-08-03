#include"head.h"
/*
* STL set/multiset 接口
* 
*	·set<T>()
*	·set<T>(const set<T>& s)
* 
*	·set<T>& operator=(const set<T>& s)
* 
*	·bool empty()
*	·int size()
*	·insert(T elem)			// 返回是否插入成功
* 
*	·erase(const_it pos)
*	·erase(const_it start, const_it end)
*	·erase(T elem)
*	·clear()
* 
*	·set<T>& swap(set<T>& s)
* 
* 查找：
*	·find(T key)	 // 存在则返回该键的迭代器，不存在则返回end()
* 
* 统计：
*	·count(T key)	 // 统计key的元素个数
* 
* 
* multiset 和 set insert()的区别：
*	·set不能重复插入数据，multiset可以
*	·set插入数据时会返回插入结果，是否成功
*	·multiset插入时不会检测数据
*/

#include<set>
static void print_set_int(const set<int>& s) {
	cout << "set: ";
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

/// <summary>
/// set<T>()
/// set<T>(const set<T>& s)
/// set<T>& operator=(const set<T>& s)
/// 
/// insert(T elem)
/// </summary>
static void test_construct() {

	// 默认构造
	set<int> s1;

	// 插入数据 只有insert方式
	for (int i = 0; i < 10; i++) {
		s1.insert(i);
		s1.insert(i * i);
	}

	// set特点：所有元素插入时，自动被排序
	// set不允许插入重复元素
	print_set_int(s1);

	// 拷贝构造
	set<int> s2(s1);
	print_set_int(s2);

	// operator=
	set<int> s3 = s2;
	print_set_int(s3);

}

/// <summary>
/// bool empty()
/// int size()
/// set<T>& swap(set<T>& s)
/// </summary>
static void test_size() {
	set<int> s;

	for (int i = 0; i < 10; i++) {
		s.insert(i);
		s.insert(i * i);
	}

	// bool empty()
	if (s.empty()) {
		cout << "the set is empty." << endl;
	}else {
		// int size()
		cout << "size of the set is " << s.size() << endl;
	}

	set<int> s2;
	s2.insert(999);

	print_set_int(s);
	print_set_int(s2);

	cout << "set<T>& swap(const set<T>& s)" << endl;
	s.swap(s2);
	print_set_int(s);
	print_set_int(s2);
	
}

/// <summary>
/// erase(const_it pos)
/// erase(const_it start, const_it end)
/// erase(T elem)
/// clear()
/// </summary>
static void test_erase() {
	set<int> s;
	
	for (int i = 0; i < 10; i++) {
		s.insert(i);
		s.insert(i * i);
	}
	print_set_int(s);

	cout << "erase(++s.begin())..." << endl;
	s.erase(++s.begin());
	print_set_int(s);

	cout << "erase(++s.begin(), --(--s.end()))..." << endl;
	s.erase(++s.begin(), --(--s.end()));
	print_set_int(s);

	cout << "erase(81)..." << endl;
	s.erase(81);
	print_set_int(s);

	cout << "clear()..." << endl;
	s.clear();
	print_set_int(s);
}

/// <summary>
/// set<T>::iterator find(T key)
/// </summary>
static void test_find() {
	set<int> s;

	for (int i = 0; i < 10; i++) {
		s.insert(i);
		s.insert(i * i);
	}
	print_set_int(s);

	set<int>::iterator pos = s.find(64);
	if (pos != s.end()) {	// 未找到元素时，返回end()
		cout << "find the element: " << *pos << endl;
	}else {
		cout << "fail to find the element." << endl;
	}

	cout << "*(++s.find(64))..." << endl;
	cout << *(++s.find(64)) << endl;

}

/// <summary>
/// int count(T key)
/// </summary>
static void test_count() {
	set<int> s;

	for (int i = 0; i < 10; i++) {
		s.insert(i);
		s.insert(i * i);
	}
	print_set_int(s);

	cout << "s.count(4)..." << endl;
	cout << s.count(4) << endl;

}

/// <summary>
/// set 和 multiset 区别
/// set不能插入重复数据，multiset可以
/// set.insert()返回插入结果，返回迭代器和是否成功
/// multiset插入时不会检测数据，返回迭代器
/// </summary>
static void test_multiset() {
	set<int> s;
	s.insert(111);

	// pair 队组数据,通过first/second索引
	pair<set<int>::iterator,bool> res = s.insert(111);

	if (res.second) {
		cout << "s insert success..." << endl;
	}
	else {
		cout << "s insert fail..." << endl;
	}
	cout << "the number of elemen 111 is " << s.count(111) << endl;

	multiset<int> ms;
	ms.insert(111);
	multiset<int>::iterator first = ms.find(111);

	multiset<int>::iterator it = ms.insert(111);
	if (it!=first) {
		cout << "ms insert success..." << endl;
	}
	else {
		cout << "ms insert fail..." << endl;
	}
	cout << "the number of elemen 111 is " << ms.count(111) << endl;
}


int main49() {

	//test_construct();

	//test_size();

	//test_erase();

	//test_find();

	//test_count();

	test_multiset();

	return 0;
}