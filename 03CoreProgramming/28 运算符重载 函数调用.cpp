#include"head.h"

/*
* ������������� ����
* 
* ()
* 
* ��Ϊ���غ��ʹ�÷�ʽ���ǳ������ĵ��ã����Ҳ��Ϊ �º���
* 
* �º���û�й̶���д�����ǳ����
* 
* !!! ע�⣺����������Ǿ�̬��Ա�����������ز�����static����
*				   ~~~~~~~~~~~~~~~~~
*			����Ϊ��Ҫ���ʳ�Ա������Ĭ�ϴ���thisָ�롣��+��-�ȣ�
* 
*/

class MyPrint {
public:
	// ���غ������� �����
	void operator() (string s) {
		cout << s << endl;
	}
	// �º����ǳ��������������͡������б�û�й̶�д��
	int operator() (int a, int b) {
		return a + b;
	}

	//// ����!��������������Ǿ�̬��Ա����
	//static int operator() (int a) {}

};


static void test01() {
	MyPrint myPrint;
	myPrint("test");	// ���غ������������ ��ʹ�ã���������ʽ��������
	cout << myPrint(1, 2) << endl;

	// ����ͨ�������������
	cout << MyPrint()(11, 22) << endl;
	//// ����ͨ�������
	//cout << MyPrint.operator("error") << endl;
}


int main28() {

	test01();

	system("pause");
	return 0;
}