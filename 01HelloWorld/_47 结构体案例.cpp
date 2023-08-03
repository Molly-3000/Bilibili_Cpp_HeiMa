#include"head.h"

// 

#include<ctime>

struct Student {
	string name;
	int score;
};

struct Teacher {
	string name;
	Student stus[5];
};

void inputInfo(Teacher teacher[], int len) {

	string nameSeed = "ABCDE";
	srand((unsigned int)time(NULL));

	for (int i = 0; i < len; i++) {
		teacher[i].name = "Teacher_";
		teacher[i].name += nameSeed[i];

		for (int j = 0; j < 5; j++) {
			teacher[i].stus[j].name = "Student_";
			teacher[i].stus[j].name += nameSeed[j];
			teacher[i].stus[j].score = rand()%61+40;  // [40,100]
		}

	}
}

void printInfo(Teacher teacher[], int len) {
	for (int i = 0; i < len; i++) {
		cout << teacher[i].name << "老师带的学生有：" << endl;

		for (int j = 0; j < 5; j++) {
			cout << teacher[i].stus[j].name <<  " " << teacher[i].stus[j].score<< "分" << endl;
		}
	}


}


struct Hero {
	string name;
	int age;
	bool isFemale;
};

void bubbleHeroByAge(Hero* heroArr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (heroArr[j].age > heroArr[j + 1].age) {
				Hero temp = heroArr[j];
				heroArr[j] = heroArr[j + 1];
				heroArr[j + 1] = temp;
			}
		}
	}
}

void printHeroArr(Hero* heroArr, int len) {
	for (int i = 0; i < len; i++) {
		cout << heroArr[i].name << " " << heroArr[i].age << endl;
	}
}

int main() {

	//Teacher teachers[3];

	//int len = sizeof(teachers) / sizeof(teachers[0]);

	//inputInfo(teachers, len);

	//printInfo(teachers, len);


	Hero heros[5] = {
		{"liubei",23,false},
		{"guanyu",22,false},
		{"zhangfei",20,false},
		{"zhaoyun",21,false},
		{"diaochan",19,true}
	};

	bubbleHeroByAge(heros, sizeof(heros) / sizeof(Hero));
	printHeroArr(heros, sizeof(heros) / sizeof(heros[0]));

	system("pause");

	return 0;
}