#include"head.h"

/*
* 继承（extend）
* 
* 作用：提高代码复用率，减少重复
* 
* 语法：class 子类 : 继承方式 父类
*		e.g. class A : public B
* 
* 继承方式：public  |  protected  |  private
* 
* 说明：1、子类也叫派生类，父类也叫基类
*		2、子类中的成员包括两大部分
*			·从父类中继承得到的		体现类间的共性
*			·自己增加的成员			体现子类的个性
* 
*/

class webPage {

public:
	void showHeader() { cout << "首页、公开课、登录、注册" << endl; }
	void showFooter() { cout << "Thank you for watching. " << endl; }
	void showLeft() { cout << "Java;Python;C++ ..." << endl; }
	void showRight(){}
};

// extend
class javaPage :public webPage {
public:
	void showRight() { cout << "Java Course01 Course02..." << endl; }
};

class pythonPage :public webPage {
public:
	void showRight(){ cout << "Python Course01 Course02..." << endl; }
};

class cppPage :public webPage {
public:
	void showRight(){ cout << "C++ Course01 Course02..." << endl; }
};

static void test01() {
	webPage base;
	pythonPage python;
	base.showHeader();
	base.showLeft();
	python.showRight();
	python.showFooter();

}

int main29() {
	test01();

	system("pause");
	return 0;
}