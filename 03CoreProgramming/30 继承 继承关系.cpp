#include"head.h"

/*
* �̳й�ϵ������
*			public | protected | private
* 
* �Ӹ����м̳еõ������ԣ�����Ȩ���� �̳й�ϵ �� �����ж���ķ���Ȩ�� ��ͬ����
*			���ȼ� public < protected < private
* 
*	����						����
*				�����̳�		�����̳�		˽�м̳�
*	public		public			protected		private
*	protected	protected		protected		private
*	private		���ɷ���		���ɷ���		���ɷ���
* 
*/		

class Base30 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1:public Base30{
public: 
	Son1() {
		m_A = 1;	// ������public		->public�̳�	->������public
		m_B = 2;	// ������protected	->public�̳�	->������protected
		//m_C = 3;	// error, m_C is privated, ���಻�ɷ���
	}
};

class Son2:protected Base30{
public:
	Son2() {
		m_A = 1;	// ������public		->protected�̳�		->������protected
		m_B = 2;	// ������protected	->protected�̳�		->������protected
		//m_C = 3;	// error, m_C is privated, ���಻�ɷ���
	}
};

class Son3:private Base30{
public:
	Son3() {
		m_A = 1;	// ������public		->private�̳�		->������private
		m_B = 2;	// ������protected	->private�̳�		->������private
		//m_C = 3;	// error, m_C is privated, ���಻�ɷ���
	}
};

static void test01() {
	Son1 son1;
	son1.m_A = 10;
	//son1.m_B = 20;	//error, m_B is protected�����ⲻ�ɷ���

	Son2 son2;
	//son2.m_A = 10;	//error, m_A is protected�����ⲻ�ɷ���
	//son2.m_B = 20;	//error, m_B is protected�����ⲻ�ɷ���

	Son3 son3;
	//son3.m_A = 10;	//error, m_A is private�����ⲻ�ɷ���
	//son3.m_B = 20;	//error, m_B is private�����ⲻ�ɷ���
}

class GrandSon3 :public Son3 {
public:
	GrandSon3() {
		//m_A = 100;	//error, m_A is private�����ⲻ�ɷ���
	}
};

int main30() {
	test01();

	system("pause");
	return 0;
}