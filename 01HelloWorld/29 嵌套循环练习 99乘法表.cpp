#include<iostream>
using namespace std;

int main29() {

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << "x" << i << "=" << i * j <<" ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}