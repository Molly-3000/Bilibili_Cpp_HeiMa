#include<iostream>
using namespace std;


// function ��һ�δ����װ���������ٴ����ظ�
// 1�������Ķ��壺
// 
// ����ֵ���� ������ (�����б�) {
//		������;
//		return ���ʽ;
//}
// �������ĳ������ͣ��޲��޷����в��޷����޲��з����в��з���
// 
// 
// 2�������ĵ��ã�
// 
// ������(�����б�);
//

// ��������ʱ������Ϊ�β�
int sum(int num1,int num2) {
	//int result = a + b;
	//return result;
	return num1 + num2;
}

int main38() {

	int a = 111;
	int b = 222;

	// ��������ʱ������Ϊʵ��
	// 
	// ** ʵ�ε�ֵ�ᴫ�ݸ��β�
	cout << sum(a, b) << endl;
	cout << sum(111, 222) << endl;

	system("pause");
	return 0;
}