#include"head.h"

/*
* ��̬	������ �� ��������
*
*	���ã�ͨ�������������������Ϊ ������ �� ���������ķ�ʽ
*			�������ָ�� �޷����� ������������������
*					�Ӷ�ͨ������ָ�� �ͷ� �������������
* 
*	ԭ������������������麯������ôdeleteʱ��
*				�޶�̬�󶨣�ִ�е��Ǹ��ࣨ����̬���ͣ�����������
*		  ��������������麯������ôdeleteʱ��
*				��ͨ����������vptr��̬�󶨵����ࣨ����̬���ͣ����鹹����
*				����������������죩����������ʽ���ø������������죩����
*											  ����super(), ~super()
* 
* ������vs��������
* 
*	���ԣ����Խ�������ͷ������������⣨�޷��ͷŸɾ���
*		����Ҫ�����ṩ�����ĺ���ʵ��
* 
*	�����д�����������Ϊ�����࣬�޷�ʵ����
* 
* �������﷨
*	virtual ~ClassName() {}
* 
* ���������﷨
*  virtual ~ClassName() = default;	// ������������δʵ��
* 
*
*/

class AbstractAnimal42 {
public:
	AbstractAnimal42() {
		cout << " This is Animal constructor" << endl;
	}
	virtual void speak() = 0;

	//virtual ~AbstractAnimal42() {	// ������ ��̬�󶨣�����ָ������ͷ��������
	//	cout << " This is virtual Animal deconstructor" << endl;
	//}

	virtual ~AbstractAnimal42() = default;	// ��������
};

class Cat42 :public AbstractAnimal42 {
public:
	Cat42() {
		cout << " This is Cat constructor" << endl;
	}
	void speak() {
		cout << " Meow." << endl;
	}

	// ������ ��̳�
	~Cat42() {
		cout << " This is virtual Cat deconstructor" << endl;
	}
};

static void test01() {
	AbstractAnimal42* animal = new Cat42;
	animal->speak();
	delete animal;
}


int main42() {

	test01();

	system("pause");
	return 0;
}