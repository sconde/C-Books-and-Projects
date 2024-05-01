#include <stdio.h>

double power(double base, int exponent) {
  double result = 1.0;

  // Handling 0 raised to any power
  if (base == 0) {
    if (exponent == 0) {
      printf("Warning: 0 to the power of 0 is undefined. Using 1.\n");
      return 1; // Common mathematical convention
    } else if (exponent > 0) {
      return 0;
    } else {
      printf("Error: Division by zero condition! Returning 1.\n");
      return 1; // Handling 0 raised to a negative power, which is undefined
    }
  }

  // Handling positive and negative exponents
  if (exponent < 0) {
    base = 1 / base;
    exponent = -exponent;
  }

  for (int i = 0; i < exponent; i++) {
    result *= base;
  }

  return result;
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
