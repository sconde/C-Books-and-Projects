#include <stdio.h>
#define SECONDS_PER_YEAR 31560000  // 1 year = SECONDS_PER_YEAR seconds

int main() {
  int age = 0;
  long seconds = 0;

  printf("Enter your age in years: ");
  scanf("%d", &age);

  seconds = age * SECONDS_PER_YEAR;
  printf("Equivalent number of seconds: %ld\n", seconds);

  return 0;
}