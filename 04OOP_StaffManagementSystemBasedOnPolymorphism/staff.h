#pragma once
#include<string>
#include<iostream>
using namespace std;

/*
* 类别：普通职工、经理、老板
* 信息：编号、姓名、所在部门编号、岗位、职责
*/

class Staff {
public:

	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;

	int m_Id;
	string m_Name;
	int m_DeptId;
};
