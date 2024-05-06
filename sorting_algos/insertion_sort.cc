#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
  const auto n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  insertionSort(arr);

  std::cout << "Sorted array: ";
  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
