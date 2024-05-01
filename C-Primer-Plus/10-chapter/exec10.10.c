#include <stdio.h>

void sumArrays(int arr1[], int arr2[], int arr3[], int size) {
  for (int i = 0; i < size; i++) {
    arr3[i] = arr1[i] + arr2[i];
  }
}

int main() {
  int arr1[] = {2, 4, 5, 8};
  int arr2[] = {1, 0, 4, 6};
  int arr3[4];

  int size = sizeof(arr1) / sizeof(arr1[0]);

  sumArrays(arr1, arr2, arr3, size);

  printf("Array 3: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr3[i]);
  }
  printf("\n");

  return 0;
}