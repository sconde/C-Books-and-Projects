#include <stdio.h>

int main() {
  int num, even_count = 0, odd_count = 0;
  int even_sum = 0, odd_sum = 0;
  float even_avg, odd_avg;

  printf("Enter integers (enter 0 to terminate):\n");

  while (1) {
    scanf("%d", &num);

    if (num == 0) {
      break;
    }

    if (num % 2 == 0) {
      even_count++;
      even_sum += num;
    } else {
      odd_count++;
      odd_sum += num;
    }
  }

  even_avg = (even_count > 0) ? (float)even_sum / even_count : 0;
  odd_avg = (odd_count > 0) ? (float)odd_sum / odd_count : 0;

  printf("Total even integers: %d\n", even_count);
  printf("Average value of even integers: %.2f\n", even_avg);
  printf("Total odd integers: %d\n", odd_count);
  printf("Average value of odd integers: %.2f\n", odd_avg);

  return 0;
}