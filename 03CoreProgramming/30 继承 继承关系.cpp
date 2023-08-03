#include"head.h"

/*
* 继承关系：三种
*			public | protected | private
* 
* 从父类中继承得到的属性，访问权限由 继承关系 和 父类中定义的访问权限 共同决定
*			优先级 public < protected < private
* 
*	父类						子类
*				公共继承		保护继承		私有继承
*	public		public			protected		private
*	protected	protected		protected		private
*	private		不可访问		不可访问		不可访问
* 
*/		

class Base30 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1:public Base30{
public: 
	Son1() {
		m_A = 1;	// 父类中public		->public继承	->子类中public
		m_B = 2;	// 父类中protected	->public继承	->子类中protected
		//m_C = 3;	// error, m_C is privated, 子类不可访问
	}
};

class Son2:protected Base30{
public:
	Son2() {
		m_A = 1;	// 父类中public		->protected继承		->子类中protected
		m_B = 2;	// 父类中protected	->protected继承		->子类中protected
		//m_C = 3;	// error, m_C is privated, 子类不可访问
	}
};

class Son3:private Base30{
public:
	Son3() {
		m_A = 1;	// 父类中public		->private继承		->子类中private
		m_B = 2;	// 父类中protected	->private继承		->子类中private
		//m_C = 3;	// error, m_C is privated, 子类不可访问
	}
};

static void test01() {
	Son1 son1;
	son1.m_A = 10;
	//son1.m_B = 20;	//error, m_B is protected，类外不可访问

	Son2 son2;
	//son2.m_A = 10;	//error, m_A is protected，类外不可访问
	//son2.m_B = 20;	//error, m_B is protected，类外不可访问

	Son3 son3;
	//son3.m_A = 10;	//error, m_A is private，类外不可访问
	//son3.m_B = 20;	//error, m_B is private，类外不可访问
}

class GrandSon3 :public Son3 {
public:
	GrandSon3() {
		//m_A = 100;	//error, m_A is private，类外不可访问
	}
};

int main30() {
	test01();

	system("pause");
	return 0;
}