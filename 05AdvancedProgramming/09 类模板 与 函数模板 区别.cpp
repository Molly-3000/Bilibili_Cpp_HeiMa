#include"head.h"
#include<string>
/*
* ͨ��<*>��<*.h>�������汾������c++�ı�׼�⣬������������std�����ռ�
* 
* ��<string.h>��c�ı�׼�⣬���ڴ���char*���͵��ַ���
* ��<cstring>��c++���ڼ���c��׼����<string.h>�Ŀ��ļ�
* <string>�ǰ�װ��std��C++ͷ�ļ�����Ӧ�����µ�string��
*/

/*
* ��ģ�� �� ����ģ�� ����
* 
* 1����ģ�岻���Զ������Ƶ�������ģ��ֻ����ʾָ������
* 
* 2����ģ�������ģ������б��У���Ĭ�ϲ���
*/

template<class NameType,class AgeType = int>
class Person09 {
public:
	Person09(NameType name,AgeType age):m_name(name),m_age(age) {}
	void showInfo() {
		cout << this->m_name << " is " << this->m_age << "." << endl;
	}
	NameType m_name;
	AgeType m_age;
};

// 1����ģ���޷��Զ������Ƶ�
static void test01() {
	//Person09 p1("auto_type", 10);	//err,ȱ����ģ��Ĳ����б�
	
	Person09<string, int> p1("explict_type", 10);
	p1.showInfo();
}

// 2����ģ�������ģ������б��У�ʹ��Ĭ�ϲ���
static void test02() {
	Person09<string> p("default_type", 100);
	p.showInfo();
}

int main09() {
	test01();
	test02();
	return 0;
}


