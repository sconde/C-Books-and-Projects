#include <chrono>
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
  const auto n = arr.size();
  bool swapped = false;
  for (auto i = 0; i < n - 1; i++) {
    swapped = false;
    for (auto j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap arr[j] and arr[j+1]
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    if (not swapped) {
      break;
    }
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  // Measure the time taken by the bubble sort algorithm
  auto start = std::chrono::high_resolution_clock::now();
  bubbleSort(arr);
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  // Calculate and print the elapsed time
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time taken by bubble sort: " << duration.count()
            << " microseconds" << std::endl;

  return 0;
}
