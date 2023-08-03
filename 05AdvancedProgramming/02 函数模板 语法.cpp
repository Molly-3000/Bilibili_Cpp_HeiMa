#include"head.h"
/*
* ����template
* 
* ���壺����һ��ͨ�ú�����ʹ�䷵��ֵ���ͺͲ������Ͳ��̶�
*							  ~~~~~~~~~~  ~~~~~~~~
*							��һ���������������ʾ
* �﷨��template<typename T>
*		T funcname(T param1,...){}
* 
* ʹ�ã����֣���1���Զ������Ƶ�
*				2����ʽָ������
* 
*/

// ����ģ�� ����
template<typename T>	// ����һ��ģ�壬���߱�������������Ĵ�����T��Ҫ��������һ��ͨ�õ���������
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// ����ģ�� ʹ��
static void test() {
	int a = 10;
	int b = 20;

	// 1���Զ������Ƶ�
	mySwap(a, b);

	// 2����ʾָ������
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

// ������������
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// ��������������
void swapFloat(float& a, float& b) {
	float temp = a;
	a = b;
	b = temp;
}

static void test01() {
	int a = 10;
	int b = 20;

	swapInt(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	float af = 10.0f;
	float bf = 20.0f;

	swapFloat(af, bf);
	cout << "af = " << af << endl;
	cout << "bf = " << bf << endl;
}

int main02() {
	test();
	return 0;
}