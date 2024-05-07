#include <cstddef>
#include <iostream>
#include <vector>

/*
Merge Sort is a divide-and-conquer algorithm that divides the input array into
two halves, recursively sorts each half, and then merges the sorted halves.

Here's how the Merge Sort algorithm works:

1. Divide the unsorted array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into a single sorted array.

Time Complexity:

Best Case: O(n log n) - The best, average, and worst-case time complexities for
Merge Sort are all O(n log n). This is because Merge Sort divides the array into
halves recursively until each sub-array has only one element, then merges them
in linear time.

Space Complexity:

Merge Sort requires auxiliary space for the temporary arrays used during the
merge step. Therefore, its space complexity is O(n), where n is the size of the
input array. This makes Merge Sort not an in-place sorting algorithm.

*/

void merge(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
  size_t n1 = mid - left + 1;
  size_t n2 = right - mid;

  std::vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  size_t i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<int>& arr, size_t left, size_t right) {
  if (left < right) {
    size_t mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  mergeSort(arr, 0, arr.size() - 1);

  std::cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
