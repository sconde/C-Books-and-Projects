#include <stdio.h>

int main() {
  int age;
  long seconds;

  printf("Enter your age in years: ");
  scanf("%d", &age);

  seconds = age * 31560000; // 1 year = 31560000 seconds

  printf("Equivalent number of seconds: %ld\n", seconds);

  return 0;
}