#pragma once   // ��ֹͷ�ļ��ظ�����
#include"point.h"
#include"head.h"

class Circle {
private:
	double m_radis;
	Point m_center = Point(0, 0, 0);	// ����������һ���� ��Ϊ��Ա ��ʼ����Ҫע�⣡����
										// �����õķ�ʽ{} �� = ()   
										//  1�����еĳ�ʼ����һ����ڹ��캯��
										//  2��Point m_center(0, 0, 0) �ᱨ��
public:
	void setCenter(Point c) { m_center = c; }
	void setRadis(double r) { m_radis = r; }

	Point getCenter() { return m_center; }
	double getRadis() { return m_radis; }

	int pointOnCircle(Point p);  // �����ں�����Ϊ ���� �� ʵ��
};


// �����ں��������д
// Circle:: ��ʾ������ΪCircle��
int Circle::pointOnCircle(Point p) {
	double d = m_center.pointDistance(p) - m_radis;
	return d > 0 ? 2 : (d == 0) ? 1 : 0;
}