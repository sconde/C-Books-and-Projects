#include <stdio.h>

double power(double base, int exponent) {
  // Handle zero cases
  if (base == 0) {
    if (exponent == 0) {
      printf("Warning: 0 to the power of 0 is undefined. Using 1.\n");
      return 1; // Mathematical convention
    } else if (exponent > 0) {
      return 0;
    } else {
      printf("Error: Division by zero condition! Returning 1.\n");
      return 1; // Division by zero
    }
  }

  // Base cases for recursion
  if (exponent == 0)
    return 1;
  if (exponent == 1)
    return base;
  if (exponent == -1)
    return 1 / base;

  // Recursive case: split the work of exponentiation
  if (exponent > 0) {
    return base * power(base, exponent - 1);
  } else {
    return (1 / base) * power(base, exponent + 1);
  }
}

int main() {
  double base;
  int exponent;

  printf("Enter base: ");
  scanf("%lf", &base);
  printf("Enter exponent (integer): ");
  scanf("%d", &exponent);

  double result = power(base, exponent);
  printf("%.2lf to the power of %d is %.2lf\n", base, exponent, result);

  return 0;
}
