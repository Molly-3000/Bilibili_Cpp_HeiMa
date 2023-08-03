#include"head.h"
#include<string>
/*
* ��ģ����̳�
* 
* 1��������̳еĸ�������ģ��ʱ������������ʱ����Ҫָ��������� T
*		�����ָ�����������޷�����������ڴ�
* 
* 2����������ָ�������� T �����ͣ�����Ҳ��Ҫ�����ģ��
*/

template<class T>
class Base12 {
public:
	Base12() {
		cout << "This is Base12." << endl;
		cout << "The type of T in Base12 is :" << endl;
		cout << typeid(T).name() << endl;
	}
	T m;
};

// 1�����಻����ģ�壬����Ҫָ�������T
class Son12_ :public Base12<int> {
public:
	Son12_() {
		cout << "This is Son2_, not a template." << endl;
	}
};

// 2������Ҳ����ģ�壬����Ҫָ�������T
template<class T,class T2>
class Son12 :public Base12<T> {	//T���ڸ���ģ��
public:
	Son12() {
		cout << "This is Son12, a template." << endl;
		cout << "Type of T in Son12 is :" << endl;
		cout << typeid(T2).name() << endl;
	}
	T2 t;	// T2 ��������ģ��
};

static void test() {
	Son12_ son1;
	Son12<int,string> son2;
}

int main12() {
	test();
	return 0;
}
