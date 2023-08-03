#include<string>
#include<iostream>
using namespace std;
#include<fstream>

/*
* �ļ����� д���裺
*		1�������ļ�ͷ		#include<fstream>
*		2������������		ifstream ifs;
*		3�����ļ� �� �ж��ļ��Ƿ�ɹ���	ifs.open("�ļ���",�򿪷�ʽ);ifs.is_open();
*		4��������			in 
*		5���ر��ļ�			ifs.close();
*
*/


static void test01() {
	// 1 ����ͷ�ļ�

	// 2 ����������
	ifstream ifs;

	// 3 ���ļ� �� �ж��Ƿ�ɹ���
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "failed to open the file" << endl;
		return;
	}

	// 4 ������
	// 
	//// ��һ��
	//char buf[1024];
	//while (ifs >> buf) {	// ifs һ�δ���һ��, �����ո�endl��eofֹͣ������ ������
	//	cout << "a line: ";
	//	cout << buf << endl;
	//}
	// 
	//// �ڶ���
	//char buf[1024];
	//while (ifs.getline(buf, sizeof(buf))) {	// ifs һ�δ���һ��, ����endl��eofֹͣ������ ������
	//	cout << buf << endl;
	//}
	//
	//// ������ 
	//string buf;
	//while (std::getline(ifs, buf)) {
	//	cout << buf << endl;
	//}
	// 
	//// ������
	char c;
	while ((c = ifs.get()) != EOF) {	// EOF end of file ��ʶ
		cout << c;
	}


	// 5 �ر��ļ�
	ifs.close();
}

int main45() {
	test01();

	system("pause");
	return 0;
}