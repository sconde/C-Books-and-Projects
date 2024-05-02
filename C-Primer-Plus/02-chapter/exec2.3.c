#include <stdio.h>
enum { DAYS_IN_YEAR = 365 };

int main() {
  int ageInYears = 0;
  int ageInDays = 0;

  printf("Enter your age in years: ");
  scanf("%d", &ageInYears);

  ageInDays = ageInYears * DAYS_IN_YEAR;

  printf("Your age in years: %d\n", ageInYears);
  printf("Your age in days: %d\n", ageInDays);

  return 0;
}