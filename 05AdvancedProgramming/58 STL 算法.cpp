#include"head.h"
/*
* STL 算法
* 
* 1、概述
*		算法主要是由头文件<algorithm>、<functional>、<numeric>组成
*		·<algorithm>是所有STL头文件中最大的一个，
				范围涉及到比较、交换、查找、遍历、赋值、修改
*		·<numeric>文件很小，只包括几个在序列上面进行
				简单数学运算的模板函数  ~~~~~~~
							  ~~~~~~~~
*		·<functional>定义了一些模板类，用以声明函数对象
*								~~~~~~
* 2、常用算法：
*		
*	遍历：
*		·for_each(const_it begin, const_it end, _Pred)	// 遍历容器
*		·transform(const_it beg1, const_it end1, const_it beg2, _func)	
				// 将数据搬运到另一个容器，_func可在搬运过程中做运算

*	查找：
*		·iterator find(begin, end, T elem)	// 查找元素
*		·find_if(begin, end, _Pred)		// 按条件查
				// _func 是谓词，即返回bool的函数对象
				// 或bool函数
*		·adjacent_find(begin, end)			// 查找相邻的重复元素，返回第一个位置的it
*		·bool binary_search(begin, end, T elem) // 二分法查找
				// 返回类型为bool
				// P.S. 在无序序列中不可使用

*	统计：
*		·int count(begin, end, T elem)			// 统计元素个数
*		·int count_if(begin, end, _Pred)		// 按条件统计
*				// _func 是谓词，即返回bool的函数对象
*				// 或bool函数
* 
*	排序：
*		·sort(begin, end, _Pred)		// 排序，默认升序
				// 可以通过 _Pred二元谓词，修改排序规则
*		·random_shuffle(begin, end)	// 打乱
*		·merge(beg1, end1, beg2, end2, dest)	// 合并
				// dest 为目标容器起始迭代器
				// 合并前必须是2个有序序列，合并后仍然有序
				// 合并前要给目标容器开辟空间
*		·reverse(begin, end)			// 反转
*	
*	拷贝
*		·copy(begin, end, dest)
*				// 拷贝前要给目标容器开辟空间
*	替换
*		·replace(begin, end, old_val, new_val)
*		·replace_if(begin, end, _Pred, new_val)
*				// _Pred为一元谓词
* 
*	交换
*		·swap(container c1, container c2)
* 
*	算数 求和
*		·accumulate(begin, end, val)
*							// val 为起始累加值
*	算数 填充
*		·fill(begin, end, val)
*							// val 为填充值
* 
*	集合 交并差
*		·set_intersection(beg1, end1, beg2, end2, dest)
							// 求两个容器的交集
*		·set_union(beg1, end1, beg2, end2, dest)		// 并集
*		·set_difference(beg1, end1, beg2, end2, dest)	
							// 差集
*/

#include<vector>
#include<algorithm>

/// <summary>
/// 遍历算法
/// for_each(const_it begin, const_it end, _func)
/// P.S. _func可以是函数名，也可以是函数对象
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
	// 函数名
	for_each(v.begin(), v.end(), print_int);
	cout << endl;
	// 函数对象
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

/// <summary>
/// 遍历
/// transform(const_it beg1, const_it end1,const_it beg2, _func)
/// P.S. 遍历前 要开辟空间
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
	// 函数名
	v2.resize(v1.size());	// transform前 要开辟空间
	transform(v1.begin(), v1.end(), v2.begin(), trans_int);
	for_each(v2.begin(), v2.end(), print_int);
	cout << endl;
	// 函数对象
	v3.resize(v2.size());	// transform前 要开辟空间
	transform(v2.begin(), v2.end(), v3.begin(), myTransForm());
	for_each(v3.begin(), v3.end(), myPrint());
	cout << endl;

}


/// <summary>
/// 查找 find(beg, end, elem)
/// P.S. 找到 返回迭代器，未找到 返回end
/// P.P.S. 自定义数据类型 需要重载operator== 以供find进行比较
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
	// 重载== , 底层find需要知道如何对比person数据
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
// 自定义数据类型 需要重载operator== 以供find进行比较
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
/// 查找 find_if(begin, end, _Pred)
/// _Pred需要是个谓词
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
	// 函数名
	vector<int>::iterator it = find_if(v.begin(), v.end(), greater_five);
	while (it != v.end()) {
		cout << "found element > 5 : " << *it << endl;
		// 函数对象
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
	
	// 函数名
	vector<Person58>::iterator it = find_if(vp.begin(), vp.end(), age_greater_20);
	while (it != vp.end()) {
		cout << "found person age > 20 :" << it->m_name << endl;
		// 函数对象
		it = find_if(++it, vp.end(), MyPersonGreater(20));
	}

}

/// <summary>
/// 查找 adjacent_find(begin, end)
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
// 自定义数据类型 需要重载operator== 以供find进行比较
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
/// 查找 bool binary_search(begin, end, value)
/// P.S. 无序序列不能查找
/// </summary>
static void test_binary_search() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	bool res = binary_search(v.begin(), v.end(),9);
	if (res) cout << "found" << endl;
	else cout << "not found" << endl;

	// 如果是无序序列，返回结果不一定正确
	v.push_back(2);		// 二分法，第一次和最后一个元素进行比较
	res = binary_search(v.begin(), v.end(), 9);
	if (res) cout << "found" << endl;
	else cout << "not found" << endl;

}


/// <summary>
/// 统计 int count(begin, end, T elem)
/// P.S. 自定义数据类型 需要重载operator== 以供find进行比较
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
// 自定义数据类型，需要重载operator==(const MyData& my)
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
/// 统计 int count_if(begin, end, _Pred)
/// _Pred是个谓词
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

	// 函数名
	int cn = count_if(vp.begin(), vp.end(), age_greater_20);
	cout << "the number of person age > 20 : " << cn << endl;
	// 函数对象
	cn = count_if(vp.begin(), vp.end(), MyPersonGreater(10));
	cout << "the number of person age > 10 : " << cn << endl;
}


/// <summary>
/// 排序 sort(begin, end, _Pred)
/// _Pred 是二元谓词，默认升序
/// </summary>
static void test_sort() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
		v.push_back(i * i);
	}

	// 默认升序
	sort(v.begin(), v.end());

	for_each(v.begin(), v.end(), print_int);
	cout << endl;

	// 改为降序
	// 利用内建函数对象
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
/// 打乱 random_shuffle(begin, end)
/// 反转 reverse(begin, end)
/// </summary>
static void test_random_shuffle() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print_int);
	cout << endl;

	// 打乱
	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), print_int);
	cout << endl;

	// 反转
	reverse(v.begin(), v.end());

	for_each(v.begin(), v.end(), print_int);
	cout << endl;

}


/// <summary>
/// 合并 merge(beg1, end1, beg2, end2, target.beg)
/// P.S. 两个容器必须为有序序列
///		 合并后仍然有序
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

	// 合并，需要提前给_dest开辟空间
	vector<int> v;
	v.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	
	for_each(v.begin(), v.end(), print_int);

}


/// <summary>
/// 拷贝 copy(begin, end, dest)
/// P.S. 拷贝前，要先给目标容器开辟空间
/// </summary>
static void test_copy() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), print_int);
	cout << endl;

	// 拷贝前 要开辟空间
	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), print_int);

}

/// <summary>
/// 替换 replace(begin, end, old_val, new_val)
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
/// 替换 replace_if(begin, end, _Pred, new_val)
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
/// 互换 swap(container c1, container c2)
/// P.S. 交换的必须是同种容器，但可以大小不同
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

	// 交换
	swap(v1, v2);
	cout << "after swap()..." << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}


#include<numeric>

/// <summary>
/// 算数求和 accumulate(begin, end, val)
///	P.S. val 为起始值累加值，通常为0
/// </summary>
static void test_accumulate() {
	vector<int> v;

	for (int i = 0; i < 100; i++) {
		v.push_back(i * i);
	}

	// 求和
	int res = accumulate(v.begin(), v.end(), 0);

	cout << "sum = " << res << endl;
}

/// <summary>
/// 填充 fill(begin, end, val)
/// </summary>
static void test_fill() {
	vector<int> v;

	v.resize(10);		// resize，填充默认值 0
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	// 填充 999
	fill(v.begin()+5, v.end(), 999);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}


/// <summary>
/// 集合 求两个容器的交、并、差
/// set_intersection(beg1, end1, beg2, end2, dest)
/// set_union(beg1, end1, beg2, end2, dest)
/// set_difference(beg1, end1, beg2, end2, dest)
/// P.S. 原容器 必须为 有序序列
///		 需要提前为目标容器 开辟空间
///		 返回值 为 所求集合末尾元素的迭代器 不一定= 容器的end
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

	// 目标容器需要提前开辟空间
	vector<int> v3;
	v3.resize(v1.size() < v2.size() ? v1.size() : v2.size());
	cout << "set_intersection()..." << endl << endl;

	// 返回位置迭代器
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