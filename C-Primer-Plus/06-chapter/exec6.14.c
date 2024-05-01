#include <stdio.h>

int main() {
  double firstArray[8];
  double secondArray[8];

  // Input values for the first array
  printf("Enter values for the first array:\n");
  for (int i = 0; i < 8; i++) {
    printf("Enter value for element %d: ", i + 1);
    scanf("%lf", &firstArray[i]);
  }

  // Calculate cumulative totals for the second array
  secondArray[0] = firstArray[0];
  for (int i = 1; i < 8; i++) {
    secondArray[i] = secondArray[i - 1] + firstArray[i];
  }

  // Display the contents of the two arrays
  printf("\nFirst Array: ");
  for (int i = 0; i < 8; i++) {
    printf("%.2lf ", firstArray[i]);
  }

  printf("\nSecond Array: ");
  for (int i = 0; i < 8; i++) {
    printf("%.2lf ", secondArray[i]);
  }

  return 0;
}