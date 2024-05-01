#include <stdio.h>

void copyArray(int rows, int cols, double source[rows][cols],
               double target[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      target[i][j] = source[i][j];
    }
  }
}

void displayArray(int rows, int cols, double array[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%f ", array[i][j]);
    }
    printf("\n");
  }
}

int main() {
  double source[3][5] = {{1.1, 2.2, 3.3, 4.4, 5.5},
                         {6.6, 7.7, 8.8, 9.9, 10.1},
                         {11.11, 12.12, 13.13, 14.14, 15.15}};

  double target[3][5];

  copyArray(3, 5, source, target);

  printf("Source array:\n");
  displayArray(3, 5, source);

  printf("\nTarget array:\n");
  displayArray(3, 5, target);

  return 0;
}