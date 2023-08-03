#include"head.h"
/*
* STL 仿函数 内建函数对象
* 
* 1、概念：STL 内建的一些函数对象
* 
*	 分类：算数仿函数	关系仿函数	逻辑仿函数
* 
*	 用法：需要引入头文件		#include<functional>
*		   这些仿函数所产生的对象、用法和一般函数完全相同
* 
* 2、算数仿函数
* 
*	 功能：实现四则运算
*		   其中negate是一元运算，其他是二元运算
* 
*	 函数原型：
*		·template<class T> T plus(const T& t1,const T& t2)		// 加
*		·template<class T> T minus(const T& t1,const T& t2)	// 减
*		·template<class T> T multiplies(const T& t1,const T& t2)// 乘
*		·template<class T> T divides(const T& t1,const T& t2)	// 除
*		·template<class T> T modulus(const T& t1,const T& t2)	// 取模
*		·template<class T> T negate(const T& t)				// 取反
* 
* 3、关系仿函数
* 
*	 功能：实现关系比较
* 
*	 函数原型：
*		·template<T> bool equal_to(const T& t1,const T& t2)
*		·template<T> bool not_equal_to(const T& t1,const T& t2)
*		·template<T> bool greater(const T& t1,const T& t2)
*		·template<T> bool greater_equal(const T& t1,const T& t2)
*		·template<T> bool less(const T& t1,const T& t2)
*		·template<T> bool less_equal(const T& t1,const T& t2)
* 
* 4、逻辑仿函数
* 
*	 功能：逻辑运算
* 
*	 函数原型：
*		·template<T> bool logical_and(const T& t1,const T& t2)	// 与
*		·template<T> bool logical_or(const T& t1,const T& t2)	// 或
*		·template<T> bool logical_not(const T& t)	// 非
* 
*/

#include<functional>		// 包含头文件

// 算数仿函数
static void test_calculation() {
	
	// 二元运算
	int v1 = 11, v2 = 22;
	cout << "v1 = " << v1 << " v2 = " << v2 << endl;
	// 加
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

	// 一元运算
	// negate
	cout << negate<int>()(v1) << endl;

}

#include<vector>
#include<algorithm>

// 关系仿函数
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

	// 升序 使用自定义函数对象 MyCompare57(
	sort(v.begin(), v.end(), MyCompare57());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// 使用内建函数对象 greater<int>()
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

// 逻辑仿函数
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
	v2.resize(v.size());	// 搬运前，要开辟空间

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