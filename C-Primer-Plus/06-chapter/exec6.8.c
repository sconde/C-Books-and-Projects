#include <stdio.h>

int main() {
  float num1, num2, result;

  printf("Enter pairs of floating-point numbers (or non-numeric to quit):\n");

  // The loop continues until scanf() does not read two floating-point numbers
  while (scanf("%f %f", &num1, &num2) == 2) {
    if (num2 != 0) { // Check to prevent division by zero
      result = (num1 - num2) / (num1 * num2);
      printf("Result of (%f - %f) / (%f * %f) = %f\n", num1, num2, num1, num2,
             result);
    } else {
      printf("The product of the numbers is zero, cannot divide by zero.\n");
    }
    printf("Enter next pair of numbers (or non-numeric to quit):\n");
  }

  printf("Non-numeric input detected, program will exit.\n");
  return 0;
}
