#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      return 1; // Found the target
    } else if (arr[mid] < target) {
      left = mid + 1; // Target is in the right half
    } else {
      right = mid - 1; // Target is in the left half
    }
  }

  return 0; // Target not found
}

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 5;

  int result = binarySearch(arr, size, target);

  if (result) {
    printf("The target is in the array.\n");
  } else {
    printf("The target is not in the array.\n");
  }

  return 0;
}