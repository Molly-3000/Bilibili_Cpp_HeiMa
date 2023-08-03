#include<iostream>
using namespace std;

/*
* 继承 中的 对象模型
* 
* 父类中所有 非静态成员属性，都被子类继承了
* 
* （虽然父类私有成员，子类无法访问，但确实被继承了，只是被编译器隐藏了。
*/

class Base31 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son31_1 :public Base31 {
public:
	int m_D;
};

static void test01() {
	// 父类中所有非静态成员属性，都会被子类继承下去
	// 父类中的私有成员属性，被编译器隐藏了，不能访问，但被继承了
	cout << "size of Son1 is " << sizeof(Son31_1) << endl;	// 4 x 4 = 16

	// 可以利用cmd查看对象模型
	// 跳转到当前文件路径
	// 查看命令：cl -d1 reportSingleClassLayout类名 文件名
	//			 cl -d1 reportSingleClassLayoutSon31_1 "31 ..."
}

int main31() {

	test01();

	system("pause");
	return 0;
}