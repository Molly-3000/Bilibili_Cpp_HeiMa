#include"head.h"

#define PI 3.14


//
// �� class
// 
// �﷨��class ���� {
//			��ĳ�Ա���������Ժ���Ϊ��
//		}
//

class Circle {

// ����Ȩ��
public:
	// ����
	double radis;
private:
	double diameter, circumference, area;

public: 
	// ��Ϊ
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

	// ʵ����һ��circle����
	// ʵ������ͨ��һ���� ����һ������Ĺ���
	Circle c1;

	// ���ʶ��������
	c1.radis = 10;

	c1.setR(10);
	cout << "Բ���ܳ�Ϊ��" << c1.getCir() << endl;

	c1.setC(c1.getCir());
	cout << "Բ�İ뾶Ϊ��" << c1.getRad() << endl;

	Student s1;
	s1.name = "aaa";
	s1.id = 111;
	s1.showStudent();

	system("pause");
	return 0;
}