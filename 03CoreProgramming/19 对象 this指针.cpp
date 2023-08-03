#include"head.h"
 
/*
* ========= thisָ�� =========
* thisָ�룺c++�ṩ������� ����ָ�룬����Ҫ���壬����ֱ��ʹ��
* 
* thisָ��ָ�򣺵��øó�Ա���� �Ķ���
* 
* thisָ���������� ÿһ���Ǿ�̬��Ա���� �� ���� �ڵ�һ��ָ��
*						 ~~~~~~~~~~~~~~
* ��;��
*	   �����βκͳ�Ա����ͬ��ʱ��������thisָ������		��������Ƴ�ͻ
*	   ������ķǾ�̬��Ա������ ���ض�������ʹ�� retrun *this
*/

class Person19 {
public:

	// thisָ������1��������Ƴ�ͻ
	Person19(int age){
		this->age = age;
	}
	// �����ͻ����һ�ְ취����ʼ���б�
	//Person19(int age) :age(age) {}

	// thisָ�������2�����ض�����
	// ������ע�ⷵ�ر��壬��Ҫ�����õķ�ʽ����
	Person19& PersonAgeAdd(Person19& p) {
		this->age += p.age;
		return *this;
	}

	int age;
};

static void test01() {
	Person19 p(18);
	cout << " The age of p is " << p.age << endl;
}

static void test02() {

	Person19 p1(10);

	Person19 p2 = 10;

	// ���ض�����������ʽ��̣���׷��
	p2.PersonAgeAdd(p1).PersonAgeAdd(p1).PersonAgeAdd(p1);

	cout << "The new age of p2 =  " << p2.age << endl;

	//// ����������� ��Ҫ���µĶ�����գ��������p2.age=20
	//Person19 p = p2.PersonAgeAdd(p1).PersonAgeAdd(p1).PersonAgeAdd(p1);
	//cout << "The new age of p2 =  " << p.age << endl;

}

int main19() {

	test01();
	system("cls");

	test02();

	system("pause");
	return 0;
}