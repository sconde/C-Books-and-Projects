#include <stdio.h>

int findLargest(int arr[], int size) {
  int largest = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  return largest;
}

int main() {
  int arr[] = {5, 10, 3, 8, 2};
  int size = sizeof(arr) / sizeof(arr[0]);

  int largest = findLargest(arr, size);
  printf("The largest value in the array is: %d\n", largest);

  return 0;
}