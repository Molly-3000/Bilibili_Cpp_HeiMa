#include "head.h"

void bubbleSort(int* arr, int len);
void printArray(int arr[], int len);

int main44() {
	int arr[] = { 4,3,1,2,6,9,10,8,7,5 };
	int len = sizeof(arr) / sizeof(int);

	bubbleSort(arr, len);
	printArray(arr, len);

	system("pause");
	return 0;
}

void printArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int* arr, int len) {

	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}