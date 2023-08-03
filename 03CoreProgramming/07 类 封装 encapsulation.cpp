#include"head.h"

#define PI 3.14


//
// 类 class
// 
// 语法：class 类名 {
//			类的成员（包括属性和行为）
//		}
//

class Circle {

// 访问权限
public:
	// 属性
	double radis;
private:
	double diameter, circumference, area;

public: 
	// 行为
	void setR(double r) {
		radis = r;
		diameter = 2 * radis;
		circumference = PI * diameter;
		area = PI * radis * radis;
	}

	void setD(double d) {
		radis = d/2;
		diameter = d;
		circumference = PI * diameter;
		area = PI * radis * radis;
	}

	void setC(double c) {
		radis = c / 2 / PI;
		diameter = 2 * radis;
		circumference = c;
		area = PI * radis * radis;
	}

	void setA(double a) {
		radis = sqrt(a / PI);
		diameter = 2 * radis;
		circumference = PI * diameter;
		area = a;
	}

	double getRad() { return radis; }
	double getDia() { return diameter; }
	double getCir() { return circumference; }
	double getArea() { return area; }
};


class Student {

public:
	string name;
	int id;

	void showStudent() {
		cout << "student name: " << name << endl;
		cout << "student number: " << id << endl;
	}

};


int main07() {

	// 实例化一个circle对象
	// 实例化：通过一个类 创建一个对象的过程
	Circle c1;

	// 访问对象的属性
	c1.radis = 10;

	c1.setR(10);
	cout << "圆的周长为：" << c1.getCir() << endl;

	c1.setC(c1.getCir());
	cout << "圆的半径为：" << c1.getRad() << endl;

	Student s1;
	s1.name = "aaa";
	s1.id = 111;
	s1.showStudent();

	system("pause");
	return 0;
}