#include <iostream>
#include <vector>

/*
Selection sort is another straightforward sorting algorithm. It repeatedly
selects the minimum (or maximum, depending on sorting order) element from the
unsorted portion of the array and moves it to the beginning of the sorted
portion.

Here's how the selection sort algorithm works:

1. Find the minimum element in the unsorted portion of the array.
2. Swap it with the first element of the unsorted portion.
3. Move the boundary between the sorted and unsorted portions one element to the
right.

Time Complexity:

Best Case: O(n^2) - The best, average, and worst cases are all O(n^2) because
selection sort always scans the entire array to find the minimum element,
regardless of the input's initial state.

Space Complexity:

Selection sort is an in-place sorting algorithm, meaning it doesn't require any
additional space other than the input array itself. Therefore, its space
complexity is O(1), indicating constant space usage regardless of the size of
the input array.
*/

void selectionSort(std::vector<int>& arr) {
  const auto n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      std::swap(arr[i], arr[min_index]);
    }
  }
}

int main() {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  selectionSort(arr);

  std::cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
