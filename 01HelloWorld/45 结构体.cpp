#include<iostream>

// �ṹ�壺�û��Զ�����������ͣ����п��Դ洢�������õ���������
// 
// �﷨��struct �ṹ������ {};
// 
// ���ִ�����ʽ��
//		1����ʼ����ֵ
//		2��δ��ʼ����ͨ�� . ���ʽṹ�����������
//		3���ڶ���ṹ��ʱ��˳�㴴������			// ������
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
	struct Student stu[10];   // �ṹ��Ƕ�׽ṹ��
};

// �ṹ����Ϊ��������  ֵ����   ���������ݵĿ���
void printStudent0(Student stu) {
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	//stu.age = 0; // ���ܸ�������ֵ
}

// ���ô���
void printStudent(const Student& stu) {
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	//stu.age = 0; // ���ܸ�������ֵ
}

// ��ַ����
// �������е��βθ�Ϊָ�룬���Լ����ڴ濪����ָ��ֻ��4�ֽڣ������Ḵ���µĸ���
void printStudent(const Student* stu) {
	cout << stu->name << " " << stu->age << " " << stu->score << endl;
	//stu->age = 0;  // const ���� �޷��޸ĳ������� const student
	return;
}

int main45() {

	struct Student s0 = { "zhangsan",19,80 };   // struct �ؼ��ֿ�ʡ��

	cout << s0.name << " " << s0.age << " " << s0.score << endl;

	Student s1;
	s1.name = "lisi";	// ͨ�� . ���ʽṹ�����������
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
	

	printStudent0(s0);	// ֵ����

	printStudent(s0);	// ���ô���

	printStudent(&s0);		// ��ַ����
	printStudent(ts[0].stu[1]);		// ��ַ����


	system("pause");
	return 0;
}