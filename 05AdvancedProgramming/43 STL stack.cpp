#include"head.h"
/*
* STL stack ջ
* 
* 1�����ջ��һ���Ƚ����(first in last out,FILO)�����ݽṹ
*				~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ��һ������
*		
*		ջ��Ϊ����ڣ�ֻ�ɷ���ջ��Ԫ��top()��ջ�ײ��ɷ���
*			��ջpush()    ��ջpop()
* 
*	p.s. ջ��֧�ֱ�����Ϊ����֧���������
*			��֧��empty()��size()

* 2�����ýӿ�
* 
* ���캯����
*	��stack<T>();						// �޲ι���
*	��stack<T>(const stack<T>& stk);	// ��������
* 
* ��ֵ������
*	��stack<T>& operator=(const stack<T>& stk);
* 
* ���ݴ�ȡ��
*	��void push(T elem)
*	��void pop()
*	��void top()
* 
* ��С������
*	��bool empty()
*	��int size()
* 
*/

#include<stack>
static void test() {
	stack<int> st;

	// ��ջ
	for (int i = 0; i < 10; i++) {
		st.push(i * 111);
	}

	// empty()
	if (st.empty()) {
		cout << "the stack is empty." << endl;
	}

	// size()
	cout << "size of the stack is " << st.size() << endl;

	while (st.size()) {	// !!! size()�ڱ仯
		// ����ջ��
		cout << st.top() << " " << endl;
		// ��ջ
		st.pop();
	}

	cout << "size of the stack is " << st.size() << endl;
}

int main43() {
	test();
	return 0;
}