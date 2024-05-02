#include <stdio.h>
enum { DAYS_IN_WEEK = 7 };

int main(void) {
  int days = 0;
  printf("Enter the number of days: ");
  scanf("%d", &days);

  printf("%d days are %d weeks, %d days.\n", days, days / DAYS_IN_WEEK,
         days % DAYS_IN_WEEK);
  return 0;
}