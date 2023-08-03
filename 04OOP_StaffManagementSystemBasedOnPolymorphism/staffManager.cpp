#pragma once
#include "staffManager.h"

#include"staff.h"
#include"boss.h"
#include"manager.h"
#include"worker.h"

#include<fstream>
#define FILENAME "staff_list.txt"

// ���ļ� staff_list.txt ��ȡְ������
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
		cout << ">>> ȷ�����ְ���б���(y/n)" << endl;
		cin >> s;
		if (s == "y") {

			// �ͷŶ������ݣ���ֹ�ڴ�й¶
			if (this->staffNum > 0) {
				for (int i = 0; i < this->staffNum; i++) {
					if (this->staffArray[i] != NULL) {
						delete this->staffArray[i];		// �ͷ��ڴ�
					}
				}
			}
			this->staffNum = 0;
			delete[] this->staffArray;	// �ͷŶ�������
			this->staffArray = nullptr;

			cout << ">>> �ɹ��������ְ����Ϣ��" << endl;
			return;
		}
		else if (s == "n") return;
		cout << ">>> �밴Ҫ������ָ�" << endl;
	}
}

// ѡ������
// ƽ���������O(time) = n^2	O(space)=1
// �Ƚϴ���=(n-1)!	��������=[0,n-1]
//void StaffManager::selectSortById(bool up) {
//	int size = this->staffNum;
//
//	// ÿ��ѭ���ҵ����Ļ���С��
//	for (int i = 0; i < size-1; i++) {
//		int minORmax = i;
//
//		// һ�ֱȽ�
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

// ƽ���������O(time) = n^2	O(space)=1
// �Ƚϴ���=n(n-1)/2	��������=[0,n-1]
void StaffManager::selectSortById(bool up) {
	int size = this->staffNum;

	// ÿ��ѭ���ҵ����Ļ���С��
	for (int i = 0; i < (size+1)/2; i++) {
		int minORmax = i;
		int maxORmin = i;
		// һ�ֱȽ�
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
		// ע�⣺ԭ���� i ������ minORmax ��λ��
		if (maxORmin == i) maxORmin = minORmax;
		swapStaff(this->staffArray[size - 1 - i], this->staffArray[maxORmin]);
	}
}
// ð������
// ƽ���������O(time) = n^2	O(space)=1
// �Ƚϴ���=n(n-1)/2	��������=[0,n-1]
void StaffManager::bubbleSortById(bool up) {
	int size = this->staffNum;

	// ÿ��ѭ�� ��1��Ԫ�ع�λ �������ν���
	for (int i = 0; i < size; i++) {

		// �Ӻ���ǰ����i����i��Ԫ���Ѿ���Ϊ
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
	cout << ">>> �������������" << endl;
	cout << " 0������" << endl;
	cout << " 1������" << endl;
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
		cout << ">>> �밴Ҫ������ָ�" << endl;
		return;
	}

	cout << ">>> ��������ɣ�" << endl;
	this->showStaff();
}


// ����
// ����ְ����� ����������ְ���б��е�λ��
// ��������򷵻��±꣬�������򷵻�-1
// ְ����� �����ظ�
int StaffManager::findStaff(int id) {
	for (int i = 0; i < this->staffNum; i++) {
		if (this->staffArray[i]->m_Id == id) {
			cout << ">>> �ҵ�ְ����";
			this->staffArray[i]->showInfo();
			return i;
		}
	}
	return -1;
}

// ���� ������������ְ��
// ����������ӡְ����Ϣ���������򷵻�-1
// ְ������ ���ظ�
int StaffManager::findStaff(string name) {
	int ret = 0;
	for (int i = 0; i < this->staffNum; i++) {
		if (this->staffArray[i]->m_Name == name) {
			cout << ">>> �ҵ�ְ����";
			this->staffArray[i]->showInfo();
			ret++;
		}
	}
	return ret;
}

// ����ְ�������ձ�Ż�����
void StaffManager::findStaff() {
	if (this->staffNum == 0) {
		cout << ">>> ְ���б�Ϊ�գ��޷����ң�" << endl;
		return;
	}

	int findFlag;
	cout << ">>> ��������ҷ�ʽ��" << endl;
	cout << " 0:ͨ����Ų���" << endl;
	cout << " 1:ͨ����������" << endl;
	cin >> findFlag;

	int id;
	string name;
	int index;
	switch (findFlag)
	{
	case 0:
		cout << ">>> �����������ְ����ţ�" << endl;
		cin >> id;
		index = this->findStaff(id);
		break;
	case 1:
		cout << ">>> �����������ְ��������" << endl;
		cin >> name;
		index = this->findStaff(name);
		break;
	default:
		cout << ">>> �밴Ҫ������ָ�" << endl;
		return;
	}

	if (index <0) {
		cout << ">>> ��ְ�������ڣ�" << endl;
	}

	system("pause");

}

// �޸�ǰ ��Ҫ���жϸ�ְ���Ƿ����
void StaffManager::modifyStaff() {
	if (this->staffNum == 0) {
		cout << ">>> ְ���б�Ϊ�գ��޷��޸�ְ����Ϣ��" << endl;
		return;
	}

	int id;
	cout << ">>> ��������޸���Ϣְ���ı�ţ�" << endl;
	cin >> id;

	int index = this->findStaff(id);
	if (index < 0) {
		cout << ">>> ��ְ�������ڣ�" << endl;
		return;
	}

	this->staffArray[index]->showInfo();

	string name;
	int job;
	cout << "�������µı�ţ�" << endl;
	cin >> id;
	
	while (this->findStaff(id) >= 0 ) {
		if (id == this->staffArray[index]->m_Id) break;
		cout << ">>> ��ְ������ѱ�ռ�ã��������µı�ţ�" << endl;
		cin >> id;
	}

	cout << "�������µ�������" << endl;
	cin >> name;
	cout << "�������µ�ְλ��" << endl;
	cout << " 1����ְͨ��" << endl;
	cout << " 2������" << endl;
	cout << " 3���ϰ�" << endl;
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
	
	cout << ">>> �޸ĳɹ������º����ϢΪ��" << endl;
	this->staffArray[index]->showInfo();
}

// ɾ��ǰ ��Ҫ���жϸ�ְ���Ƿ����
void StaffManager::deleteStaff() {
	if (this->staffNum == 0) {
		cout << ">>> ְ���б�Ϊ�գ�����ɾ����" << endl;
		return;
	}

	int id;
	cout << ">>> �������ɾ��ְ���ı�ţ�" << endl;
	cin >> id;
	
	// find index
	int index = findStaff(id);

	if (index < 0) {
		cout << ">>> ��ְ�������ڣ�" << endl;
		return;
	}

	// delete staff
	this->staffNum--;
	for (int i = index; i < this->staffNum; i++) {
		this->staffArray[i] = this->staffArray[i + 1];
	}
	
	cout << ">>> �ѳɹ�ɾ����" << endl;

}

// ����ְ���б��ļ� staff_list.txt
void StaffManager::saveFile() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	// ��дְ������
	ofs << this->staffNum << endl;

	for (int i = 0; i <this->staffNum; i++) {
		ofs << this->staffArray[i]->m_Id << " "
			<< this->staffArray[i]->m_Name << " "
			<< this->staffArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

// ��ӡ����ְ����Ϣ
void StaffManager::showStaff() {
	if (this->staffNum == 0) {
		cout << ">>> Ŀǰû��ְ����" << endl;
		return;
	}
	for (int i = 0; i < this->staffNum; i++) {
		this->staffArray[i]->showInfo();
	}
}

// �������ְ��
void StaffManager::addStaff() {
	int addNum;
	cout << "������Ҫ��ӵ�ְ��������" << endl;
	cin >> addNum;

	if (addNum > 0) {

		int newSize = this->staffNum + addNum;
		Staff** newArray = new Staff * [newSize];

		// ��ԭ����ְ��ָ���б������µĴ洢�ռ� 
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
			cout << "�����������ְ���ı�ţ�" << endl;
			cin >> id;

			while (this->findStaff(id) >= 0) {
				cout << ">>> ��ְ������ѱ�ռ�ã��������µı�ţ�" << endl;
				cin >> id;
			}

			cout << "�����������ְ����������" << endl;
			cin >> name;
			cout << "�����������ְ����ְλ��" << endl;
			cout << " 1����ְͨ��" << endl;
			cout << " 2������" << endl;
			cout << " 3���ϰ�" << endl;
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

		// �ͷ�ԭ����ְ��ָ���б�
		delete[] this->staffArray;

		// ����ְ���б�
		this->staffArray = newArray;
		this->staffNum = newSize;
		this->fileEmpty = false;

		cout << "�ɹ����" << addNum << "����ְ����" << endl;
	}

	else {
		cout << "Wrong Input!" << endl;
	}

	system("pause");
	system("cls");

}

// �˳�ְ��ϵͳ
void StaffManager::exitSystem() {
	cout << "Good Bye!" << endl;
	system("pause");
	exit(0);		// �˳��������еĳ���
}

// ��ӡ�˵�
void StaffManager::showMenu() {
	cout << "=========================================" << endl;
	cout << "***********  Welcome to SMS!  ***********" << endl;
	cout << "***********  0: �˳�����ϵͳ  ***********" << endl;
	cout << "***********  1: ���ְ����Ϣ  ***********" << endl;
	cout << "***********  2: ��ʾְ����Ϣ  *********** " << endl;
	cout << "***********  3: ɾ����ְְ��  *********** " << endl;
	cout << "***********  4: �޸�ְ����Ϣ  *********** " << endl;
	cout << "***********  5: ����ְ����Ϣ  *********** " << endl;
	cout << "***********  6: ���ձ������  *********** " << endl;
	cout << "***********  7: ���������Ϣ  *********** " << endl;
	cout << "=========================================" << endl;
}


StaffManager::StaffManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// �״ν���ϵͳ���ļ�������
	if (!ifs.is_open()) {
		cout << ">>> The staff file doesn't exist." << endl;
		this->staffNum = 0;
		this->staffArray = NULL;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	// �ļ��Ѿ����ڣ��������
	int num;
	ifs >> num;
	if (num == 0) {	// �ж��ļ��Ƿ�Ϊ��
		cout << ">>> The staff file is empty." << endl;
		this->staffNum = 0;
		this->staffArray = NULL;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	// �ļ���Ϊ��
	this->staffNum = num;
	this->staffArray = new Staff * [num];	// ��������ڶ�����ָ������
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
	cout << ">>> ��ʼ��Ա���б�ɹ����Ѽ���" << this->staffNum << "��ְ����Ϣ��" << endl;
}


StaffManager::~StaffManager() {
	if (this->staffArray != NULL) {
		// ɾ��������ÿ��ְ������
		for (int i = 0; i < this->staffNum; i++) {
			delete this->staffArray[i];
			this->staffArray[i] = NULL;
		}
		// ɾ��������ָ������
		delete[] this->staffArray;
		// ����Ұָ��
		this->staffArray = NULL;
	}
	this->staffNum = 0;
}