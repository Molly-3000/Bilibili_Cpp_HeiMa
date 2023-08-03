#include"head.h"

/*
* friend：友元
* 
*	public客厅，private卧室
*	有些private属性，也想让类外的一些特殊的函数或类访问
*		
* 作用：让一个函数或者类访问 另一个类 中的 私有成员
* 
* 实现：3种
*		1、全局函数做友元
*		2、类做友元
*		3、成员函数做友元	！！！注意
*/

class myFriend;
class Building;

// 3、类的成员函数做友元
class myFriend2 {
public:
	void visit(Building* building); 
	// 因为c++是从前往后依次编译的，所以
	// 友元类函数的声明必须在 Building类的定义之前
	// 友元类函数的实现必须在 Building类的定义之后
};

class Building {

	// 声明友元，可以访问私有成员
	friend void goodFriend(Building* building);			// 友元全局函数
	friend myFriend;									// 友元类
	friend void myFriend2::visit(Building* building);	// 友元成员函数

public:
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};


// 1、全局函数做友元
static void goodFriend(Building* building) {
	cout << " A good frind is visiting my " << building->m_SittingRoom << endl;
	cout << " A good frind is visiting my " << building->m_BedRoom << endl;
}

static void test01() {
	Building myHouse;
	goodFriend(&myHouse);
}


// 2、类做友元（友元类）
class myFriend {
public:
	void visit(Building* building) {
		cout << " A good frind is visiting my " << building->m_SittingRoom << endl;
		cout << " A good frind is visiting my " << building->m_BedRoom << endl;
	}
};

static void test02() {
	Building myHouse;
	myFriend friend1;
	friend1.visit(&myHouse);
}



void myFriend2::visit(Building* building) {
	cout << " A good frind is visiting my " << building->m_SittingRoom << endl;
	cout << " A good frind is visiting my " << building->m_BedRoom << endl;
}

static void test03() {
	Building myHouse;
	myFriend2 friend2;
	friend2.visit(&myHouse);
}

int main22() {

	test01();

	test02();

	test03();

	system("pause");
	return 0;
}