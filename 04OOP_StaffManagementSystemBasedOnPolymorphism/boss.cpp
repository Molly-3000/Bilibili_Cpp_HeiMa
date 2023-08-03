#pragma once
#include "boss.h"

string Boss::dutyInfo = "管理公司所有事务";

string Boss::getDeptName() {
	return string("老板");
}

void Boss::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< " \t姓名：" << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t职责：" << dutyInfo << endl;
}

Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
