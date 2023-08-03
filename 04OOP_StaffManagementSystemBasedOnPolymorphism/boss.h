#pragma once
#include<iostream>
using namespace std;

#include"staff.h"


class Boss :public Staff {
public:
	Boss(int id, string name, int dId);

	void showInfo();
	string getDeptName();
	static string dutyInfo;
};
