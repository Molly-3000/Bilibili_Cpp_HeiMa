#include"head.h"
#include<fstream>
#include<string>

/*
* 二进制文件 写
*
* 打开方式指定为 ios::binary
* 
* 二进制 写：
*	ostream& wirte(const char* buffer, int len);
*					读取数据的空间地址，数据长度
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
	ofs.write((const char*)&person, sizeof(Person46));	// 强制类型转化为 const char*

	ofs.close();

}

int main46() {

	test01();

	system("pause");
	return 0;
}