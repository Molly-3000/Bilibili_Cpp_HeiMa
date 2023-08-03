#include<iostream>
using namespace std;

int main35() {

	// 冒泡做升序
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int count = 0;

	//for (int i = 0; i <sizeof(arr)/sizeof(arr[0])-1; i++) {
	//	for (int j = sizeof(arr) / sizeof(arr[0])-1; j > i; j--) {
	//		count++;
	//		if (arr[j] < arr[j - 1]) {
	//			int temp = arr[j];
	//			arr[j] = arr[j - 1];
	//			arr[j - 1] = temp;
	//		}
	//	}
	//}

	// 总共排序轮数 = 元素个数-1
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
		// 每轮比较次数 = 元素个数-1-轮数
		for (int j = 0; j < sizeof(arr) / sizeof(arr[0])-1-i; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << count << endl;
	for (int i = 0; i < 9; i++) cout << arr[i];

	system("pause");
	return 0;
}