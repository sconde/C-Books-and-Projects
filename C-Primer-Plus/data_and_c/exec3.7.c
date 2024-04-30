#include <stdio.h>

int main() {
  double inches, centimeters;

  printf("Enter your height in inches: ");
  scanf("%lf", &inches);

  centimeters = inches * 2.54;

  printf("Your height in centimeters is: %.2lf\n", centimeters);

  return 0;
}