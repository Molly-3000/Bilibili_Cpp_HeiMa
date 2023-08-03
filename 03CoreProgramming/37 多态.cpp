#include"head.h"

/*
* 多态 Polynorphism
* 
* 两类：
*		静态多态：函数重载，包括运算符重载		（函数名的复用）
*		动态多态：由虚函数 和 派生类 共同实现的运行时的多态
* 
* 区别：
*		静态多态 函数地址早绑定		编译阶段确定函数地址
*		动态多态 函数地址晚绑定		运行阶段确定函数地址
* 
* 动态多态的 实现条件：
*		1、有继承关系，即有基类和派生类
*		2、派生类要 重写 基类中的 虚函数
*					··		  ···
*		*重写：实函数和虚函数 返回值类型 函数名 参数列表 完全一致
*		
* 动态多态的 使用：
*		父类的指针 或 引用 指向子类的对象
*			  ··    ··
*		父类是静态类型     子类是动态类型
* 
* 动态多态的 原理：
*		子类对象在内存中包括两个部分，
*			父类部分（父类非静态成员）和子类部分（子类非静态成员）
*		在通过引用或指针的 实现的 隐式类型转换中
*			子类转化为父类，本质是因为 每个子类对象都包括一个父类部分
*		指针或引用实际上 绑定到了这个父类部分上
*/

class Animal37 {
public:

	// 地址早绑定 在编译阶段确定函数地址
	// speak()函数绑定为 Animal.speak()
	//void speak() {
	//	cout << "The animal is speaking." << endl;
	//}

	// 虚函数 
	// 地址晚绑定 运行阶段绑定为 派生类.speak()
	virtual void speak() {
		cout << "The animal is speaking." << endl;
	}
};

class Cat37:public Animal37 {
public:
	void speak() {
		cout << "Meow." << endl;
	}
};

class Dog37:public Animal37 {
public:
	void speak() {
		cout << "Woof." << endl;
	}
};


void doSpeak(Animal37& animal) {	// Animal & animal = cat;
	animal.speak();
}

static void test01() {

	Animal37 animal;
	doSpeak(animal);

	Cat37 cat;
	doSpeak(cat);	// Animal & animal = cat; // 子类可以转化为父类，反之不行

	Dog37 dog;
	doSpeak(dog);	// Animal & animal = dog;


}

int main37() {

	test01();

	system("pause");
	return 0;
}