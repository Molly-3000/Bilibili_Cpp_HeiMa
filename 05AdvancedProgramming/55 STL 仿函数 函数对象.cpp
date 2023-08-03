#include"head.h"
/*
* STL ��������
* 
* 1�����������������
* 
*		������� �������ò�����() ���࣬����� ��Ϊ��������
*			  ~~~~ ~~~~~~~~~~~~~~~~
*			  ��������ʹ�����ص�() ʱ����Ϊ���ƺ������ã��ʳ�Ϊ�º���
*											~~~~~~~~~~~			~~~~~
*		���ʣ��������󣨷º�������һ����Ķ��󣬲���һ������
*										  ~~~~
* 2����������ʹ��
* 
*		�ص㣺����������ʹ��ʱ����������ͨ�����������ã������в������з���ֵ
*			  �������󳬳���ͨ�����ĸ����������������Լ���״̬����Ա���ԣ�
*			  �������������Ϊ��������						  ~~~~
*						~~~~~~~~~~~~~~
*/

// �������󣬿����в���������ֵ
class MyAdd {
public:
	int operator() (int v1, int v2) {
		return v1 + v2;
	}
};

static void test1() {

	cout << "1+2 = " << MyAdd()(1, 2) << endl;	// ��������

	int v1 = 1;
	int v2 = 2;
	MyAdd myAdd;
	cout << "1+2 = " << myAdd(1, 2) << endl;

}

// �������󣬿������Լ���״̬
class MyMinus {
public:
	MyMinus(int v1, int v2):m_v1(v1),m_v2(v2),count(0) {}
	int operator() () {
		count++;
		return this->m_v1 - this->m_v2;

	}
	int operator() (int v1, int v2) {
		count++;
		return v1 - v2;
	}
	int m_v1;
	int m_v2;
	int count;
};

static void test2() {
	cout << "11-1 = " << MyMinus(11, 1)() << endl;

	MyMinus mySub(11, 1);
	cout << "11-1 = " << mySub() << endl;
	cout << "count: " << mySub.count << endl;

	MyMinus mySub2(11, 1);
	cout << "11-1-1-1 = " << mySub2(mySub2(mySub2(), 1),1) << endl;
	cout << "count: " << mySub2.count << endl;

}

// �������󣬿�����Ϊ�������д���
class MyPrint55 {
public:
	void operator() (string s) {
		cout << s << endl;
		count++;
	}
	int count = 0;
};
static void doPrint(MyPrint55& printer, string s) {
	printer(s);
}

static void test3() {
	MyPrint55 printer;
	doPrint(printer, "hello");
	doPrint(printer, "hello");
	doPrint(printer, "hello");
	doPrint(printer, "hello");
	cout << "count: " << printer.count << endl;
}

int main55() {

	test1();
	test2();
	test3();
	return 0;
}