#include"head.h"

// ����� ��ʼ�� �� ����
// 
// ��ʼ��->���캯��
//		����������ʱ���������Զ����ã���ֻ����һ��
// �﷨������(){}
//		1����д����ֵ���ͣ�дreturn
//		2����������������ͬ
//		3������д��������������
// 
// ����->��������
//		�ڶ�������ǰ���������Զ����ã���ֻ����һ��   // ��Ҳ�Ƕ�������� delete[]��ԭ��ÿ������Ҫ����һ��
// �﷨��~����(){}
//		1����д����ֵ����дreturn
//		2����������������ͬ��ǰ���~����
//		3������д��������������
// 
// constructor �� destructor ���Ǳ���ʵ�ֵ�
//		�������Աû��ʵ�֣����ɱ������ṩһ����ʵ�ֵĺ���
//


class Test1 {
public:
	Test1() { cout << "This is stack object constructor." << endl; }
	~Test1() { cout << "This is stack object dectructor." << endl; }
};

class Test2 {
public:
	Test2() { cout << "This is heap object constructor." << endl; }
	~Test2() { cout << "This is heap object dectructor." << endl; }
};

void heapTest() {
	Test2 heapT;  // ջ�����ں�����Ҳ���Ǹþֲ��������������˳�ǰ������ͻᱻ����
}

int main10() {

	Test1 stackT;

	heapTest();

	system("pause");
	return 0;
}