#include <stdio.h>

double min(double x, double y) { return (x < y) ? x : y; }

int main() {
  double a = 3.14;
  double b = 2.71;
  double result = min(a, b);

  printf("The smaller value is: %lf\n", result);

  return 0;
}
