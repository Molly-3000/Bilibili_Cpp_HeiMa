#pragma once
#include<string>
#include<iostream>
using namespace std;

/*
* �����ְͨ���������ϰ�
* ��Ϣ����š����������ڲ��ű�š���λ��ְ��
*/

class Staff {
public:

	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;

	int m_Id;
	string m_Name;
	int m_DeptId;
};
