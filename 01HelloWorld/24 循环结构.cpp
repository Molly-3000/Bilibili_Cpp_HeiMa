#include<iostream>
using namespace std;

int main24() {

	int num = 0;

	// ����ѭ����do{ѭ�����;}while(�������ʽ);  
	// while(�������ʽ){ѭ�����;}   
	// for(��ʼ���ʽ;�������ʽ;ĩβѭ����) {ѭ�����;}

	while (num < 10) {
		cout << num << endl;
		num++;
	}

	do {
		num--;
		cout << num << endl;
	} while (num > 0);


	
	for (; num < 10; num++) {
		cout << num << endl;
	}

	// forѭ��������� �ȼ�������
	//for (; ; ) {
	//	if (num < 10) break;
	//	cout << num << endl;
	//	num++;
	//}

	system("pause");
	return 0;
}