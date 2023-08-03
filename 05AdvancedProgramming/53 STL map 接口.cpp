#include"head.h"
/*
* STL map 接口
* 
* 构造函数：
*	·map<T1,T2>()
*	·map<T1,T2>(const map<T1,T2>& m)	
* 
*	·map<T1,T2>& operator= (const map<T1,T2>& m)
* 
*	·insert(const pair<T1,T2>& p)
*	·insert(pair<T1, T2>(T1 t1, T2 t2))
*	·insert(make_pair(T1 t1, T2 t2))
*	·insert(map<T1,T2>::value_type(T1 t1, T2 t2))
* 
*	·erase(const_it pos)
*	·erase(const_it start, const_it end)
*	·erase(T1 key)
* 
*	·find(T1 key)
*	
*	·count(T1 key)
* 
* 排序：仿函数
*	·bool operator() ()
* 
*/

#include<map>

static void print_map(map<int,int> &m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key=" << it->first << " value=" << it->second << endl;
	}
	cout << endl;
}
static void print_map(map<int, string>& m) {
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key=" << it->first << " value=" << it->second << endl;
	}
	cout << endl;
}

/// <summary>
/// map<T1, T2> ()
/// map<T1, T2> (const map<T1,T2>& m)
/// map<T1, T2>& operator= (map<T1,T2>& m)
/// insert(pair<T1,T2>& p)
/// insert(pair<T1,T2>(T1 t1,T2 t2))
/// insert(make_pair(T1 t1, T2 t2))
/// insert(map<T1,T2>::value_type(T1 t1, T2, t2))
/// map[key] = value		// 不建议
/// </summary>
static void test_construct() {
	map<int, int> m1;

	pair<int, int> p(0, 000);
	pair<int, int> p2 = make_pair(9, 999);
	m1.insert(p);
	m1.insert(p2);
	m1.insert(pair<int, int>(1, 111));
	m1.insert(make_pair(2, 222));

	m1.insert(map<int, int>::value_type(9, 999));

	// []不建议插入，多用于通过key访问value
	// 如果通过[]访问key不存在，会自动插入m[key] = 0;
	m1[8] = 888;

	print_map(m1);

	map<int, int> m2(m1);
	print_map(m2);

	map<int, int> m3 = m2;
	print_map(m3);

}

/// <summary>
/// bool empty()
/// int size()
/// </summary>
static void test_size() {
	map<int, string> m;
	m.insert(make_pair(3,"zhangsan"));
	m.insert(make_pair(5,"wangwu"));
	m.insert(make_pair(4,"lisi"));

	if (m.empty()) {
		cout << "map is empty." << endl;
	}
	else {
		cout << "size of the map is " << m.size() << endl;
	}
}

/// <summary>
/// map<T1,T2>& swap(const map<T1,T2>& m)
/// </summary>
static void test_swap() {
	map<int, string> m;
	m.insert(make_pair(13, "zhangsan"));
	m.insert(make_pair(15, "wangwu"));
	m.insert(make_pair(41, "lisi"));

	map<int, string> m2;
	m2.insert(make_pair(25, "孙伯符"));
	m2.insert(make_pair(18, "孙仲谋"));
	m2.insert(make_pair(31, "张文远"));
	m2.insert(make_pair(21, "司马懿"));

	print_map(m);
	print_map(m2);

	cout << "after swap..." << endl;
	m.swap(m2);
	print_map(m);
	print_map(m2);
}

/// <summary>
/// void erase(const_it pos)
/// void erase(const_it start, const_it end)
/// void erase(T1& key)
/// void clear()
/// </summary>
static void test_erase() {
	map<int, string> m;
	m.insert(make_pair(25, "孙伯符"));
	m.insert(make_pair(18, "孙仲谋"));
	m.insert(make_pair(31, "张文远"));
	m.insert(make_pair(21, "司马懿"));
	m.insert(pair<int,string>(13, "zhangsan"));
	m.insert(pair<int, string>(15, "wangwu"));
	m.insert(map<int, string>::value_type(41, "lisi"));
	m.insert(map<int, string>::value_type(0, "test"));
	print_map(m);

	m.erase(--m.end());
	print_map(m);

	m.erase(++m.begin(), ++(++(++m.begin())));
	print_map(m);

	m.erase(1);
	print_map(m);

	m.erase(0);
	print_map(m);

}

/// <summary>
/// map<T1,T2>::iterator find(T1 key)
/// int count(T1 key)
/// </summary>
static void test_find() {
	map<int, string> m;
	m.insert(make_pair(2, "孙伯符"));
	m.insert(make_pair(3, "孙仲谋"));
	m.insert(make_pair(1, "张文远"));
	m.insert(make_pair(4, "司马懿"));

	map<int, string>::iterator res = m.find(1);
	if (res!=m.end()) {
		cout << "find: key=" << res->first << " value = " << res->second << endl;
	}
	else {
		cout << "the key doesn't exists." << endl;
	}

	int num = m.count(1);
	cout << "find " << num << " key=1" << endl;

	int num2 = m.count(5);
	cout << "find " << num2 << " key=5" << endl;
}

// 仿函数
class MapCompare {
public:
	bool operator()(int v1,int v2) const{
		return v1 > v2;
	}
};
// map 排序
static void test_compare(){
	map<int, string, MapCompare> m;
	m.insert(make_pair(2, "孙伯符"));
	m.insert(make_pair(3, "孙仲谋"));
	m.insert(make_pair(1, "张文远"));
	m.insert(make_pair(4, "司马懿"));

	for (map<int, string, MapCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key=" << it->first << " value=" << it->second << endl;
	}
	cout << endl;
}
int main53() {
	//test_construct();

	//test_size();

	//test_swap();

	//test_erase();

	//test_find();

	test_compare();

	return 0;
}