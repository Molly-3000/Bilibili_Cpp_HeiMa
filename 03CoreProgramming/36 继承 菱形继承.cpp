//#include"head.h"

/*
* ���μ̳�
* 
* ���⣺
*		1��������/����ȷ				ͨ�� ������ ���
*		2���������ݣ��˷���Դ			ͨ�� ��̳� ���
* ע�⣺
*		������ʹ�ö�̳�
*/

// ������
class Animal36 {
public:
	int m_Age;
	int m_Height;
	int m_Weight;
};

// ��̳У��ڼ̳з�ʽǰ�� virtual �ؼ���
//			��ʱ�������Ϊ ����� virtual base class
class Wolf : virtual public Animal36 {};

class Dog : virtual public Animal36 {};

class Husky : public Wolf, public Dog {};

static void test01() {
	Husky hs;

	//hs.m_Age = 1;	// error, ����ȷ
	hs.Wolf::m_Age = 1;
	hs.Dog::m_Age = 2;
	//cout << "Wolf m_Age = " << hs.Wolf::m_Age << endl;
	//cout << "Dog m_Age = " << hs.Dog::m_Age << endl;

	// cl /d1 reportSingleClassLayoutHusky "36..."
	// ���� m_Age ���ݣ���Դ�˷�

	// ͨ����̳У����ټ̳����ݣ�����ָ��
	// ֻ��һ������
	// 
	//cout << "Wolf m_Age = " << hs.Wolf::m_Age << endl;
	//cout << "Dog m_Age = " << hs.Dog::m_Age << endl;


}

int main36() {

	test01();

	//system("pause");
	return 0;
}