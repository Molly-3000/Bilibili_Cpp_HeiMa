#pragma once
#include"circle.h"
#include"head.h"
class Point {
private:
	double m_x, m_y, m_z;

public:
	Point() {}
	Point(double x, double y, double z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void setX(double x) { m_x = x; }
	void setY(double y) { m_y = y; }
	void setZ(double z) { m_z = z; }

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	double pointDistance(Point p);

};


double Point::pointDistance(Point p) {
	return sqrt(pow(m_x - p.getX(), 2) + pow(m_y - p.getY(), 2) + pow(m_z - p.getZ(), 2));
}