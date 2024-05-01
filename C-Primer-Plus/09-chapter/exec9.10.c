#include <stdio.h>

void to_base_n(int number, int base) {
  int r;

  if (base < 2 || base > 10) {
    printf("Base must be between 2 and 10.\n");
    return;
  }

  r = number % base;
  if (number >= base) {
    to_base_n(number / base, base);
  }
  printf("%d", r);
}

int main() {
  int number, base;

  printf("Enter a number: ");
  scanf("%d", &number);
  printf("Enter the base (2-10): ");
  scanf("%d", &base);

  printf("The base-%d equivalent of %d is ", base, number);
  to_base_n(number, base);
  printf("\n");

  return 0;
}
