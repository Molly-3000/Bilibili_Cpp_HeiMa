#include"head.h"

/*
* friend����Ԫ
* 
*	public������private����
*	��Щprivate���ԣ�Ҳ���������һЩ����ĺ����������
*		
* ���ã���һ��������������� ��һ���� �е� ˽�г�Ա
* 
* ʵ�֣�3��
*		1��ȫ�ֺ�������Ԫ
*		2��������Ԫ
*		3����Ա��������Ԫ	������ע��
*/

class myFriend;
class Building;

// 3����ĳ�Ա��������Ԫ
class myFriend2 {
public:
	void visit(Building* building); 
	// ��Ϊc++�Ǵ�ǰ�������α���ģ�����
	// ��Ԫ�ຯ�������������� Building��Ķ���֮ǰ
	// ��Ԫ�ຯ����ʵ�ֱ����� Building��Ķ���֮��
};

class Building {

	// ������Ԫ�����Է���˽�г�Ա
	friend void goodFriend(Building* building);			// ��Ԫȫ�ֺ���
	friend myFriend;									// ��Ԫ��
	friend void myFriend2::visit(Building* building);	// ��Ԫ��Ա����

public:
	Building() {
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}

public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};


// 1��ȫ�ֺ�������Ԫ
static void goodFriend(Building* building) {
	cout << " A good frind is visiting my " << building->m_SittingRoom << endl;
	cout << " A good frind is visiting my " << building->m_BedRoom << endl;
}

static void test01() {
	Building myHouse;
	goodFriend(&myHouse);
}


// 2��������Ԫ����Ԫ�ࣩ
class myFriend {
public:
	void visit(Building* building) {
		cout << " A good frind is visiting my " << building->m_SittingRoom << endl;
		cout << " A good frind is visiting my " << building->m_BedRoom << endl;
	}
};

static void test02() {
	Building myHouse;
	myFriend friend1;
	friend1.visit(&myHouse);
}



void myFriend2::visit(Building* building) {
	cout << " A good frind is visiting my " << building->m_SittingRoom << endl;
	cout << " A good frind is visiting my " << building->m_BedRoom << endl;
}

static void test03() {
	Building myHouse;
	myFriend2 friend2;
	friend2.visit(&myHouse);
}

int main22() {

	test01();

	test02();

	test03();

	system("pause");
	return 0;
}