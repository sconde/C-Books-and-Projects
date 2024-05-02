#include <stdio.h>
#include <time.h>

void delay(double seconds) {
  clock_t start = clock();
  clock_t delay_time = (clock_t)(seconds * CLOCKS_PER_SEC);

  while (clock() - start < delay_time) {
    // Do nothing, just loop until enough ticks have passed
  }
}

int main() {
  double delay_seconds;

  printf("Enter the number of seconds to delay: ");
  scanf("%lf", &delay_seconds);

  printf("Starting delay...\n");
  delay(delay_seconds);
  printf("Delay complete.\n");

  return 0;
}
