#pragma once   // 防止头文件重复包含
#include"point.h"
#include"head.h"

class Circle {
private:
	double m_radis;
	Point m_center = Point(0, 0, 0);	// 在类中让另一个类 作为成员 初始化需要注意！！！
										// 可以用的方式{} 或 = ()   
										//  1、类中的初始化，一般放在构造函数
										//  2、Point m_center(0, 0, 0) 会报错
public:
	void setCenter(Point c) { m_center = c; }
	void setRadis(double r) { m_radis = r; }

	Point getCenter() { return m_center; }
	double getRadis() { return m_radis; }

	int pointOnCircle(Point p);  // 将类内函数分为 声明 和 实现
};


// 将类内函数拆出来写
// Circle:: 表示作用域为Circle类
int Circle::pointOnCircle(Point p) {
	double d = m_center.pointDistance(p) - m_radis;
	return d > 0 ? 2 : (d == 0) ? 1 : 0;
}