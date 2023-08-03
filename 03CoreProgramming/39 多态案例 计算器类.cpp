#include "head.h"

class Calculater39 {
public:
	
	int getResult(string opr) {
		if (opr == "+")	return num1 + num2;
		else if (opr == "-") return num1 - num2;
		else if (opr == "*") return num1 * num2;
		// ��Ҫ�¹��� ����Ҫ �޸�Դ��
		// �����㿪��ԭ�򣺶���չ���п��������޸Ľ��йر�
	}
	int num1, num2;
};

static void test01() {
	Calculater39 c;
	c.num1 = 10;
	c.num2 = 10;
	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;
}

// ���ö�̬���п���
// �ô���
//		1����֯�ṹ����		�������
//		2���ɶ���ǿ			�����ھ�
//		3������ǰ�ںͺ��ڵ���չ��ά��
// 
// ���ࡪ��������
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int num1, num2;
};
// �ӷ�������
class AddCalculator :public AbstractCalculator {
public:
	int getResult() {
		return num1 + num2;
	}
};
// ����������
class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return num1 - num2;
	}
};
// �˷�������
class MulCalculator :public AbstractCalculator {
public:
	int getResult() {
		return num1 * num2;
	}
};


static void test02() {

	// ��̬ʹ�÷�ʽ
	// ����ָ�� �� ���� ָ���������

	AbstractCalculator* cal;
	AddCalculator add;
	AbstractCalculator & cal2 = add;

	cal = new AddCalculator();
	cal->num1 = 10;
	cal->num2 = 10;
	cout << cal->num1 << " + " << cal->num2 << " = " << cal->getResult() << endl;
	delete cal;

	cal = new SubCalculator();
	cal->num1 = 10;
	cal->num2 = 10;
	cout << cal->num1 << " - " << cal->num2 << " = " << cal->getResult() << endl;
	delete cal;

	cal = new MulCalculator();
	cal->num1 = 10;
	cal->num2 = 10;
	cout << cal->num1 << " * " << cal->num2 << " = " << cal->getResult() << endl;
	delete cal;
}

int main39() {

	test01();

	test02();

	system("pause");
	return 0;
}