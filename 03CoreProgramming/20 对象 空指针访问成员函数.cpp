#include"head.h"

/*
* C++������ָ����ó�Ա��������Ҫע���Ա������û���õ�thisָ��
* 
* ����õ�thisָ�룬��Ҫ���ж���䣬����ǿ����³����
*/

class Person20 {

public:
	// û���õ�thisָ��
	void showClassName() {
		cout << " This is Person class" << endl;
	}

	// �õ���thisָ�룬��this->m_Age��c++Ĭ�ϵ�������ǰ����thisָ�룩����thisָ��ΪNULL
	void showPersonAge() {
		if (this == NULL) return;		// ��ߴ��뽡׳�ԣ���ֹ��ָ�����
		cout << " The age of person is " << m_Age << endl;
	}

	int m_Age;

};

int main20() {

	Person20* p = NULL;

	p->showClassName();

	p->showPersonAge(); // error

	system("pause");
	return 0;
}