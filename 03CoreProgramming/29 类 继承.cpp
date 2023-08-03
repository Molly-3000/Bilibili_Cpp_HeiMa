#include"head.h"

/*
* �̳У�extend��
* 
* ���ã���ߴ��븴���ʣ������ظ�
* 
* �﷨��class ���� : �̳з�ʽ ����
*		e.g. class A : public B
* 
* �̳з�ʽ��public  |  protected  |  private
* 
* ˵����1������Ҳ�������࣬����Ҳ�л���
*		2�������еĳ�Ա�������󲿷�
*			���Ӹ����м̳еõ���		�������Ĺ���
*			���Լ����ӵĳ�Ա			��������ĸ���
* 
*/

class webPage {

public:
	void showHeader() { cout << "��ҳ�������Ρ���¼��ע��" << endl; }
	void showFooter() { cout << "Thank you for watching. " << endl; }
	void showLeft() { cout << "Java;Python;C++ ..." << endl; }
	void showRight(){}
};

// extend
class javaPage :public webPage {
public:
	void showRight() { cout << "Java Course01 Course02..." << endl; }
};

class pythonPage :public webPage {
public:
	void showRight(){ cout << "Python Course01 Course02..." << endl; }
};

class cppPage :public webPage {
public:
	void showRight(){ cout << "C++ Course01 Course02..." << endl; }
};

static void test01() {
	webPage base;
	pythonPage python;
	base.showHeader();
	base.showLeft();
	python.showRight();
	python.showFooter();

}

int main29() {
	test01();

	system("pause");
	return 0;
}