#include <stdio.h>

double cube(double num) { return num * num * num; }

int main() {
  double number;

  printf("Enter a number: ");
  scanf("%lf", &number);

  double result = cube(number);

  printf("The cube of %.2lf is %.2lf\n", number, result);

  return 0;
}