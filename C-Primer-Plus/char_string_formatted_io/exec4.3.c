#include <stdio.h>

int main() {
  float number;

  printf("Enter a floating-point number: ");
  scanf("%f", &number);

  printf("The input is %.1f or %.1e.\n", number, number);
  printf("The input is %+10.3f or %.3E.\n", number, number);

  return 0;
}