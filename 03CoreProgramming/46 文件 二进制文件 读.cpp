#include"head.h"
#include<fstream>
#include<string>

/*
* �������ļ� д
*
* �򿪷�ʽָ��Ϊ ios::binary
* 
* ������ д��
*	ostream& wirte(const char* buffer, int len);
*					��ȡ���ݵĿռ��ַ�����ݳ���
*/

class Person46 {
public:
	char m_Name[64];
	int m_Age;
};

static void test01() {
	Person46 person{ "zhangsan",16 };
	Person46* person2 = new Person46({ "zhangsan",16 });

	ofstream ofs;
	ofs.open("test binary.txt", ios::out | ios::binary);
	ofs.write((const char*)&person, sizeof(Person46));	// ǿ������ת��Ϊ const char*

	ofs.close();

}

int main46() {

	test01();

	system("pause");
	return 0;
}