#include"head.h"

/*
* 构造函数的分类 & 调用
* 
* 1、分类： 
*				按 参数分：有参/无参   （无参构造也叫 默认构造）

*				按 类型分：普通构造
*					  拷贝构造 !!! 传递 const + 引用
* 
* 2、调用方式：
*				括号法	显式法	隐式转换法
* 
* 
*/

class Person11 {
	int age;

public:
	// constructor
	Person11() {
		cout << "无参构造函数/默认构造函数" << endl;
	}
	Person11(int a) {
		age = a;
		cout << "有参构造函数" << endl;
	}

	// 拷贝构造函数
	Person11(const Person11& p) {
		// 将传入的对象 所有的属性 拷贝到当前对象身上
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}

	~Person11() {
		cout << "析构函数" << endl;
	}

};

int main11() {

	// 调用
	// 1、括号法：即通过 括号传参构造 或者 不传参调用默认构造函数
	
	// // 默认构造 ！！ 不能加括号
	// 不报错，但编译器会认为是一个 函数的声明
	// 不会创建对象，不调用默认构造函数
	// Person p1();   // 类似 void func();

	//Person p1;		// 默认构造
	//Person p2(10);	// 参数构造
	//Person p3(p2);	// 参数构造、拷贝构造

	// 2、显式构造：即显示调用构造函数
	Person11 p1;
	Person11 p2 = Person11(10);
	Person11 p3 = Person11(p2);

	Person11(10); // 右侧单列，是一个匿名对象。
				// 匿名对象 特点：当前 行代码 执行结束后，系统立即回收
				// 
				// ！！！ 不要用 拷贝构造函数 初始化匿名对象
				// eg. Person(p3);
				// 编译器会认为 Person (p3) 等价于 Person p3; 即是一个对象的声明，会无参构造一个p3对象
		
	// 3、隐式转换法：即等号右边 直接写参数
	Person11 p4 = 10; // 等价于 Person p4 = Person(10);
	Person11 p5 = p4; // Person p5 = Person(p4);

	system("pause");
	return 0;
}