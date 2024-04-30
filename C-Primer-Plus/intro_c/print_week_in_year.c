#include <stdio.h>

int main(void) {
  int days;
  printf("Enter the number of days: ");
  scanf("%d", &days);
  printf("%d days are %d weeks, %d days.\n", days, days / 7, days % 7);
  return 0;
}