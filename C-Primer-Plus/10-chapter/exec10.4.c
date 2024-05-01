#include <stdio.h>

int findLargestIndex(double arr[], int size) {
  int largestIndex = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i] > arr[largestIndex]) {
      largestIndex = i;
    }
  }
  return largestIndex;
}

int main() {
  double numbers[] = {1.2, 3.4, 5.6, 2.8, 4.0};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  int largestIndex = findLargestIndex(numbers, size);
  printf("The largest value is at index %d\n", largestIndex);
  return 0;
}