#include"head.h"
#include<string>
/*
* Class Template Case
* 
* Description:实现一个通用的数组类
* 
*	·可以对内置数据类型以及自定义数据类型的数据进行存储
*	·将数组中的数据存储到堆区
*	·构造函数中可以传入数组容量
*	·提供对应的拷贝构造函数以及operator=防止浅拷贝问题	！！注意返回类型
*	·提供尾插法和尾删法对数组中国的数据进行增加和删除
*	·可以通过下标的方式访问数组中的元素
*	·可以获取数组中当前元素个数和数组容量
* 
*/

#include"16 myArray.hpp"

template<class T>
static void print(myArray<T>& arr) {
	cout << "printing array:";
	for (int i = 0; i < arr.size(); i++) {
		cout << " " << arr[i];
	}
	cout << endl;
}

static void test1() {
	myArray<int> arr1(5);

	for (int i = 0; i < arr1.capacity(); i++) {
		arr1.push_back(i);
	}

	myArray<int> arr2 = arr1;
	myArray<int> arr3(arr2);
	myArray<double> arr4(8);

	for (int i = 0; i < arr4.capacity(); i++) {
		arr4.push_back( double(i) * double(i));
	}

	arr1.push_back(111);
	arr2.pop_back();
	arr4.pop_back();

	print<int>(arr1);
	print(arr2);
	print<int>(arr3);

	arr4[3] = 55;
	print(arr4);

}


class Person16 {
public:
	Person16() {}
	Person16(string name, int age) :m_name(name), m_age(age) {}

	string m_name;
	int m_age;
};

static void printPersonArray(myArray<Person16>& arr) {
	cout << "printing array:";
	for (int i = 0; i < arr.size(); i++) {
		cout << " " << arr[i].m_name << " " << arr[i].m_age;
	}
	cout << endl;
}

static void test2() {
	myArray<Person16> arr(10);
	arr.push_back(Person16("zhangsan", 17));
	arr.push_back(Person16("lisi", 34));
	arr.push_back(Person16("wangwu", 24));
	arr.pop_back();
	arr.push_back(Person16("zhaoliu", 19));
	printPersonArray(arr);
	cout << arr.capacity() << " " << arr.size() << endl;
}

int main0() {

	test1();

	test2();
	return 0;
}