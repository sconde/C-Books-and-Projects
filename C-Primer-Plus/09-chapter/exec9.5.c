#include <stdio.h>

void larger_of(double *x, double *y) {
  if (*x > *y) {
    *y = *x;
  } else {
    *x = *y;
  }
}

int main() {
  double x = 5.7;
  double y = 3.2;

  printf("Before: x = %.2f, y = %.2f\n", x, y);
  larger_of(&x, &y);
  printf("After: x = %.2f, y = %.2f\n", x, y);

  return 0;
}