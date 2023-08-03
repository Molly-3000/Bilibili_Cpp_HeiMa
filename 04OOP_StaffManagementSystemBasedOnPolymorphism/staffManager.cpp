#pragma once
#include "staffManager.h"

#include"staff.h"
#include"boss.h"
#include"manager.h"
#include"worker.h"

#include<fstream>
#define FILENAME "staff_list.txt"

// 从文件 staff_list.txt 获取职工人数
int getStaffNum() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int job;

	int num = 0;
	ifs >> id;

	while (ifs >> id && ifs >> name && ifs >> job) {
		num++;
	}
	ifs.close();
	return num;
}

void swapStaff(Staff* &st1,Staff* &st2) {
	Staff* temp = st1;
	st1 = st2;
	st2 = temp;
}

void StaffManager::clearFile() {
	string s;

	while (1) {
		cout << ">>> 确认清空职工列表吗？(y/n)" << endl;
		cin >> s;
		if (s == "y") {

			// 释放堆区数据，防止内存泄露
			if (this->staffNum > 0) {
				for (int i = 0; i < this->staffNum; i++) {
					if (this->staffArray[i] != NULL) {
						delete this->staffArray[i];		// 释放内存
					}
				}
			}
			this->staffNum = 0;
			delete[] this->staffArray;	// 释放堆区数组
			this->staffArray = nullptr;

			cout << ">>> 成功清除所有职工信息！" << endl;
			return;
		}
		else if (s == "n") return;
		cout << ">>> 请按要求输入指令！" << endl;
	}
}

// 选择排序
// 平均、最差、最佳O(time) = n^2	O(space)=1
// 比较次数=(n-1)!	交换次数=[0,n-1]
//void StaffManager::selectSortById(bool up) {
//	int size = this->staffNum;
//
//	// 每轮循环找到最大的或最小的
//	for (int i = 0; i < size-1; i++) {
//		int minORmax = i;
//
//		// 一轮比较
//		for (int j = i + 1; j < size; j++) {
//			if (up) {
//				if (this->staffArray[minORmax]->m_Id > this->staffArray[j]->m_Id) minORmax = j;
//			}
//			if (!up) {
//				if (this->staffArray[minORmax]->m_Id < this->staffArray[j]->m_Id) minORmax = j;
//			}
//		}
//		swapStaff(this->staffArray[i], this->staffArray[minORmax]);
//	}
//}

// 平均、最差、最佳O(time) = n^2	O(space)=1
// 比较次数=n(n-1)/2	交换次数=[0,n-1]
void StaffManager::selectSortById(bool up) {
	int size = this->staffNum;

	// 每轮循环找到最大的或最小的
	for (int i = 0; i < (size+1)/2; i++) {
		int minORmax = i;
		int maxORmin = i;
		// 一轮比较
		for (int j = i + 1; j < size-i; j++) {
			if (up) {
				if (this->staffArray[minORmax]->m_Id > this->staffArray[j]->m_Id) {
					minORmax = j;
				}
				if (this->staffArray[maxORmin]->m_Id < this->staffArray[j]->m_Id) {
					maxORmin = j;
				}
			}
			if (!up) {
				if (this->staffArray[minORmax]->m_Id < this->staffArray[j]->m_Id) {
					minORmax = j;
				}
				if (this->staffArray[maxORmin]->m_Id > this->staffArray[j]->m_Id) {
					maxORmin = j;
				}
			}
		}
		swapStaff(this->staffArray[i], this->staffArray[minORmax]);
		// 注意：原来的 i 换到了 minORmax 的位置
		if (maxORmin == i) maxORmin = minORmax;
		swapStaff(this->staffArray[size - 1 - i], this->staffArray[maxORmin]);
	}
}
// 冒泡排序
// 平均、最差、最佳O(time) = n^2	O(space)=1
// 比较次数=n(n-1)/2	交换次数=[0,n-1]
void StaffManager::bubbleSortById(bool up) {
	int size = this->staffNum;

	// 每轮循环 将1个元素归位 按序依次交换
	for (int i = 0; i < size; i++) {

		// 从后往前，第i轮有i个元素已经归为
		for (int j = size -1; j > i; j--) {
			if (this->staffArray[j]->m_Id < this->staffArray[j - 1]->m_Id){
				if (up) {
					swapStaff(this->staffArray[j], this->staffArray[j - 1]);
				}
			}
			else {
				if (!up) {
					swapStaff(this->staffArray[j], this->staffArray[j - 1]);
				}
			}
		}
	}
}
void StaffManager::sortById() {
	int flag;
	cout << ">>> 请输入排序规则：" << endl;
	cout << " 0：降序" << endl;
	cout << " 1：升序" << endl;
	cin >> flag;
	switch (flag)
	{
	case 0:
		selectSortById(false);
		break;
	case 1:
		selectSortById(true);
		break;
	default:
		cout << ">>> 请按要求输入指令！" << endl;
		return;
	}

	cout << ">>> 排序已完成：" << endl;
	this->showStaff();
}


// 重载
// 根据职工编号 查找其所在职工列表中的位置
// 如果存在则返回下标，不存在则返回-1
// 职工编号 不可重复
int StaffManager::findStaff(int id) {
	for (int i = 0; i < this->staffNum; i++) {
		if (this->staffArray[i]->m_Id == id) {
			cout << ">>> 找到职工：";
			this->staffArray[i]->showInfo();
			return i;
		}
	}
	return -1;
}

// 重载 根据姓名查找职工
// 如果存在则打印职工信息，不存在则返回-1
// 职工姓名 可重复
int StaffManager::findStaff(string name) {
	int ret = 0;
	for (int i = 0; i < this->staffNum; i++) {
		if (this->staffArray[i]->m_Name == name) {
			cout << ">>> 找到职工：";
			this->staffArray[i]->showInfo();
			ret++;
		}
	}
	return ret;
}

// 查找职工，按照编号或姓名
void StaffManager::findStaff() {
	if (this->staffNum == 0) {
		cout << ">>> 职工列表为空，无法查找！" << endl;
		return;
	}

	int findFlag;
	cout << ">>> 请输入查找方式：" << endl;
	cout << " 0:通过编号查找" << endl;
	cout << " 1:通过姓名查找" << endl;
	cin >> findFlag;

	int id;
	string name;
	int index;
	switch (findFlag)
	{
	case 0:
		cout << ">>> 请输入待查找职工编号：" << endl;
		cin >> id;
		index = this->findStaff(id);
		break;
	case 1:
		cout << ">>> 请输入待查找职工姓名：" << endl;
		cin >> name;
		index = this->findStaff(name);
		break;
	default:
		cout << ">>> 请按要求输入指令！" << endl;
		return;
	}

	if (index <0) {
		cout << ">>> 该职工不存在！" << endl;
	}

	system("pause");

}

// 修改前 需要先判断该职工是否存在
void StaffManager::modifyStaff() {
	if (this->staffNum == 0) {
		cout << ">>> 职工列表为空，无法修改职工信息！" << endl;
		return;
	}

	int id;
	cout << ">>> 请输入待修改信息职工的编号：" << endl;
	cin >> id;

	int index = this->findStaff(id);
	if (index < 0) {
		cout << ">>> 该职工不存在！" << endl;
		return;
	}

	this->staffArray[index]->showInfo();

	string name;
	int job;
	cout << "请输入新的编号：" << endl;
	cin >> id;
	
	while (this->findStaff(id) >= 0 ) {
		if (id == this->staffArray[index]->m_Id) break;
		cout << ">>> 该职工编号已被占用，请输入新的编号：" << endl;
		cin >> id;
	}

	cout << "请输入新的姓名：" << endl;
	cin >> name;
	cout << "请输入新的职位：" << endl;
	cout << " 1：普通职工" << endl;
	cout << " 2：经理" << endl;
	cout << " 3：老板" << endl;
	cin >> job;

	Staff* staff = NULL;
	switch (job) {
	case 1:
		staff = new Worker(id, name, 1);
		break;
	case 2:
		staff = new Manager(id, name, 2);
		break;
	case 3:
		staff = new Boss(id, name, 3);
		break;
	default:
		break;
	}

	this->staffArray[index] = staff;
	
	cout << ">>> 修改成功！更新后的信息为：" << endl;
	this->staffArray[index]->showInfo();
}

// 删除前 需要先判断该职工是否存在
void StaffManager::deleteStaff() {
	if (this->staffNum == 0) {
		cout << ">>> 职工列表为空，不可删除！" << endl;
		return;
	}

	int id;
	cout << ">>> 请输入待删除职工的编号：" << endl;
	cin >> id;
	
	// find index
	int index = findStaff(id);

	if (index < 0) {
		cout << ">>> 该职工不存在！" << endl;
		return;
	}

	// delete staff
	this->staffNum--;
	for (int i = index; i < this->staffNum; i++) {
		this->staffArray[i] = this->staffArray[i + 1];
	}
	
	cout << ">>> 已成功删除！" << endl;

}

// 保存职工列表到文件 staff_list.txt
void StaffManager::saveFile() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	// 先写职工人数
	ofs << this->staffNum << endl;

	for (int i = 0; i <this->staffNum; i++) {
		ofs << this->staffArray[i]->m_Id << " "
			<< this->staffArray[i]->m_Name << " "
			<< this->staffArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

// 打印所有职工信息
void StaffManager::showStaff() {
	if (this->staffNum == 0) {
		cout << ">>> 目前没有职工。" << endl;
		return;
	}
	for (int i = 0; i < this->staffNum; i++) {
		this->staffArray[i]->showInfo();
	}
}

// 批量添加职工
void StaffManager::addStaff() {
	int addNum;
	cout << "请输入要添加的职工人数：" << endl;
	cin >> addNum;

	if (addNum > 0) {

		int newSize = this->staffNum + addNum;
		Staff** newArray = new Staff * [newSize];

		// 将原来的职工指针列表拷贝到新的存储空间 
		if (this->staffArray != NULL) {
			int i = 0;
			while (i < this->staffNum) {
				newArray[i] = this->staffArray[i];
				i++;
			}
		}

		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int job;
			cout << "请输入新添加职工的编号：" << endl;
			cin >> id;

			while (this->findStaff(id) >= 0) {
				cout << ">>> 该职工编号已被占用，请输入新的编号：" << endl;
				cin >> id;
			}

			cout << "请输入新添加职工的姓名：" << endl;
			cin >> name;
			cout << "请输入新添加职工的职位：" << endl;
			cout << " 1：普通职工" << endl;
			cout << " 2：经理" << endl;
			cout << " 3：老板" << endl;
			cin >> job;

			Staff* staff = NULL;
			switch (job)
			{
			case 1:
				staff = new Worker(id, name, 1);
				break;
			case 2:
				staff = new Manager(id, name, 2);
				break;
			case 3:
				staff = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newArray[this->staffNum + i] = staff;
		}

		// 释放原来的职工指针列表
		delete[] this->staffArray;

		// 更新职工列表
		this->staffArray = newArray;
		this->staffNum = newSize;
		this->fileEmpty = false;

		cout << "成功添加" << addNum << "名新职工！" << endl;
	}

	else {
		cout << "Wrong Input!" << endl;
	}

	system("pause");
	system("cls");

}

// 退出职工系统
void StaffManager::exitSystem() {
	cout << "Good Bye!" << endl;
	system("pause");
	exit(0);		// 退出正在运行的程序
}

// 打印菜单
void StaffManager::showMenu() {
	cout << "=========================================" << endl;
	cout << "***********  Welcome to SMS!  ***********" << endl;
	cout << "***********  0: 退出管理系统  ***********" << endl;
	cout << "***********  1: 添加职工信息  ***********" << endl;
	cout << "***********  2: 显示职工信息  *********** " << endl;
	cout << "***********  3: 删除离职职工  *********** " << endl;
	cout << "***********  4: 修改职工信息  *********** " << endl;
	cout << "***********  5: 查找职工信息  *********** " << endl;
	cout << "***********  6: 按照编号排序  *********** " << endl;
	cout << "***********  7: 清空所有信息  *********** " << endl;
	cout << "=========================================" << endl;
}


StaffManager::StaffManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 首次进入系统，文件不存在
	if (!ifs.is_open()) {
		cout << ">>> The staff file doesn't exist." << endl;
		this->staffNum = 0;
		this->staffArray = NULL;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	// 文件已经存在，但被清空
	int num;
	ifs >> num;
	if (num == 0) {	// 判断文件是否为空
		cout << ">>> The staff file is empty." << endl;
		this->staffNum = 0;
		this->staffArray = NULL;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	// 文件不为空
	this->staffNum = num;
	this->staffArray = new Staff * [num];	// 创建存放在堆区的指针数组
	this->fileEmpty = false;
	this->initStaff();
	ifs.close();
}


void StaffManager::initStaff() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int i = 0;
	ifs >> i;

	int id;
	string name;
	int job;
	i = 0;
	while (ifs >> id && ifs >> name && ifs >> job) {
		Staff* staff = NULL;
		switch (job)
		{
		case 1:
			staff = new Worker(id, name, 1);
			break;
		case 2:
			staff = new Manager(id, name, 2);
			break;
		case 3:
			staff = new Boss(id, name, 3);
			break;
		default:
			break;
		}
		this->staffArray[i] = staff;
		i++;
	}

	ifs.close();
	cout << ">>> 初始化员工列表成功！已加载" << this->staffNum << "名职工信息。" << endl;
}


StaffManager::~StaffManager() {
	if (this->staffArray != NULL) {
		// 删除堆区的每个职工对象
		for (int i = 0; i < this->staffNum; i++) {
			delete this->staffArray[i];
			this->staffArray[i] = NULL;
		}
		// 删除堆区的指针数组
		delete[] this->staffArray;
		// 避免野指针
		this->staffArray = NULL;
	}
	this->staffNum = 0;
}