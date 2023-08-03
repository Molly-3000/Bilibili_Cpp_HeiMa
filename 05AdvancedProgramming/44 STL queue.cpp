#include"head.h"
/*
* STL queue ����
* 
* 1����������
* 
*	queue��һ���Ƚ��ȳ�(first in first out, FIFO)�����ݽṹ
*			   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ����������
* 
*		��βֻ����� push()����ͷֻ�ܳ��� pop()
*		back()				 front()		
*		
*		ֻ�ж�ͷ�Ͷ�β���ݿ��Է��ʣ���֧���������
* 
*	p.s. queue��֧�ֱ�������֧���������
*			������empty()������size()
* 
* 2�����ýӿ�
* 
*	���캯����
*		��queue<T> ();
*		��queue<T> (const queue<T>& q) 
* 
*	��ֵ������
*		��queue<T>& operator=(const queue<T>& q)
* 
*	���ݴ�ȡ��
*		��void push(T elem)
*		��void pop()
*		��T fornt()
*		��T back()
* 
*	��С������
*		��bool empty()
*		��int size()
* 
*/

#include<queue>
class Person44 {
public:
	Person44(string name, int age):m_name(name),m_age(age) {}
	string m_name;
	int m_age;
};

static void test() {
	queue <Person44> q;

	// ��� push()
	q.push(Person44("zhangsan", 11));
	q.push(Person44("lisi", 12));
	q.push(Person44("wangwu", 11));
	q.push(Person44("zhaoliu", 15));

	// ��С size()
	cout << "the size of the queue is " << q.size() << endl << endl;

	// Ϊ�� empty()
	while (!q.empty()) {
		// ��ͷ fornt()
		cout << "first one: " << q.front().m_name << " " << q.front().m_age << endl;
		// ��β back()
		cout << "last one: " << q.back().m_name << " " << q.back().m_age << endl;
		// ���� pop()
		q.pop();
	}

	// ��С size()
	cout << "the size of the queue is " << q.size() << endl;

}

int main44() {
	test();
	return 0;
}