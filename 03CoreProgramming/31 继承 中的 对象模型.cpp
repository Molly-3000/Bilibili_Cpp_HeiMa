#include<iostream>
using namespace std;

/*
* �̳� �е� ����ģ��
* 
* ���������� �Ǿ�̬��Ա���ԣ���������̳���
* 
* ����Ȼ����˽�г�Ա�������޷����ʣ���ȷʵ���̳��ˣ�ֻ�Ǳ������������ˡ�
*/

class Base31 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son31_1 :public Base31 {
public:
	int m_D;
};

static void test01() {
	// ���������зǾ�̬��Ա���ԣ����ᱻ����̳���ȥ
	// �����е�˽�г�Ա���ԣ��������������ˣ����ܷ��ʣ������̳���
	cout << "size of Son1 is " << sizeof(Son31_1) << endl;	// 4 x 4 = 16

	// ��������cmd�鿴����ģ��
	// ��ת����ǰ�ļ�·��
	// �鿴���cl -d1 reportSingleClassLayout���� �ļ���
	//			 cl -d1 reportSingleClassLayoutSon31_1 "31 ..."
}

int main31() {

	test01();

	system("pause");
	return 0;
}