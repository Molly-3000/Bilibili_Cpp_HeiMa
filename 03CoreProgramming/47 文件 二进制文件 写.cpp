#include"head.h"
#include<fstream>

/*
* 二进制文件 写
* 
* 打开方式指定为 ios::binary
*
* 二进制 读：
*	ostream& read(char* buffer, int len);
*				接受数据的空间地址，数据长度
*/


class Person47 {
public:
	char m_Name[64];
	int m_Age;
};

static void test01() {
	
	ifstream ifs;

	ifs.open("test binary.txt", ios::in | ios::binary);
	if (!ifs.is_open()) return;

	Person47 p;
	ifs.read((char*)&p, sizeof(Person47));
	cout << p.m_Name << " " << p.m_Age << endl;

	ifs.close();

}

int main47() {

	test01();

	system("pause");
	return 0;
}