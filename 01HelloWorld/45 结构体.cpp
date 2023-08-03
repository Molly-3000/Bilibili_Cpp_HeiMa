#include<iostream>

// 结构体：用户自定义的数据类型，其中可以存储多种内置的数据类型
// 
// 语法：struct 结构体名称 {};
// 
// 三种创建方式：
//		1、初始化赋值
//		2、未初始化，通过 . 访问结构体变量的属性
//		3、在定义结构体时，顺便创建变量			// 很少用
// 
// 

#include"head.h"
struct Student {
	string name;
	int age;
	int score;
}s2,s3;

struct Teacher {
	int tid;
	string name;
	int age;
	struct Student stu[10];   // 结构体嵌套结构体
};

// 结构体作为函数参数  值传递   本质是数据的拷贝
void printStudent0(Student stu) {
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	//stu.age = 0; // 不能给常量赋值
}

// 引用传递
void printStudent(const Student& stu) {
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	//stu.age = 0; // 不能给常量赋值
}

// 地址传递
// 将函数中的形参改为指针，可以减少内存开销（指针只有4字节），不会复制新的副本
void printStudent(const Student* stu) {
	cout << stu->name << " " << stu->age << " " << stu->score << endl;
	//stu->age = 0;  // const 报错 无法修改常量对象 const student
	return;
}

int main45() {

	struct Student s0 = { "zhangsan",19,80 };   // struct 关键字可省略

	cout << s0.name << " " << s0.age << " " << s0.score << endl;

	Student s1;
	s1.name = "lisi";	// 通过 . 访问结构体变量的属性
	s1.age = 10;
	s1.score = 100;
	cout << s1.name << " " << s1.age << " " << s1.score << endl;

	Student s2 = { "wangwu",19,80 };
	cout << s2.name << " " << s2.age << " " << s2.score << endl;

	s3 = { "zhaoliu",19,80 };
	cout << s3.name << " " << s3.age << " " << s3.score << endl;


	Teacher ts[3] = {
		{},
		{},
		{}
	};

	ts[0].name = "laoshi";
	ts[0].age = 50;
	ts[0].tid = 1;
	ts[0].stu[0] = s0;
	ts[0].stu[1] = s1;

	cout << ts[0].name << " " << ts[0].age << " " << ts[0].tid << endl;
	

	printStudent0(s0);	// 值传递

	printStudent(s0);	// 引用传递

	printStudent(&s0);		// 地址传递
	printStudent(ts[0].stu[1]);		// 地址传递


	system("pause");
	return 0;
}