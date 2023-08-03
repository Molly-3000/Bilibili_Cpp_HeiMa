#include"head.h"
#include<fstream>

/*
* 文件操作
* 
* C++文件流 <fstream>
* 
* 文件类型：
*		文本文件：	以文本的ASCII码形式存储 
*		二进制文件：以本文的二进制形式存储
* 
* 操作文件的三个类：
*		ifstream		输入流		读
*		ofstream		输出流		写
*		fstream		输入输出流		读写
* 
* 文本文件 操作步骤：
*		1、包含头文件		#include<fstream>
*		2、创建输出流		ofsteam ofs;
*		3、打开文件			ofs.open("文件名",打开方式);		// out, app, ate, trunc
*		4、写数据			ofs<<"写数据";
*		5、关闭文件			ofs.close();
* 
* 文件 打开方式：
*		ios::in			只读
*		ios::out		只写
*		ios::ate		初始位置为文件尾	多用于追加
*		ios::app		以追加方式写文件
*		ios::trunc		如果文件已经存在，先删除，再创建
*		ios::binary		以二进制方式进行操作
* 
*		***如果要多种打开方式配合使用，以|操作符链接
*				ios::in | ios::out | ios::binary
*/


static void test01() {

	// 写
	ofstream ofs;					
	ofs.open("test.txt", ios::out);
	ofs << "test output..."<<endl;		// ofs 一次处理一行
	ofs << "line 2" << endl;			// endl == "\n"+"std::flush"
	ofs << "line 3" << endl;			// endl还调用flush函数，刷新缓冲区，使得栈中的东西刷新一次，但用 "\n" 不会刷新，它只会换行，栈内数据没有变化。
	ofs.close();

}

int main44() {
	test01();

	system("pause");
	return 0;
}