#include"head.h"

//
// ����Ȩ��
// 3��
// ���� public      ���ڿɷ���	����ɷ���	
// ���� protected	���ڿ�		���ⲻ��		�����
// ˽�� private		���ڿ�		���ⲻ��		���಻��
// 
// private�ĺô���
//		1����Ա����˽�л��������Լ����ƶ�дȨ��
//		2������дȨ�ޣ����Լ�����ݵ���Ч��
//



class Person {
public:
	string m_Name;
protected:
	string m_Car;
private:
	int m_Password;

	string name;	// �ɶ���д
	int age = 0;	// ֻ��
	string lover = "someone";	// ֻд

public:
	void func() {
		m_Name = "zhangsan";	// public		���ڿ�
		m_Car = "qq";			// protected	���ڿ�
		m_Password = 111;		// private		���ڿ�
	}
	
	// ��˽�����Խ��ж�д���� �� �ӿ�
	void setName(string newName) { name = newName; }	// д �ӿ�
	string getName() { return name; }					// �� �ӿ�

	// ��д������������ݵ���Ч��
	//  0 <= age <= 150 
	void setAge(int newAge) { 
		if (newAge < 0 || newAge>150) {
			cout << "Non-valid age!" << endl;
			return;
		}
		age = newAge; 
	}			// д

	string getLover() { return lover; }					// ��
};

// struct �� class
// Ψһ��������ǳ�Ա Ĭ�ϵķ���Ȩ�޲�ͬ
// struct Ĭ�� public
// class  Ĭ�� private

class C1 {
	int m;
}c1;
struct C2 {
	int m;
}c2;

int main08() {

	Person p1;
	p1.m_Name = "zhangsan";		// public		�����
	//p1.m_Car = "benci";       // protected	���ⲻ��
	//p1.m_Password = "benci";	// private		���ⲻ��

	p1.setAge(-1);
	p1.setAge(18);

	//c1.m;		// class  ��Ա Ĭ�� private�� ���ⲻ��
	c2.m;		// struct ��Ա Ĭ�� public��  �����

	system("pause");
	return 0;
}