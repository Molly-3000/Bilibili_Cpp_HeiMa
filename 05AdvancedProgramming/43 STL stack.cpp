#include"head.h"
/*
* STL stack 栈
* 
* 1、概念：栈是一种先进后出(first in last out,FILO)的数据结构
*				~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 仅一个出口
*		
*		栈顶为出入口，只可访问栈顶元素top()，栈底不可访问
*			入栈push()    出栈pop()
* 
*	p.s. 栈不支持遍历行为，不支持随机访问
*			但支持empty()，size()

* 2、常用接口
* 
* 构造函数：
*	·stack<T>();						// 无参构造
*	·stack<T>(const stack<T>& stk);	// 拷贝构造
* 
* 赋值操作：
*	·stack<T>& operator=(const stack<T>& stk);
* 
* 数据存取：
*	·void push(T elem)
*	·void pop()
*	·void top()
* 
* 大小操作：
*	·bool empty()
*	·int size()
* 
*/

#include<stack>
static void test() {
	stack<int> st;

	// 入栈
	for (int i = 0; i < 10; i++) {
		st.push(i * 111);
	}

	// empty()
	if (st.empty()) {
		cout << "the stack is empty." << endl;
	}

	// size()
	cout << "size of the stack is " << st.size() << endl;

	while (st.size()) {	// !!! size()在变化
		// 访问栈顶
		cout << st.top() << " " << endl;
		// 出栈
		st.pop();
	}

	cout << "size of the stack is " << st.size() << endl;
}

int main43() {
	test();
	return 0;
}