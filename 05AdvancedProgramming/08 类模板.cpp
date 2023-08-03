#include"head.h"
#include<string>
/*
* ��ģ��
* 
* ���ã�����һ��ͨ���࣬���еĳ�Ա �������Ͳ�����ָ����
*		  ��һ����������������� ~~~~~~~~
*				~~~~~~~~~~
* �﷨��template<typename T1,typename T2>;	//typename ������ class ����
*		class myClass{};
* 
* P.S. ע����ģ�� ��ʵ�����﷨
*	   myClass<T1 p1, T2 p2> p0();
*	   myClass<T1 p1, T2 p2> p1 = myClass<T1 p1, T2 p2>();
*	   myClass<T1 p1, T2 p2> p2 = p1;
* 
*/

// template�Ĳ����б������ж����������
template<typename NameType,typename AgeType>
class Person08 {
public:
	Person08() {}
	Person08(NameType name, AgeType age) :m_Name(name),m_Age(age) {}
	void showInfo() {
		cout << this->m_Name << " is " << this->m_Age << "." << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

static void test() {
	Person08<string, int> p1 = Person08<string, int>("zhangsan", 16);
	Person08<string, int> p2("lisi",18);
	Person08<string, int> p();

	p1.showInfo();
	p2.showInfo();

}

int main08() {
	test();
	return 0;
}
