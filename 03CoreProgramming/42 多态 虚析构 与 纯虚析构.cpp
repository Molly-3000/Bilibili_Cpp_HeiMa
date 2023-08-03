#include"head.h"

/*
* 多态	虚析构 和 纯虚析构
*
*	作用：通过将父类的析构函数改为 虚析构 或 纯虚析构的方式
*			解决父类指针 无法调用 子类析构函数的问题
*					从而通过父类指针 释放 堆区的子类对象
* 
*	原理：如果析构函数并非虚函数，那么delete时，
*				无动态绑定，执行的是父类（即静态类型）的析构函数
*		  如果析构函数是虚函数，那么delete时，
*				将通过子类对象的vptr动态绑定到子类（即动态类型）的虚构函数
*				且子类的析构（或构造）函数都会隐式调用父类析构（或构造）函数
*											  ··super(), ~super()
* 
* 虚析构vs纯虚析构
* 
*	共性：可以解决父类释放子类对象的问题（无法释放干净）
*		都需要子类提供析构的函数实现
* 
*	区别：有纯虚析构的类为抽象类，无法实例化
* 
* 虚析构语法
*	virtual ~ClassName() {}
* 
* 纯虚析构语法
*  virtual ~ClassName() = default;	// 析构函数不能未实现
* 
*
*/

class AbstractAnimal42 {
public:
	AbstractAnimal42() {
		cout << " This is Animal constructor" << endl;
	}
	virtual void speak() = 0;

	//virtual ~AbstractAnimal42() {	// 虚析构 动态绑定，父类指针可以释放子类对象
	//	cout << " This is virtual Animal deconstructor" << endl;
	//}

	virtual ~AbstractAnimal42() = default;	// 纯虚析构
};

class Cat42 :public AbstractAnimal42 {
public:
	Cat42() {
		cout << " This is Cat constructor" << endl;
	}
	void speak() {
		cout << " Meow." << endl;
	}

	// 虚属性 会继承
	~Cat42() {
		cout << " This is virtual Cat deconstructor" << endl;
	}
};

static void test01() {
	AbstractAnimal42* animal = new Cat42;
	animal->speak();
	delete animal;
}


int main42() {

	test01();

	system("pause");
	return 0;
}