#pragma once
#include "manager.h"


string Manager::dutyInfo = "����ϰ彻�������񣬲��·������Ա��";

string Manager::getDeptName() {
	return string("����");
}

void Manager::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< " \t������" << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \tְ��" << dutyInfo << endl;
}

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
