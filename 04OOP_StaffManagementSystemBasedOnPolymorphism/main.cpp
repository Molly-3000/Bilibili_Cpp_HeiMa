#pragma onece
#include"head.h"
#include"boss.h"
/*
* 职工管理系统
* 
* 类别：普通职工、经理、老板
* 信息：编号、姓名、岗位、职责
* 
* 职责：普通职工，完成经理交代的任务
*		经理，完成老板交代的任务，并下发任务给普通职工
*		老板，管理公司所有事务
* 
* 系统功能：
*		0、退出
*		1、添加职工信息		可批量添加
*		2、显示职工信息		所有
*		3、删除离职职工		通过编号
*		4、修改职工信息		通过编号
*		5、查找职工信息		通过编号或姓名
*		6、按编号排序		用户指定 升序或降序
*		7、清空所有文档		清空文件中所有职工信息，清空前需要再次确认
*/


int main() {

	StaffManager sm;
	int choice = 0;

	while (true) {
		sm.showMenu();

		cout << ">>> 请输入指令：" << endl;
		cin >> choice;

		switch (choice) {
		case 0:		//退出
			sm.exitSystem();
			break;
		case 1:		//增加
			sm.addStaff();
			break;
		case 2:		//显示
			sm.showStaff();
			break;
		case 3:		//删除
			sm.deleteStaff();
			break;
		case 4:		//修改
			sm.modifyStaff();
			break;
		case 5:		//查找
			sm.findStaff();
			break;
		case 6:		//排序
			sm.sortById();
			break;
		case 7:		//清除
			sm.clearFile();
			break;
		}
		system("pause");
		system("cls");
		sm.saveFile();
	}
	return 0;
}