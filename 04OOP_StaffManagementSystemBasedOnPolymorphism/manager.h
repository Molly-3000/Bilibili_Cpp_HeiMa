#pragma once
#include<iostream>
using namespace std;

#include"staff.h"

class Manager :public Staff {
public:
	Manager(int id, string name, int dId);

	void showInfo();

	string getDeptName();

	static string dutyInfo;
};
