#include"head.h"


struct Student {
	string name;
	int age;
	int score;
};

// 结构体数组、结构体指针的使用方法和内置类型相同
int main46() {

	// 结构体数组
	struct Student arr[3];
	Student studentArr[] = {
		{"zhangsan",6,100},
		{"lisi",8,100},
		{"wangwu",5,100}
	};

	for (int i = 0; i < sizeof(studentArr) / sizeof(Student); i++) {
		cout << studentArr[i].name << " " << studentArr[i].age << " " << studentArr[i].score<<endl;
	}


	// 结构体指针
	Student* sp;
	sp = studentArr;

	// 指针 通过 -> 访问结构体变量中的属性
	cout << sp->name << " " << sp->age << " " << sp->score << endl;

	sp++;
	cout << sp->name << " " << sp->age << " " << sp->score << endl;

	sp++;
	cout << (*sp).name << " " << (*sp).age << " " << (*sp).score << endl;   // 这样也可通过指针访问
	  
	system("pause");
	return 0;
}