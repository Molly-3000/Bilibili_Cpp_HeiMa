#include"head.h"
#include<string>
/*
* ��ģ�� vs ��ͨ��
* 
* ��Ա���� ����ʱ�� ������
* 
*	����ͨ���У���Ա����һ��ʼ�Ϳ��Դ���
* 
*	����ģ���У���Ա�����ڵ���ʱ�Ŵ���
*						 ~~~~~~
*/

class Person10_a {
public:
	void show_a() {
		cout << "Normal class A function." << endl;
	}
};

class Person10_b {
public:
	void show_b() {
		cout << "Normal class B function." << endl;
	}
};

template<class T>
class Person10 {
public:
	T obj;
	void show1() {
		obj.show_a();	// show_a()��show_b()����ͬһ����ĺ���
	}
	void show2() {
		obj.show_b();	// ������ͨ������,��Ϊ��ģ���У���Ա�����ڵ���ʱ�Ŵ���
	}
};

static void test() {
	Person10<Person10_a> pa;
	pa.show1();			// ����ʱ����ģ���еĳ�Ա�����Ŵ���
	//pa.show2();		// err,show_b()����Person_a�ĳ�Ա
}

int main10() {
	test();
	return 0;
}
