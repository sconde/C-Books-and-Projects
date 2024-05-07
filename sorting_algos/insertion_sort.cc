#include <chrono>
#include <iostream>
#include <vector>

/*
1. Start with the second element (index 1) and iterate through the array.

2. For each element, compare it with the elements before it, moving larger
elements one position to the right until finding its correct position.

3. Insert the current element into its correct position in the sorted portion of
the array.

Time Complexity:
- Best Case: O(n) - This occurs when the input array is already sorted, and the
inner loop executes without needing to shift elements.

- Average Case: O(n^2) - In the average case, each element needs to be compared
and possibly shifted to its correct position, resulting in quadratic time
complexity.

- Worst Case: O(n^2) - This occurs when the input array is in reverse order, and
each element needs to be compared and shifted to the beginning of the array.

Space Complexity:

- Insertion sort is an in-place sorting algorithm, meaning it doesn't require
any additional space other than the input array itself. Therefore, its space
complexity is O(1), indicating constant space usage regardless of the size of
the input array.
*/

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

  // Measure the time taken by the bubble sort algorithm
  auto start = std::chrono::high_resolution_clock::now();
  insertionSort(arr);
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Sorted array: " << '\n';  // Replace std::endl with '\n'
  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << '\n';  // Replace std::endl with '\n'
  // Calculate and print the elapsed time
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time taken by bubble sort: " << duration.count()
            << " microseconds" << '\n';  // Replace std::endl with '\n'

  return 0;
}
