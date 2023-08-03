#include"head.h"

/*
* 递增/递减 运算符重载
* 
* ++，--
* 
* 注意前置/后置
*		后置需要用占位参数，作为区分，且必须用int
* 
*/

class myInteger {

public:
	myInteger(int num) :num(num) {}

	// 前置
	myInteger& operator++() {
		num++;
		return *this;
	}
	myInteger& operator--() {
		num--;
		return *this;
	}

	//// 上面的函数 在输出结果上等价于，但开销不同
	//myInteger operator--() {
	//	num--;
	//	myInteger temp = *this;
	//	return temp;
	//}

	// 后置
	// 1、用占位参数区分前置和后置
	// 2、后置返回值，而不是引用
	myInteger operator++(int) {	// int代表占位参数
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