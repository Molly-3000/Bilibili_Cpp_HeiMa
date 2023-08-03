#include<iostream>
using namespace std;

int main33() {

	// 寻找最大值
	int arr[] = {300,350,200,400,250};

	int max = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		max = max > arr[i] ? max : arr[i];
	}

	cout << max << endl;


	// 元素逆置
	int arr2[] = { 1,2,3,4,5 };
	int size = sizeof(arr2) / sizeof(arr2[0]);
	int start = 0;          // 用start、end标记位置
	int end = size - 1;

	while(start<end) {
		int temp = arr2[start];
		arr2[start] = arr2[end];
		arr2[end] = temp;
		start++;
		end--;
	}
	
	for (int i = 0; i < size; i++) cout << arr2[i] << endl;

	system("pause");
	return 0;
}