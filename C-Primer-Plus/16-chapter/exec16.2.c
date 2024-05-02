#include <stdio.h>

#define HARMONIC_MEAN(x, y) (2.0 / ((1.0 / (x)) + (1.0 / (y))))

int main() {
  double num1, num2;

  printf("Enter two numbers: ");
  scanf("%lf %lf", &num1, &num2);

  double result = HARMONIC_MEAN(num1, num2);

  printf("The harmonic mean of %.2lf and %.2lf is %.2lf\n", num1, num2, result);

  return 0;
}