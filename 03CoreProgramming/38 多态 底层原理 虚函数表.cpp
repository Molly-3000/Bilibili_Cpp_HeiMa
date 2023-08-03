#include "head.h"

/*
* 动态多态（动态绑定） 的 底层原理
* 
*		核心是虚函数表
* 
* 1、每个包含了虚函数的类，都包含一个虚表指针vptr
* 
* 2、虚表指针vptr指向该类的虚函数表vftable，该表维护所有虚函数的地址
*		（虚表属于类，不属于对象，即一个类只有一个虚表，所有对象共享）
*		（虚表 在编译阶段 就确定了函数地址）
* 
* 3、如果父类中有虚函数表，则子类中也有虚函数表
* 
* 4、当子类中重写虚函数时，子类的vftable中，新的虚函数将覆盖掉父类中的虚函数地址
* 
*/

// 空类 大小为1
// 因为空类、空结构体也可以实例化，为了区分不同的实例化对象
// 不同的对象，内存地址应该不同，所以编译器给空类隐含地增加了1个字节
class Animal38_ {};

// 基类
class Animal38 {
public:
	// 类内为虚函数维护了一个 vfptr，指向虚函数表
	// 虚函数表 维护了 该类 所有虚函数地入口地址
	virtual void speak() {
		cout << "The animal is speaking." << endl;
	}
};

// 派生类 重写虚函数
class Cat38 :public Animal38 {
public:
	// 继承了基类的vfptr，指向子类的vftable
	// 当派生类中 重写 基类的虚函数
	// 在vftable中，子类的虚函数会覆盖父类虚函数的地址
	void speak() {
		cout << "Meow." << endl;
	}
};

class Dog38 :public Animal38 {
	// 继承了基类的vfptr，指向子类的vftable
};

static void doSpeak(Animal38 & animal) {
	animal.speak();
}

static void test01() {
	Animal38 animal;
	doSpeak(animal);	// 基类的speak()

	Cat38 cat;
	doSpeak(cat);		// 重写，绑定到派生类的speak()

	Dog38 dog;
	doSpeak(dog);		// 未重写，绑定到基类的speak()
}

int main38() {

	test01();

	system("pause");
	return 0;
}