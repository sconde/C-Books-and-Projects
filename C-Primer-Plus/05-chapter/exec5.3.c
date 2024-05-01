#include <stdio.h>

int main() {
  int days;

  while (1) {
    printf("Enter the number of days (0 or negative value to exit): ");
    scanf("%d", &days);

    if (days <= 0) {
      break;
    }

    int weeks = days / 7;
    int remainingDays = days % 7;

    printf("%d days are %d weeks, %d days.\n", days, weeks, remainingDays);
  }

  return 0;
}