#include <iostream>
using namespace std;
//冒泡排序
void bubble(int num[], int n) {
	bool jud = true;
	for (int i = n; i > 0; i--) {
		jud = true;
		for (int j = 0; j < n - 1; j++) {
			if (num[j] < num[j + 1]) {
				int temp = num[j + 1];
				num[j + 1] = num[j];
				num[j] = temp;
				jud = false;
			}
		}
		if (jud)break;
	}
}
int scheduling(int job[], int machine[], int n, int m) {
	bubble(job, n);
	int num = 0;
	//循环寻找当前最长作业分配到空闲作业
	while (num != n) {
		int temp = job[num];
		bubble(machine, m);
		machine[m - 1] += temp;
		num++;
	}
	//找到机器使用时间中的最大值
	bubble(machine, m);
	return machine[0];
}
int main() {
	//设有n个独立作业，m台机器
	int m, n;
	cout << "Please input the num of jobs and machines: ";
	cin >> n >> m;
    int *machine = new int[m]{0};
	int *job = new int[n];
	cout << "Please input the time of each job: ";
	for (int i = 0; i < n; i++) {
		cin >> job[i];
	}
	int result = scheduling(job, machine, n, m);
	cout << "the minimum of scheduling time is: " << result;
	system("pause");
	return 0;
}
