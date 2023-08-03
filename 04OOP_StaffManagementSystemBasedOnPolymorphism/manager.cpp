#pragma once
#include "manager.h"


string Manager::dutyInfo = "完成老板交给的任务，并下发任务给员工";

string Manager::getDeptName() {
	return string("经理");
}

void Manager::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< " \t姓名：" << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t职责：" << dutyInfo << endl;
}

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
