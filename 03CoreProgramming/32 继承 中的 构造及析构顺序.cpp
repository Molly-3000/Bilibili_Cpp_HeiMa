#include"head.h"

/*
* �̳� �е� ���켰����˳��
* 
* ����̳и���󣬵������������ʱ��Ҳ����ø���Ĺ��캯��
* 
* ��������ʱ���ȸ��๹�죬�����๹��
* ���ٶ���ʱ������˳���빹��˳���෴
* 
*/

class Base32 {
public:
	Base32() { cout << " This is the constructor form Base class." << endl; }
	~Base32() { cout << " This is the deconstructor form Base class." << endl; }
};

class Son32:public Base32 {
public:
	Son32() { cout << " This is the constructor form Son class." << endl; }
	~Son32() { cout << " This is the deconstructor form Son class." << endl; }
};

static void test01() {
	Son32 son;
}

int main32() {

	test01();
		
	system("pause");
	return 0;
}