//#include"head.h"

/*
* 菱形继承
* 
* 问题：
*		1、二义性/不明确				通过 作用域 解决
*		2、两份数据，浪费资源			通过 虚继承 解决
* 注意：
*		不建议使用多继承
*/

// 动物类
class Animal36 {
public:
	int m_Age;
	int m_Height;
	int m_Weight;
};

// 虚继承，在继承方式前加 virtual 关键字
//			此时，父类称为 虚基类 virtual base class
class Wolf : virtual public Animal36 {};

class Dog : virtual public Animal36 {};

class Husky : public Wolf, public Dog {};

static void test01() {
	Husky hs;

	//hs.m_Age = 1;	// error, 不明确
	hs.Wolf::m_Age = 1;
	hs.Dog::m_Age = 2;
	//cout << "Wolf m_Age = " << hs.Wolf::m_Age << endl;
	//cout << "Dog m_Age = " << hs.Dog::m_Age << endl;

	// cl /d1 reportSingleClassLayoutHusky "36..."
	// 两份 m_Age 数据，资源浪费

	// 通过虚继承，不再继承数据，而是指针
	// 只有一份数据
	// 
	//cout << "Wolf m_Age = " << hs.Wolf::m_Age << endl;
	//cout << "Dog m_Age = " << hs.Dog::m_Age << endl;


}

int main36() {

	test01();

	//system("pause");
	return 0;
}