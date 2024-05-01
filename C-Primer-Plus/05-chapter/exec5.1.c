#include <stdio.h>

#define MINUTES_PER_HOUR 60

int main() {
  int minutes;

  while (1) {
    printf("Enter time in minutes (0 or less to exit): ");
    scanf("%d", &minutes);

    if (minutes <= 0) {
      break;
    }

    int hours = minutes / MINUTES_PER_HOUR;
    int remainingMinutes = minutes % MINUTES_PER_HOUR;

    printf("%d minutes is equivalent to %d hours and %d minutes.\n", minutes,
           hours, remainingMinutes);
  }

  printf("Program exited.\n");

  return 0;
}