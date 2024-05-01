#include <float.h>
#include <stdio.h>

int main() {
  double d = 1.0 / 3.0;
  float f = 1.0f / 3.0f;

  printf("Double with 4 digits: %.4lf\n", d);
  printf("Double with 12 digits: %.12lf\n", d);
  printf("Double with 16 digits: %.16lf\n", d);

  printf("Float with 4 digits: %.4f\n", f);
  printf("Float with 12 digits: %.12f\n", f);
  printf("Float with 16 digits: %.16f\n", f);

  printf("FLT_DIG: %d\n", FLT_DIG);
  printf("DBL_DIG: %d\n", DBL_DIG);

  return 0;
}