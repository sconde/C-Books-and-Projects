#include <stdio.h>

int main() {
  int lower, upper;
  int sum;

  printf("Enter lower and upper integer limits: ");
  while (scanf("%d %d", &lower, &upper) == 2) {
    if (upper <= lower) {
      printf("Done\n");
      break;
    }

    sum = 0;
    for (int i = lower; i <= upper; i++) {
      sum += i * i;
    }

    printf("The sum of the squares from %d to %d is %d\n", lower * lower,
           upper * upper, sum);
    printf("Enter next set of limits: ");
  }

  return 0;
}
