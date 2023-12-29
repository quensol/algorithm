#include <iostream>

using namespace std;

int partition(int *arr, int low, int high) {
  // 选择枢轴元素
  int pivot = arr[high];

  // 将小于枢轴元素的元素移到左边，大于枢轴元素的元素移到右边
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  // 将枢轴元素放到中间位置
  swap(arr[i + 1], arr[high]);

  // 返回枢轴元素的位置
  return i + 1;
}

void quick_sort(int *arr, int low, int high) {
  // 递归终止条件
  if (low >= high) {
    return;
  }

  // 分解
  int pi = partition(arr, low, high);

  // 递归排序左子数组
  quick_sort(arr, low, pi - 1);

  // 递归排序右子数组
  quick_sort(arr, pi + 1, high);
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

  // 快速排序
  quick_sort(arr, 0, n - 1);

  // 打印排序后的数组
  cout << "排序后的数组：" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
