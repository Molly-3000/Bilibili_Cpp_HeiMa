#include"head.h"

/*
* ��̬ Polynorphism
* 
* ���ࣺ
*		��̬��̬���������أ��������������		���������ĸ��ã�
*		��̬��̬�����麯�� �� ������ ��ͬʵ�ֵ�����ʱ�Ķ�̬
* 
* ����
*		��̬��̬ ������ַ���		����׶�ȷ��������ַ
*		��̬��̬ ������ַ���		���н׶�ȷ��������ַ
* 
* ��̬��̬�� ʵ��������
*		1���м̳й�ϵ�����л����������
*		2��������Ҫ ��д �����е� �麯��
*					����		  ������
*		*��д��ʵ�������麯�� ����ֵ���� ������ �����б� ��ȫһ��
*		
* ��̬��̬�� ʹ�ã�
*		�����ָ�� �� ���� ָ������Ķ���
*			  ����    ����
*		�����Ǿ�̬����     �����Ƕ�̬����
* 
* ��̬��̬�� ԭ��
*		����������ڴ��а����������֣�
*			���ಿ�֣�����Ǿ�̬��Ա�������ಿ�֣�����Ǿ�̬��Ա��
*		��ͨ�����û�ָ��� ʵ�ֵ� ��ʽ����ת����
*			����ת��Ϊ���࣬��������Ϊ ÿ��������󶼰���һ�����ಿ��
*		ָ�������ʵ���� �󶨵���������ಿ����
*/

class Animal37 {
public:

	// ��ַ��� �ڱ���׶�ȷ��������ַ
	// speak()������Ϊ Animal.speak()
	//void speak() {
	//	cout << "The animal is speaking." << endl;
	//}

	// �麯�� 
	// ��ַ��� ���н׶ΰ�Ϊ ������.speak()
	virtual void speak() {
		cout << "The animal is speaking." << endl;
	}
};

class Cat37:public Animal37 {
public:
	void speak() {
		cout << "Meow." << endl;
	}
};

class Dog37:public Animal37 {
public:
	void speak() {
		cout << "Woof." << endl;
	}
};


void doSpeak(Animal37& animal) {	// Animal & animal = cat;
	animal.speak();
}

static void test01() {

	Animal37 animal;
	doSpeak(animal);

	Cat37 cat;
	doSpeak(cat);	// Animal & animal = cat; // �������ת��Ϊ���࣬��֮����

	Dog37 dog;
	doSpeak(dog);	// Animal & animal = dog;


}

int main37() {

	test01();

	system("pause");
	return 0;
}