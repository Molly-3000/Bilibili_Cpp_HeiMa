#include"head.h"
#include<fstream>

/*
* �ļ�����
* 
* C++�ļ��� <fstream>
* 
* �ļ����ͣ�
*		�ı��ļ���	���ı���ASCII����ʽ�洢 
*		�������ļ����Ա��ĵĶ�������ʽ�洢
* 
* �����ļ��������ࣺ
*		ifstream		������		��
*		ofstream		�����		д
*		fstream		���������		��д
* 
* �ı��ļ� �������裺
*		1������ͷ�ļ�		#include<fstream>
*		2�����������		ofsteam ofs;
*		3�����ļ�			ofs.open("�ļ���",�򿪷�ʽ);		// out, app, ate, trunc
*		4��д����			ofs<<"д����";
*		5���ر��ļ�			ofs.close();
* 
* �ļ� �򿪷�ʽ��
*		ios::in			ֻ��
*		ios::out		ֻд
*		ios::ate		��ʼλ��Ϊ�ļ�β	������׷��
*		ios::app		��׷�ӷ�ʽд�ļ�
*		ios::trunc		����ļ��Ѿ����ڣ���ɾ�����ٴ���
*		ios::binary		�Զ����Ʒ�ʽ���в���
* 
*		***���Ҫ���ִ򿪷�ʽ���ʹ�ã���|����������
*				ios::in | ios::out | ios::binary
*/


static void test01() {

	// д
	ofstream ofs;					
	ofs.open("test.txt", ios::out);
	ofs << "test output..."<<endl;		// ofs һ�δ���һ��
	ofs << "line 2" << endl;			// endl == "\n"+"std::flush"
	ofs << "line 3" << endl;			// endl������flush������ˢ�»�������ʹ��ջ�еĶ���ˢ��һ�Σ����� "\n" ����ˢ�£���ֻ�ỻ�У�ջ������û�б仯��
	ofs.close();

}

int main44() {
	test01();

	system("pause");
	return 0;
}