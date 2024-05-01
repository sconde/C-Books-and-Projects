#include <stdio.h>

double harmonic_mean(double num1, double num2) {
  double inverse_sum = (1 / num1) + (1 / num2);
  double harmonic_mean = 2 / inverse_sum;
  return harmonic_mean;
}

int main() {
  double num1, num2;
  printf("Enter two numbers: ");
  scanf("%lf %lf", &num1, &num2);
  double result = harmonic_mean(num1, num2);
  printf("The harmonic mean is: %lf\n", result);
  return 0;
}