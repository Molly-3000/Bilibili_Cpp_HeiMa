#pragma once
#include "worker.h"


string Worker::dutyInfo = "��ɾ�����������";

string Worker::getDeptName() {
	return string("Ա��");
}

void Worker::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< " \t������" << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \tְ��" << dutyInfo << endl;
}

Worker::Worker(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}