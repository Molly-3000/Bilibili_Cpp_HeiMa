#include<string>
#include<iostream>
using namespace std;
#include<fstream>

/*
* 文件操作 写步骤：
*		1、包含文件头		#include<fstream>
*		2、创建流对象		ifstream ifs;
*		3、打开文件 并 判断文件是否成功打开	ifs.open("文件名",打开方式);ifs.is_open();
*		4、读数据			in 
*		5、关闭文件			ifs.close();
*
*/


static void test01() {
	// 1 包含头文件

	// 2 创建流对象
	ifstream ifs;

	// 3 打开文件 并 判断是否成功打开
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "failed to open the file" << endl;
		return;
	}

	// 4 读数据
	// 
	//// 第一种
	//char buf[1024];
	//while (ifs >> buf) {	// ifs 一次处理一行, 遇到空格、endl或eof停止（包括 不读）
	//	cout << "a line: ";
	//	cout << buf << endl;
	//}
	// 
	//// 第二种
	//char buf[1024];
	//while (ifs.getline(buf, sizeof(buf))) {	// ifs 一次处理一行, 遇到endl或eof停止（包括 不读）
	//	cout << buf << endl;
	//}
	//
	//// 第三种 
	//string buf;
	//while (std::getline(ifs, buf)) {
	//	cout << buf << endl;
	//}
	// 
	//// 第四种
	char c;
	while ((c = ifs.get()) != EOF) {	// EOF end of file 标识
		cout << c;
	}


	// 5 关闭文件
	ifs.close();
}

int main45() {
	test01();

	system("pause");
	return 0;
}