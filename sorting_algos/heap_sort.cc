#include <iostream>
#include <vector>

/*
Heap Sort is an efficient sorting algorithm based on the binary heap data
structure. It builds a max-heap from the input array, repeatedly extracts the
maximum element from the heap, and places it at the end of the sorted portion of
the array.

Here's how the Heap Sort algorithm works:

1. Build a max-heap from the input array.

2. Repeat the following steps until the heap size is 1:

2.1. Swap the root (maximum element) of the heap with the last element of the
heap.

2.2. Reduce the heap size by 1 (excluding the last element).

2.3. Heapify the root to maintain the max-heap property.


Time Complexity:

Best Case: O(n log n) - The best-case time complexity of Heap Sort is O(n log
n), which occurs when the input array is already a max-heap.

Average Case: O(n log n) - Heap Sort has an average-case time complexity of O(n
log n), making it highly efficient on average.

Worst Case: O(n log n) - The worst-case time complexity also occurs when the
input array is not a max-heap, requiring O(n log n) comparisons and swaps.

Space Complexity:

Heap Sort is an in-place sorting algorithm, meaning it doesn't require
additional space proportional to the input size. Therefore, its space complexity
is O(1), indicating constant space usage regardless of the size of the input
array.
*/

void heapify(std::vector<int>& arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) largest = left;

  if (right < n && arr[right] > arr[largest]) largest = right;

  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(std::vector<int>& arr) {
  int n = arr.size();

  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

  // Extract elements from the heap one by one
  for (int i = n - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);  // Move current root to end
    heapify(arr, i, 0);         // Call max heapify on the reduced heap
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  heapSort(arr);

  std::cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
