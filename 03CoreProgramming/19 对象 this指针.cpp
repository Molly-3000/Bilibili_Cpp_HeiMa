#include"head.h"
 
/*
* ========= this指针 =========
* this指针：c++提供的特殊的 对象指针，不需要定义，可以直接使用
* 
* this指针指向：调用该成员函数 的对象
* 
* this指针是隐含在 每一个非静态成员函数 的 参数 内的一种指针
*						 ~~~~~~~~~~~~~~
* 用途：
*	   ·当形参和成员变量同名时，可以用this指针区分		（解决名称冲突
*	   ·在类的非静态成员函数种 返回对象本身，可使用 retrun *this
*/

class Person19 {
public:

	// this指针作用1：解决名称冲突
	Person19(int age){
		this->age = age;
	}
	// 解决冲突的另一种办法：初始化列表
	//Person19(int age) :age(age) {}

	// this指针的作用2：返回对象本身
	// ！！！注意返回本体，需要以引用的方式返回
	Person19& PersonAgeAdd(Person19& p) {
		this->age += p.age;
		return *this;
	}

	int age;
};

static void test01() {
	Person19 p(18);
	cout << " The age of p is " << p.age << endl;
}

static void test02() {

	Person19 p1(10);

	Person19 p2 = 10;

	// 返回对象本身，可以链式编程，即追加
	p2.PersonAgeAdd(p1).PersonAgeAdd(p1).PersonAgeAdd(p1);

	cout << "The new age of p2 =  " << p2.age << endl;

	//// 如果不加引用 需要用新的对象接收，否则输出p2.age=20
	//Person19 p = p2.PersonAgeAdd(p1).PersonAgeAdd(p1).PersonAgeAdd(p1);
	//cout << "The new age of p2 =  " << p.age << endl;

}

int main19() {

	test01();
	system("cls");

	test02();

	system("pause");
	return 0;
}