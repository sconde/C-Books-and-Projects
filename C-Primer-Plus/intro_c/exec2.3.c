#include <stdio.h>

int main() {
  int ageInYears;
  int ageInDays;

  printf("Enter your age in years: ");
  scanf("%d", &ageInYears);

  ageInDays = ageInYears * 365;

  printf("Your age in years: %d\n", ageInYears);
  printf("Your age in days: %d\n", ageInDays);

  return 0;
}