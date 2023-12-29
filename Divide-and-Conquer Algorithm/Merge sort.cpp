#include <iostream>

using namespace std;

void merge(int *arr, int low, int mid, int high) {
  // 创建两个临时数组，用于存储两个有序子数组
  int *left = new int[mid - low + 1];
  int *right = new int[high - mid];

  // 将两个子数组的数据复制到临时数组中
  for (int i = 0; i < mid - low + 1; i++) {
    left[i] = arr[low + i];
  }
  for (int i = 0; i < high - mid; i++) {
    right[i] = arr[mid + 1 + i];
  }

  // 合并两个有序子数组
  int i = 0, j = 0, k = low;
  while (i < mid - low + 1 && j < high - mid) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }

  // 将剩余元素复制到原数组中
  while (i < mid - low + 1) {
    arr[k++] = left[i++];
  }
  while (j < high - mid) {
    arr[k++] = right[j++];
  }

  // 释放临时数组
  delete[] left;
  delete[] right;
}

void merge_sort(int *arr, int low, int high) {
  // 递归终止条件
  if (low >= high) {
    return;
  }

  // 分解
  int mid = (low + high) / 2;
  merge_sort(arr, low, mid);
  merge_sort(arr, mid + 1, high);

  // 合并
  merge(arr, low, mid, high);
}

int main() {
  int arr[] = {5, 2, 4, 1, 3, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  // 打印原数组
  cout << "原数组：" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // 归并排序
  merge_sort(arr, 0, n - 1);

  // 打印排序后的数组
  cout << "排序后的数组：" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
