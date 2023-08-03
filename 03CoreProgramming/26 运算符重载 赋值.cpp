#include"head.h"

/*
* 重载赋值运算符
* 
* =
* 
* 编译器提供的是浅拷贝，析构时可能导致重复释放
* 
* 注意：先判断是否有数据，有则释放；然后再深拷贝
* 
*/

class Person26 {
public:
	Person26(int age) :m_Age(new int(age)) {}

	~Person26() { 
		if (this != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}

	Person26& operator= (Person26 &p) {

		// 编译器提供的 = 是浅拷贝
		// m_Age = p.m_Age
		// 在析构的时候 可能会导致堆区重复释放

		// 先判断是否有数据在堆区，有则释放
		if (m_Age != NULL) {
			delete m_Age;			// 先释放
		}
		m_Age = new int(*p.m_Age);  // 再分配
		return *this;
	}

	int* m_Age;
};

static void test01() {
	Person26 p1(18);
	Person26 p2 = 20;
	Person26 p3 = 30;
	p3 = p2 = p1;	// 运算顺序 从右往左
	cout << " the age of person1 is " << *p1.m_Age << endl;
	cout << " the age of person2 is " << *p2.m_Age << endl;
	cout << " the age of person3 is " << *p3.m_Age << endl;
}

int main26() {

	test01();

	system("pause");
	return 0;
}