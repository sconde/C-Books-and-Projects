#include <stdio.h>

void sortValues(double *a, double *b, double *c) {
  double temp;

  // Sort the values in ascending order
  if (*a > *b) {
    temp = *a;
    *a = *b;
    *b = temp;
  }
  if (*b > *c) {
    temp = *b;
    *b = *c;
    *c = temp;
  }
  if (*a > *b) {
    temp = *a;
    *a = *b;
    *b = temp;
  }
}

int main() {
  double num1, num2, num3;

  printf("Enter three numbers: ");
  scanf("%lf %lf %lf", &num1, &num2, &num3);

  sortValues(&num1, &num2, &num3);

  printf("Sorted values: %.2lf, %.2lf, %.2lf\n", num1, num2, num3);

  return 0;
}