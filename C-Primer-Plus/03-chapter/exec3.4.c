#include <math.h>
#include <stdio.h>

int main() {
  double num = NAN;

  printf("Enter a floating-point value: ");
  scanf("%lf", &num);

  printf("fixed-point notation: %.6f\n", num);
  printf("exponential notation: %e\n", num);
  printf("p notation: %a\n", num);

  return 0;
}