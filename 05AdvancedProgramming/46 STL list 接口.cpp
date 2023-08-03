#include"head.h"
/*
* STL list 链表 常用接口
* 
* 构造函数：
*	·list<T> ();
*	·list<T>(const list<T>& lst)
*	·list<T>(const_it start, const_it end)
*	·list<T>(int n, T elem)
* 
* 赋值操作：
*	·list<T>& operator= (const list<T>& lst)
*	·list<T>& assign(const_it start, const_it end)
*	·list<T>& assign(int n, T elem)
* 
* 交换：
*	·list<T>& swap(const list<T>& lst)
* 
* 大小：
*	·bool empty()
*	·int size()
*	·list<T>& resize(int n)
*	·list<T>& resize(int n, T elem)
* 
* 插入数据：
*	·void push_back(T elem)		// 尾插
*	·void push_front(T elem)		// 头插
*	·list<T>::iterator list<T>::insert(const_it pos, T elem)
*	·list<T>::iterator list<T>::insert(const_it pos, int n, T elem)
*	·list<T>::iterator list<T>::insert(const_it pos, const_it start, const_it end)
* 
* 删除数据：
*	·void pop_back()
*	·void pop_front()
*	·void erase(const_it pos)
*	·void erase(const_it start, const_it end)
*	·void clear()
*	·void remove(T elem)		// 删除容器中所有与elem值匹配的元素
* 
* 数据存取：
*	·T fornt()
*	·T back()
* 
*	P.S.链表，不是连续空间存储，不支持随机访问，所以没有[]和at()
* 
* 排序：
*	·void sort()			// 升序
*	·void sort()			// 降序
* 
* !! 所有不支持随机访问的容器，不可以使用标准算法（即全局sort）
*			内部会提供对应的sort()算法(即成员sort)。
* 
*	 对于自定义数据类型，必须提供排序算法，不然无法排序
* 
* 反转：
*	·void reverse()		// 反转	
* 
*/

#include<list>
#include<algorithm>

static void print_list_int(const list<int>& lst) {
	cout << "list: ";
	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

/// <summary>
/// list<T>()
/// list<T>(const list<T>& lst)
/// list<T>(const_it start, const_it end)
/// list<T>(int n, T elem)
/// </summary>
static void test_construct() {
	// 默认构造
	list<int> lst1;
	
	// 尾插 push_back
	lst1.push_back(111);
	lst1.push_back(222);
	lst1.push_back(333);
	cout << "list1 after push_back()..." << endl;
	print_list_int(lst1);

	// 头插 push_front
	lst1.push_front(222);
	lst1.push_front(333);
	cout << "list1 after push_front()..." << endl;
	print_list_int(lst1);

	// 拷贝构造
	list<int> lst2(lst1);
	cout << "lst2..." << endl;
	print_list_int(lst2);

	// 区间构造
	list<int> lst3(lst1.begin()++,lst1.end()--);
	cout << "lst3..." << endl;
	print_list_int(lst3);

	// n个elem
	list<int> lst4(10, 100);
	cout << "lst4..." << endl;
	print_list_int(lst4);
}

/// <summary>
/// list<T>& operator=(const list<T>& lst);
/// list<T>& assign(const_it start, const_it end)
/// list<T>& assign(int n, T elem)
/// </summary>
static void test_assign() {
	list<int> L1, L2;

	L1.push_back(111);
	L1.push_back(222);
	L1.push_back(333);
	L1.push_front(888);
	L1.push_front(999);
	cout << "L1..." << endl;
	print_list_int(L1);

	// operator= ()
	L2 = L1;
	cout << "L2..." << endl;
	print_list_int(L2);

	// assign(const_it start, const_it end)
	L2.assign(++L1.begin(), --L1.end());		// 注意前置++/--
	cout << "L2..." << endl;
	print_list_int(L2);

	// assign(int n, T elem)
	L2.assign(10, 0);
	cout << "L2..." << endl;
	print_list_int(L2);
}

/// <summary>
/// list<T>& swap(const list<T>& lst)
/// </summary>
static void test_swap() {
	list<int> L1;

	L1.push_back(111);
	L1.push_back(222);
	L1.push_back(333);

	list<int> L2(10,0);

	cout << "before swap..." << endl;
	print_list_int(L1);
	print_list_int(L2);

	// 交换 swap(const list<T>& lst)
	L1.swap(L2);

	cout << "after swap..." << endl;
	print_list_int(L1);
	print_list_int(L2);

}

/// <summary>
/// bool empty()
/// int size()
/// void resize(int n)
/// void resize(int n, T elem)
/// </summary>
static void test_size() {
	list<int> lst;
	lst.push_back(111);
	lst.push_front(222);
	lst.push_front(333);

	// 为空 empty()
	if (lst.empty()) {
		cout << "the list is empty." << endl;
	}
	else {
		// 大小 size()
		cout << "the size of the list is " << lst.size() << endl;
		print_list_int(lst);
	}

	// resize(int n)
	lst.resize(5);
	cout << "after resize(5)..." << endl;
	print_list_int(lst);

	// resize(int n, T elem)
	lst.resize(10, 999);
	cout << "after resize(10, 999)..." << endl;
	print_list_int(lst);

	lst.resize(1);
	cout << "after resize(1)..." << endl;
	print_list_int(lst);

}

/// <summary>
/// void push_back(T elem)
/// void push_front(T elem)
/// 
/// list<T>::iterator insert(const_it pos, T elem)
/// list<T>::iterator insert(const_it pos, int n, T elem);
/// list<T>::iterator insert(const_it pos, const_it start, const_it end)
/// </summary>
static void test_insert() {
	list<int> lst;
	lst.push_back(000);

	list<int>::iterator	it = lst.insert(lst.begin(), 111);
	cout << *it;

	lst.insert(lst.end(), 3, 999);

	lst.insert(lst.begin(), lst.begin(), lst.end());


}

/// <summary>
/// void pop_back()
/// void pop_front()
/// void erase(const_it pos)
/// void erase(const_it start, const_it end)
/// void empty()
/// void remove(T elem)
/// </summary>
static void test_erase() {
	list<int> lst;

	for (int i = 0; i < 10; i++) {
		lst.push_back(i);
		lst.push_back(i * i);
	}
	print_list_int(lst);
	
	cout << "after pop_back()..." << endl;
	lst.pop_back();
	print_list_int(lst);

	cout << "after pop_front()..." << endl;
	lst.pop_front();
	print_list_int(lst);

	cout << "after erase(++l.begin())..." << endl;
	lst.erase(++lst.begin());
	print_list_int(lst);

	cout << "after erase(const_it start,const_it end)..." << endl;
	list<int>::iterator it1 = lst.begin();
	it1++;
	list<int>::iterator it2 = lst.end();
	it2--;
	lst.erase(lst.begin(),it1);		// begin 向后遍历，左闭右开
	print_list_int(lst);
	lst.erase(it2,lst.end());		// end 向前遍历，左开右闭
	print_list_int(lst);

	cout << "after remove(4)..." << endl;
	lst.remove(4);
	print_list_int(lst);

	cout << "after clear()" << endl;
	lst.clear();
	print_list_int(lst);
}

/// <summary>
/// T fronnt()
/// T back()
/// </summary>
static void test_data() {
	list<int> lst;
	for (int i = 0; i < 10; i++) {
		lst.push_back(i);
		lst.push_back(i * i);
	}
	print_list_int(lst);

	cout << "front():" << lst.front() << endl;
	cout << "back():" << lst.back() << endl;

}

/// <summary>
/// void sort()
/// void sort(bool func* func)
/// </summary>

static bool myCompare(int a, int b) {
	return a > b;
}
 
static void test_sort() {
	list<int> lst;

	for (int i = 0; i < 10; i++) {
		lst.push_front(i * i);
	}
	print_list_int(lst);

	cout << "after sort()..." << endl;
	lst.sort();
	print_list_int(lst);

	cout << "after sort(func* func)" << endl;
	lst.sort(myCompare);
	print_list_int(lst);
}

/// <summary>
/// void reverse()
/// </summary>
static void test_reverse() {
	list<int> lst;

	for (int i = 0; i < 10; i++) {
		lst.push_front(i * i);
	}
	print_list_int(lst);

	cout << "after reverse()..." << endl;
	lst.reverse();
	print_list_int(lst);
}

int main46() {
	//test_construct();

	//test_assign();

	//test_swap();

	//test_size();

	//test_insert();

	//test_erase();
	 
	//test_data();

	test_sort();

	//test_reverse();

	return 0;
}