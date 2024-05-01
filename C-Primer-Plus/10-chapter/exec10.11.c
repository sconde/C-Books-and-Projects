#include <stdio.h>

void displayArray(int arr[][5], int rows) {
  printf("Array values:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void doubleArray(int arr[][5], int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 5; j++) {
      arr[i][j] *= 2;
    }
  }
}

int main() {
  int arr[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};

  displayArray(arr, 3);
  doubleArray(arr, 3);
  displayArray(arr, 3);

  return 0;
}