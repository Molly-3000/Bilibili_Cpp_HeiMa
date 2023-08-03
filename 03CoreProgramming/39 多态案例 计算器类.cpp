#include "head.h"

class Calculater39 {
public:
	
	int getResult(string opr) {
		if (opr == "+")	return num1 + num2;
		else if (opr == "-") return num1 - num2;
		else if (opr == "*") return num1 * num2;
		// 想要新功能 就需要 修改源码
		// 不满足开闭原则：对扩展进行开发，对修改进行关闭
	}
	int num1, num2;
};

static void test01() {
	Calculater39 c;
	c.num1 = 10;
	c.num2 = 10;
	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;
}

// 利用多态进行开发
// 好处：
//		1、组织结构清晰		（低耦合
//		2、可读性强			（高内聚
//		3、便于前期和后期的扩展和维护
// 
// 基类——抽象类
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int num1, num2;
};
// 加法计算器
class AddCalculator :public AbstractCalculator {
public:
	int getResult() {
		return num1 + num2;
	}
};
// 减法计算器
class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return num1 - num2;
	}
};
// 乘法计算器
class MulCalculator :public AbstractCalculator {
public:
	int getResult() {
		return num1 * num2;
	}
};


static void test02() {

	// 多态使用方式
	// 父类指针 或 引用 指向子类对象

	AbstractCalculator* cal;
	AddCalculator add;
	AbstractCalculator & cal2 = add;

	cal = new AddCalculator();
	cal->num1 = 10;
	cal->num2 = 10;
	cout << cal->num1 << " + " << cal->num2 << " = " << cal->getResult() << endl;
	delete cal;

	cal = new SubCalculator();
	cal->num1 = 10;
	cal->num2 = 10;
	cout << cal->num1 << " - " << cal->num2 << " = " << cal->getResult() << endl;
	delete cal;

	cal = new MulCalculator();
	cal->num1 = 10;
	cal->num2 = 10;
	cout << cal->num1 << " * " << cal->num2 << " = " << cal->getResult() << endl;
	delete cal;
}

int main39() {

	test01();

	test02();

	system("pause");
	return 0;
}