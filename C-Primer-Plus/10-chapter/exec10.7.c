#include <stdio.h>

// Function to copy one-dimensional array
void copyArray(double *source, double *destination, int size) {
  for (int i = 0; i < size; i++) {
    destination[i] = source[i];
  }
}

// Function to copy two-dimensional array
void copy2DArray(double source[][3], double destination[][3], int rows,
                 int cols) {
  for (int i = 0; i < rows; i++) {
    copyArray(source[i], destination[i], cols);
  }
}

int main() {
  // Initialize the source array
  double sourceArray[][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};

  // Declare the destination array
  double destinationArray[3][3];

  // Copy the source array to the destination array
  copy2DArray(sourceArray, destinationArray, 3, 3);

  // Print the destination array
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%.1f ", destinationArray[i][j]);
    }
    printf("\n");
  }

  return 0;
}