#include <stdio.h>

void reverseArray(double arr[], int size) {
  int i, j;
  double temp;

  for (i = 0, j = size - 1; i < j; i++, j--) {
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

int main() {
  double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int i;

  printf("Original array: ");
  for (i = 0; i < size; i++) {
    printf("%.1f ", arr[i]);
  }

  reverseArray(arr, size);

  printf("\nReversed array: ");
  for (i = 0; i < size; i++) {
    printf("%.1f ", arr[i]);
  }

  return 0;
}