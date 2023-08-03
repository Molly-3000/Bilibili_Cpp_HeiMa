#include"head.h"

/*
* �������� �� ����ʱ��
*		���������
*				��ʹ�� һ���Ѿ�������ϵĶ��� �� ��ʼ��һ���¶���
*				���� ֵ���� �ķ�ʽ������ ������ֵ
*				���� ֵ���� �ķ�ʽ ���ؾֲ�����
* 
*/

class Person12 {
	int age;
public:
	Person12(){
		cout << " This is default constructor. " << endl;
	}
	Person12(int a) {
		age = a; 
		cout << " This is a parameter constructor." << endl;
	}
	Person12(const Person12& p) {
		age = p.age; 
		cout << " This is a copy constructor." << endl;
	}

	~Person12() {
		cout << " This is deconstructor." << endl;
	}
};

// ͨ�� static �ú������� ��ǰcpp ��ʹ��
// 1���� һ���Ѿ�������ϵĶ��� ����ʼ�� һ���¶���
static void test01() {
	Person12 p1(10);
	Person12 p2(p1);
	Person12 p3 = Person12(p2);
	Person12 p4 = p3;
}

// 2���� ֵ���� �ķ�ʽ�� ��������
//		 ֵ���ݵı����� ����һ����ʱ�ĸ����������������˵�����ǿ�������
void doCopyForFunc(Person12 p){}
static void test02() {
	Person12 p;
	doCopyForFunc(p);
}

// 3���� ֵ���� ���� �ֲ�����
//		 ֵ���صı����� Ҳ�Ǵ���һ����ʱ�ĸ����������������˵�����ǿ�������
Person12 doCopyForReturn() {
	Person12 p;	// �ֲ����󣬲����᷵��
	cout << (int*)&p << endl;
	return p;
}
static void test03() {
	//doCopyForReturn();
	//Person12 p = doCopyForReturn();
	//cout << (int*)&p << endl;
	Person12 p2(doCopyForReturn());
}

int main12() {

	//test01();
	//test02();
	test03();

	system("pause");
	return 0;
}