#pragma once
#include<iostream>
using namespace std;

#include"staff.h"

class Worker :public Staff {
public:
	Worker(int id, string name, int dId);

	void showInfo();

	string getDeptName();

	static string dutyInfo;
};

