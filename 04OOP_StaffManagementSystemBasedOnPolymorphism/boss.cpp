#pragma once
#include "boss.h"

string Boss::dutyInfo = "����˾��������";

string Boss::getDeptName() {
	return string("�ϰ�");
}

void Boss::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< " \t������" << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \tְ��" << dutyInfo << endl;
}

Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
