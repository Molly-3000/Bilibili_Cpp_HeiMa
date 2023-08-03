#include"head.h"
/*
* ����ģ��
* 
* ע�����
*		1���Զ������Ƶ�ʱ���������Ƶ���һ�µ���������T
*		2��ģ�����Ҫȷ����T���������ͣ�����ʹ��
*/

template<class T>	// typename�����滻Ϊclass
void swapT2(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// 1���Ƶ�����T�������ͱ���һ��
static void test01() {
	int a = 10;
	int b = 20;
	float bf = 20.f;

	swapT2(a, b);
	//swapT2(a, bf);	// error,û��������б�int,float��ƥ��ĺ���ģ��T2
}

// 2������ȷ��T����������
template<class T>
void func() {
	cout << "template func()" << endl;
}

static void test02() {
	//func(); // error,û��������б�ƥ��ĺ���ģ��T2
			  // ��û���Զ��Ƶ���T������
	func<int>();	// ����ָ��T������	
	func<float>();
	func<string>();
}

int main03() {
	test01();
	test02();
	return 0;
}