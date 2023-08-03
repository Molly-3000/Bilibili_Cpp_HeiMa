#include"head.h"

/*
* 重载关系运算符
* 
* ==，！=，>，<，>=，<=
* 
*/

class Person27 {
public:
	Person27(string name, int age) :m_Name(name),m_Age(age) {}

	bool operator==(Person27 p) {
		return (m_Name == p.m_Name) && (m_Age == p.m_Age);
	}

	bool operator!=(Person27 p) {
		return !((m_Name == p.m_Name) && (m_Age == p.m_Age));
	}

	string m_Name;
	int m_Age;
};

static void test01() {
	Person27 p1("Tom", 18);
	Person27 p2("Tom", 18);

	Person27 p3("Jerry", 18);

	if (p1 == p2) cout << "p1 == p2 is valid" << endl;
	if (p1 != p3) cout << "p1 != p3 is valid" << endl;

}

int main27() {

	test01();

	system("pause");
	return 0;
}