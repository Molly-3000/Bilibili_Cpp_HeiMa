#pragma once
#include "worker.h"


string Worker::dutyInfo = "完成经理交代的任务";

string Worker::getDeptName() {
	return string("员工");
}

void Worker::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< " \t姓名：" << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t职责：" << dutyInfo << endl;
}

Worker::Worker(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}