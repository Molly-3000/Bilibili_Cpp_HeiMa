#include<iostream>
using namespace std;

int main34() {
	// Ԫ������
	int arr[] = { 1,2,3,4,5 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i];
	}
	cout << endl;

	int size = sizeof(arr) / sizeof(arr[0]);
	int start = 0;          // ��start��end���λ��
	int end = size - 1;

	// ѭ��ֱ�� ��ʼ>=����λ��
	while (start < end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}

	for (int i = 0; i < size; i++) cout << arr[i] << endl;

	system("pause");
	return 0;
}