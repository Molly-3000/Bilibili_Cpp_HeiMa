#include"head.h"

/*
* ���ظ�ֵ�����
* 
* =
* 
* �������ṩ����ǳ����������ʱ���ܵ����ظ��ͷ�
* 
* ע�⣺���ж��Ƿ������ݣ������ͷţ�Ȼ�������
* 
*/

class Person26 {
public:
	Person26(int age) :m_Age(new int(age)) {}

	~Person26() { 
		if (this != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}

	Person26& operator= (Person26 &p) {

		// �������ṩ�� = ��ǳ����
		// m_Age = p.m_Age
		// ��������ʱ�� ���ܻᵼ�¶����ظ��ͷ�

		// ���ж��Ƿ��������ڶ����������ͷ�
		if (m_Age != NULL) {
			delete m_Age;			// ���ͷ�
		}
		m_Age = new int(*p.m_Age);  // �ٷ���
		return *this;
	}

	int* m_Age;
};

static void test01() {
	Person26 p1(18);
	Person26 p2 = 20;
	Person26 p3 = 30;
	p3 = p2 = p1;	// ����˳�� ��������
	cout << " the age of person1 is " << *p1.m_Age << endl;
	cout << " the age of person2 is " << *p2.m_Age << endl;
	cout << " the age of person3 is " << *p3.m_Age << endl;
}

int main26() {

	test01();

	system("pause");
	return 0;
}