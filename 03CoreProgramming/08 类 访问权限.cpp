#include"head.h"

//
// 访问权限
// 3种
// 公共 public      类内可访问	类外可访问	
// 保护 protected	类内可		类外不可		子类可
// 私有 private		类内可		类外不可		子类不可
// 
// private的好处：
//		1、成员属性私有化，可以自己控制读写权限
//		2、对于写权限，可以检测数据的有效性
//



class Person {
public:
	string m_Name;
protected:
	string m_Car;
private:
	int m_Password;

	string name;	// 可读可写
	int age = 0;	// 只读
	string lover = "someone";	// 只写

public:
	void func() {
		m_Name = "zhangsan";	// public		类内可
		m_Car = "qq";			// protected	类内可
		m_Password = 111;		// private		类内可
	}
	
	// 对私有属性进行读写控制 的 接口
	void setName(string newName) { name = newName; }	// 写 接口
	string getName() { return name; }					// 读 接口

	// 对写操作，检测数据的有效性
	//  0 <= age <= 150 
	void setAge(int newAge) { 
		if (newAge < 0 || newAge>150) {
			cout << "Non-valid age!" << endl;
			return;
		}
		age = newAge; 
	}			// 写

	string getLover() { return lover; }					// 读
};

// struct 和 class
// 唯一的区别就是成员 默认的访问权限不同
// struct 默认 public
// class  默认 private

class C1 {
	int m;
}c1;
struct C2 {
	int m;
}c2;

int main08() {

	Person p1;
	p1.m_Name = "zhangsan";		// public		类外可
	//p1.m_Car = "benci";       // protected	类外不可
	//p1.m_Password = "benci";	// private		类外不可

	p1.setAge(-1);
	p1.setAge(18);

	//c1.m;		// class  成员 默认 private， 类外不可
	c2.m;		// struct 成员 默认 public，  类外可

	system("pause");
	return 0;
}