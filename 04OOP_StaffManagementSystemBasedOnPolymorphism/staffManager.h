#pragma once
#include<iostream>
using namespace std;

#include"staff.h"


class StaffManager {
public:

	StaffManager();

	void clearFile();

	void sortById();
	void selectSortById(bool up);
	void bubbleSortById(bool up);

	void findStaff();

	int findStaff(int id);

	int findStaff(string name);

	void deleteStaff();

	void modifyStaff();

	void showMenu();

	void exitSystem();

	void addStaff();

	void showStaff();

	void saveFile();

	void initStaff();


	~StaffManager();

	int staffNum;
	Staff** staffArray;	 // 指向存放在堆区的 指针数组
	bool fileEmpty;
};
