#include"head.h"


struct Student {
	string name;
	int age;
	int score;
};

// �ṹ�����顢�ṹ��ָ���ʹ�÷���������������ͬ
int main46() {

	// �ṹ������
	struct Student arr[3];
	Student studentArr[] = {
		{"zhangsan",6,100},
		{"lisi",8,100},
		{"wangwu",5,100}
	};

	for (int i = 0; i < sizeof(studentArr) / sizeof(Student); i++) {
		cout << studentArr[i].name << " " << studentArr[i].age << " " << studentArr[i].score<<endl;
	}


	// �ṹ��ָ��
	Student* sp;
	sp = studentArr;

	// ָ�� ͨ�� -> ���ʽṹ������е�����
	cout << sp->name << " " << sp->age << " " << sp->score << endl;

	sp++;
	cout << sp->name << " " << sp->age << " " << sp->score << endl;

	sp++;
	cout << (*sp).name << " " << (*sp).age << " " << (*sp).score << endl;   // ����Ҳ��ͨ��ָ�����
	  
	system("pause");
	return 0;
}