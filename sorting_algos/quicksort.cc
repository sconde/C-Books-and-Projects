#include <i386/limits.h>

#include <cstddef>
#include <iostream>
#include <vector>

/*
Quick Sort is another efficient divide-and-conquer sorting algorithm. It selects
a pivot element and partitions the array into two sub-arrays such that elements
less than the pivot are on the left, and elements greater than the pivot are on
the right. It then recursively sorts the sub-arrays.

Here's how the Quick Sort algorithm works:

1. Choose a pivot element from the array.

2. Partition the array into two sub-arrays: elements less than the pivot and
elements greater than the pivot.

3. Recursively apply the Quick Sort algorithm to each sub-array.

Time Complexity:

- Best Case: O(n log n) - The best-case time complexity of Quick Sort occurs
when the pivot divides the array into approximately equal parts in each
recursive call.

- Average Case: O(n log n) - Quick Sort has an average-case time complexity of
O(n log n), making it highly efficient on average.

- Worst Case: O(n^2) - The worst-case time complexity occurs when the pivot is
always the smallest or largest element in the array, resulting in unbalanced
partitions.

Space Complexity:

Quick Sort is an in-place sorting algorithm, meaning it doesn't require
additional space proportional to the input size. However, its space complexity
is O(log n) due to the recursive calls and the stack space used for
partitioning.
*/

size_t partition(std::vector<int>& arr, size_t low, size_t high) {
  size_t pivot = arr[high];
  size_t i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(std::vector<int>& arr, size_t low, size_t high) {
  if (low < high) {
    size_t pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  quickSort(arr, 0, arr.size() - 1);

  std::cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
