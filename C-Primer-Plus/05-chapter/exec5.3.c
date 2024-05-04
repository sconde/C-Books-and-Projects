#include <stdio.h>
enum { DAYS_IN_WEEK = 7 };

int main() {
  int days;

  while (1) {
    printf("Enter the number of days (0 or negative value to exit): ");
    scanf("%d", &days);

    if (days <= 0) {
      break;
    }

    int weeks = days / DAYS_IN_WEEK;

    int remainingDays = days % DAYS_IN_WEEK;

    printf("%d days are %d weeks, %d days.\n", days, weeks, remainingDays);
  }

  return 0;
}