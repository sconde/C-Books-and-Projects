#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
  const auto n = arr.size();
  for (auto i = 0; i < n - 1; i++) {
    for (auto j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap arr[j] and arr[j+1]
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  bubbleSort(arr);
  std::cout << "Sorted array: ";
  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}