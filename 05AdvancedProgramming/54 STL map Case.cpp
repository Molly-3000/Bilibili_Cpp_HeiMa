#include"head.h"
/*
* STL map Case
* 
* CD：	公司招了10个员工（ABCD..），需要指派每个员工的部门
*		员工信息有：姓名、工资
*		部门分别为：策划、美术、研发
*		随机给10名员工分配部门和工资
*		通过multimap进行信息插入	key--编号	value--员工
*		分部门显示员工信息
* 
*/

#include<vector>
#include<map>
#include<ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Person54 {
public:
	Person54(string name, int salary) {
		this->m_name = name;
		this->m_salary = salary;
	}
	string m_name;
	int m_salary;
};

static void init_staff(vector<Person54>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		v.push_back(Person54(string("员工") += nameSeed[i], 0));
	}
}

static void group_staff(vector<Person54>& v, multimap<int, Person54>& m) {

	int salaryS[3];
	salaryS[0] = (rand() % 100 + 61) * 100;
	salaryS[1] = (rand() % 150 + 71) * 100;
	salaryS[2] = (rand() % 200 + 81) * 100;

	int dep;
	for (int i = 0; i < v.size(); i++) {
		dep = rand() % 3;
		v[i].m_salary = salaryS[dep];
		m.insert(make_pair(dep, v[i]));
	}

}

static void show_group(multimap<int, Person54>& m) {

	multimap<int, Person54>::iterator it1 = m.find(CEHUA);
	multimap<int, Person54>::iterator it2 = m.find(MEISHU);
	multimap<int, Person54>::iterator it3 = m.find(YANFA);

	cout << "策划部门：" << endl;
	for (multimap<int, Person54>::iterator it = it1; it != it2; it++) {
		cout << it->second.m_name << " " << it->second.m_salary << endl;
	}

	cout << "美术部门：" << endl;
	for (multimap<int, Person54>::iterator it = it2; it != it3; it++) {
		cout << it->second.m_name << " " << it->second.m_salary << endl;
	}

	cout << "研发部门：" << endl;
	for (multimap<int, Person54>::iterator it = it3; it != m.end(); it++) {
		cout << it->second.m_name << " " << it->second.m_salary << endl;
	}

}

static void test() {

	vector<Person54> vp;
	init_staff(vp);

	multimap<int, Person54> mp;
	group_staff(vp, mp);

	show_group(mp);

}

int main54() {
	srand((unsigned int)time(NULL));

	test();
	return 0;
}