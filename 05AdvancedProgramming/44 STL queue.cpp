#include"head.h"
/*
* STL queue 队列
* 
* 1、基本概念
* 
*	queue：一种先进先出(first in first out, FIFO)的数据结构
*			   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 有两个出口
* 
*		队尾只能入队 push()，队头只能出队 pop()
*		back()				 front()		
*		
*		只有队头和队尾数据可以访问，不支持随机访问
* 
*	p.s. queue不支持遍历，不支持随机访问
*			但可以empty()，可以size()
* 
* 2、常用接口
* 
*	构造函数：
*		·queue<T> ();
*		·queue<T> (const queue<T>& q) 
* 
*	赋值操作：
*		·queue<T>& operator=(const queue<T>& q)
* 
*	数据存取：
*		·void push(T elem)
*		·void pop()
*		·T fornt()
*		·T back()
* 
*	大小操作：
*		·bool empty()
*		·int size()
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

	// 入队 push()
	q.push(Person44("zhangsan", 11));
	q.push(Person44("lisi", 12));
	q.push(Person44("wangwu", 11));
	q.push(Person44("zhaoliu", 15));

	// 大小 size()
	cout << "the size of the queue is " << q.size() << endl << endl;

	// 为空 empty()
	while (!q.empty()) {
		// 队头 fornt()
		cout << "first one: " << q.front().m_name << " " << q.front().m_age << endl;
		// 队尾 back()
		cout << "last one: " << q.back().m_name << " " << q.back().m_age << endl;
		// 出队 pop()
		q.pop();
	}

	// 大小 size()
	cout << "the size of the queue is " << q.size() << endl;

}

int main44() {
	test();
	return 0;
}