#include"head.h"

/*
* ����/�ݼ� ���������
* 
* ++��--
* 
* ע��ǰ��/����
*		������Ҫ��ռλ��������Ϊ���֣��ұ�����int
* 
*/

class myInteger {

public:
	myInteger(int num) :num(num) {}

	// ǰ��
	myInteger& operator++() {
		num++;
		return *this;
	}
	myInteger& operator--() {
		num--;
		return *this;
	}

	//// ����ĺ��� ���������ϵȼ��ڣ���������ͬ
	//myInteger operator--() {
	//	num--;
	//	myInteger temp = *this;
	//	return temp;
	//}

	// ����
	// 1����ռλ��������ǰ�úͺ���
	// 2�����÷���ֵ������������
	myInteger operator++(int) {	// int����ռλ����
		myInteger temp = *this;
		num++;
		return temp;
	}

	myInteger operator--(int) {
		myInteger temp = *this;
		num--;
		return temp;
	}

	int getNum() { return num; }

private:
	int num;
};

ostream& operator<< (ostream& cout, myInteger n) {
	cout << n.getNum()<<endl;
	return cout;
}

static void test01() {
	myInteger myint = 10;
	cout << ++myint;
	cout << --myint;
	cout << myint++;
	cout << myint--;

}

int main25() {

	test01();

	system("pause");
	return 0;
}