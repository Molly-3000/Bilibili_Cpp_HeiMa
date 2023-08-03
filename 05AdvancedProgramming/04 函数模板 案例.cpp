#include"head.h"
/*
* ����ģ�� ����
* 
* Ҫ�����ú���ģ���װһ�������������ԶԲ�ͬ�������������������
*		�������Ϊ�Ӵ�С�������㷨Ϊѡ������
*		�ֱ����� char[] �� int[] ���в���
*/

template<typename T>
void swapT(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void sortT(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int max = i;
		for (int j = i + 1; j < n; j++) {
			max = arr[max] > arr[j] ? max : j;
		}
		if (max!= i) swapT(arr[i], arr[max]);
	}
}

template<class T>
void printT(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ">";
	}
	cout << endl;
}

static void test01() {
	char arr1[] = "ad23dfi5283md";
	sortT(arr1, sizeof(arr1) / sizeof(char));
	printT(arr1, sizeof(arr1) / sizeof(char));
}

static void test02() {
	int arr1[] = { 1,2,3,6,3,6,7,8,2 };
	sortT(arr1, sizeof(arr1) / sizeof(int));
	printT(arr1, sizeof(arr1) / sizeof(int));
}

int main04() {
	test01();
	test02();
	return 0;
}