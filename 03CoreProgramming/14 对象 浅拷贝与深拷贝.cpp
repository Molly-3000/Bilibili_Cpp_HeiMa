#include"head.h"

/*
* ǳ���� vs ���
* 
* ǳ�������򵥵���ֵ�������������ṩ�Ŀ����������ǳ������
* 
* ������ڶ��������µ��ڴ�ռ䣬���п���������
* 
* ǳ���������⣺�������ڴ��ظ��ͷ�
* 
*/

class Person14 {
public:
	Person14(){
		cout << "This is default constructor." << endl;
	}

	Person14(int _age, int _height) {
		age = _age;
		height = new int(_height);
		cout << "This is parameter constructor." << endl;
	}

	// �������ṩ�Ŀ������캯��be like:
	// 
	//Person14(const Person14& p) {
	//	age = p.age;
	//	height = p.height;		// shadow copy
	//	cout << "This is shadow copy constructor." << endl;
	//}

	Person14(const Person14& p) {
		age = p.age;
		height = new int(*p.height);	// deep copy
		cout << "This is deep copy constructor." << endl;
	}

	~Person14() {
		// �����������������ͷŶ���ʱ���ͷŶ������ٵĿռ�
		if (height != NULL) {
			delete height;
			height = NULL;		// �ÿգ��Ա���Ұָ��
		}
		cout << "This is deconstructor." << endl;
	}
	int age;
	int* height;
};

static void test01() {
	Person14 p1(18,165);
	cout << "The height of person1 is " << *p1.height << endl;
	Person14 p2 = p1;
	cout << "The height of person2 is " << *p2.height << endl;

	// p1 p2 ����ջ������ָ�룩,�Ƚ����
	// �� test01()�˳�ʱ�����ͷ�p2�����ͷ�p1
	// p1 ִ��deconstructor �ͷ�ָ��
	// if shadow copy��
	//		p2 ִ��deconstructor�ͷ�ָ�룬�ظ��ͷţ����Ա���
	// else deep copy:
	//		p2 ִ��deconstructor�ͷ�ָ�룬�ͷ���p1��ͬ���ڴ�
	//
}

int main14() {

	test01();

	system("pause");
	return 0;
}