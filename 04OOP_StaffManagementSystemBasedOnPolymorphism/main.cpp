#pragma onece
#include"head.h"
#include"boss.h"
/*
* ְ������ϵͳ
* 
* �����ְͨ���������ϰ�
* ��Ϣ����š���������λ��ְ��
* 
* ְ����ְͨ������ɾ�����������
*		��������ϰ彻�������񣬲��·��������ְͨ��
*		�ϰ壬����˾��������
* 
* ϵͳ���ܣ�
*		0���˳�
*		1�����ְ����Ϣ		���������
*		2����ʾְ����Ϣ		����
*		3��ɾ����ְְ��		ͨ�����
*		4���޸�ְ����Ϣ		ͨ�����
*		5������ְ����Ϣ		ͨ����Ż�����
*		6�����������		�û�ָ�� �������
*		7����������ĵ�		����ļ�������ְ����Ϣ�����ǰ��Ҫ�ٴ�ȷ��
*/


int main() {

	StaffManager sm;
	int choice = 0;

	while (true) {
		sm.showMenu();

		cout << ">>> ������ָ�" << endl;
		cin >> choice;

		switch (choice) {
		case 0:		//�˳�
			sm.exitSystem();
			break;
		case 1:		//����
			sm.addStaff();
			break;
		case 2:		//��ʾ
			sm.showStaff();
			break;
		case 3:		//ɾ��
			sm.deleteStaff();
			break;
		case 4:		//�޸�
			sm.modifyStaff();
			break;
		case 5:		//����
			sm.findStaff();
			break;
		case 6:		//����
			sm.sortById();
			break;
		case 7:		//���
			sm.clearFile();
			break;
		}
		system("pause");
		system("cls");
		sm.saveFile();
	}
	return 0;
}