#include"head.h"

/*
* �����Ա��һ����Ķ�����Ϊ��һ����ĳ�Ա
*		������������ʱ������һ�������Ա����Ϊָ�룩
* 
*/

class A16{

public:
	A16() {
		cout << "This is A constructor" << endl;
	}
	~A16() {
		cout << "This is A deconstructor" << endl;
	}

};

class B16 {

	A16 a;	// �����Ա

	// ʵ����ʱ�����ȴ���A���󴴽�B
	// �ͷ�ʱ�������ͷ�B�����ͷ�A

public:
	B16() {
		cout << "This is B constructor" << endl;
	}
	~B16() {
		cout << "This is B deconstructor" << endl;
	}
	 
};

class C16 {

};

static void test01() {
	B16 b;
}

int main16() {

	test01();

	system("pause");
	return 0;
}