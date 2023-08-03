#include"head.h"
#include"circle.h"
#include"point.h"

// Cube类 和 

class Cube {

private:
	double m_L, m_W, m_H;

public:
	void setL(double longitude) { m_L = longitude; }
	void setW(double width) { m_W = width; }
	void setH(double height) { m_H = height; }

	double getL() { return m_L; }
	double getW() { return m_W; }
	double getH() { return m_H; }

	double getVlocity() {
		return m_L * m_W * m_H;
	}

	double getArea() {
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	bool ifSame(Cube cube) {
		return (m_L == cube.m_L && m_W == cube.m_W && m_H == cube.m_H);
	}

};

bool ifCubeSame(Cube& a, Cube& b) {
	return a.ifSame(b);
}

bool ifCubeSame2(Cube& a, Cube& b) {
	return a.getL()==b.getL() && a.getW()==b.getW() && a.getH()==b.getH();
}

int cubeMain() {

	Cube c1, c2;
	c1.setL(1);
	c1.setW(2);
	c1.setH(1);

	c2.setL(1);
	c2.setW(1);
	c2.setH(1);
	
	cout << c1.getArea() << endl;
	cout << c1.getVlocity() << endl;

	cout << c1.ifSame(c2) << endl;
	cout << ifCubeSame(c1, c2) << endl;

	c2.setW(2);
	cout << ifCubeSame2(c1, c2) << endl;

	system("pause");
	return 0;
}

//class Point {
//private:
//	double m_x, m_y, m_z;
//
//public:
//	Point() {}
//	Point(double x,double y, double z) {
//		m_x = x;
//		m_y = y;
//		m_z = z;
//	}
//
//	void setX(double x) { m_x = x; }
//	void setY(double y) { m_y = y; }
//	void setZ(double z) { m_z = z; }
//
//	double getX() { return m_x; }
//	double getY() { return m_y; }
//	double getZ() { return m_z; }
//
//	double pointDistance(Point p) {
//		return sqrt(pow(m_x - p.getX(), 2) + pow(m_y - p.getY(), 2) + pow(m_z - p.getZ(), 2));
//	}
//
//};
//
//class Circle {
//private:
//	double m_radis;
//	Point m_center = Point(0, 0, 0);    //  1、类中的初始化，一般放在构造函数
//										//  2、Point m_center(0, 0, 0) 会报错
//public:
//	void setCenter(Point c) { m_center = c; }
//	void setRadis(double r) { m_radis = r; }
//
//	Point getCenter() { return m_center; }
//	double getRadis() { return m_radis; }
//
//	int pointOnCircle(Point p) {
//		double d = m_center.pointDistance(p) - m_radis;
//		return d > 0 ? 2 : (d == 0) ? 1 : 0;
//	}
//};

void pointInCircle(Point& p,Circle& c) {
	int result = c.pointOnCircle(p);
	switch (result) {
	case 0:
		cout << "点在圆内" << endl;
		break;
	case 1:
		cout << "点在圆上" << endl;
		break;
	case 2:
		cout << "点在圆外" << endl;
		break;
	default:
		break;

	}
}

int circleMain() {

	Circle c;
	c.setRadis(10);

	Point p0(0, 0, 0);
	c.setCenter(p0);
	pointInCircle(p0, c);

	Point p1(10, 0, 0);
	pointInCircle(p1, c);

	Point p2(11, 0, 0);
	pointInCircle(p2, c);

	system("pause");
	return 0;
}

int main09() {
	cubeMain();
	circleMain();
	return 0;
}