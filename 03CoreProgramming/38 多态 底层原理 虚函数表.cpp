#include "head.h"

/*
* ��̬��̬����̬�󶨣� �� �ײ�ԭ��
* 
*		�������麯����
* 
* 1��ÿ���������麯�����࣬������һ�����ָ��vptr
* 
* 2�����ָ��vptrָ�������麯����vftable���ñ�ά�������麯���ĵ�ַ
*		����������࣬�����ڶ��󣬼�һ����ֻ��һ��������ж�����
*		����� �ڱ���׶� ��ȷ���˺�����ַ��
* 
* 3��������������麯������������Ҳ���麯����
* 
* 4������������д�麯��ʱ�������vftable�У��µ��麯�������ǵ������е��麯����ַ
* 
*/

// ���� ��СΪ1
// ��Ϊ���ࡢ�սṹ��Ҳ����ʵ������Ϊ�����ֲ�ͬ��ʵ��������
// ��ͬ�Ķ����ڴ��ַӦ�ò�ͬ�����Ա�����������������������1���ֽ�
class Animal38_ {};

// ����
class Animal38 {
public:
	// ����Ϊ�麯��ά����һ�� vfptr��ָ���麯����
	// �麯���� ά���� ���� �����麯������ڵ�ַ
	virtual void speak() {
		cout << "The animal is speaking." << endl;
	}
};

// ������ ��д�麯��
class Cat38 :public Animal38 {
public:
	// �̳��˻����vfptr��ָ�������vftable
	// ���������� ��д ������麯��
	// ��vftable�У�������麯���Ḳ�Ǹ����麯���ĵ�ַ
	void speak() {
		cout << "Meow." << endl;
	}
};

class Dog38 :public Animal38 {
	// �̳��˻����vfptr��ָ�������vftable
};

static void doSpeak(Animal38 & animal) {
	animal.speak();
}

static void test01() {
	Animal38 animal;
	doSpeak(animal);	// �����speak()

	Cat38 cat;
	doSpeak(cat);		// ��д���󶨵��������speak()

	Dog38 dog;
	doSpeak(dog);		// δ��д���󶨵������speak()
}

int main38() {

	test01();

	system("pause");
	return 0;
}