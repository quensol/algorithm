#include<iostream>
using namespace std;
#define NUM 20
void allSort(int i, int n, int num[]) {
	if (i >= n) {
		for (int i = 0; i < n; i++) {
			cout << num[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int t = i; t < n; t++) {
			int temp = num[t];
			num[t] = num[i];
			num[i] = temp;

			allSort(i + 1, n, num);

			temp = num[t];
			num[t] = num[i];
			num[i] = temp;
		}
	}
}
int main() {
	int num;
	cout << "Please input the number: ";
    scanf("%d", &num);
	int n[num];
	for (int i = 0; i < num; i++) {
		n[i] = i + 1;
	}
	allSort(0, num, n);
	system("pause");
	return 0;
}
