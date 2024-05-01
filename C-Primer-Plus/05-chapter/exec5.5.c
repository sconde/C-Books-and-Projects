#include <stdio.h>

int main(void) {
  int count, sum, num;

  printf("Enter the number of integers to calculate the sum for: ");
  scanf("%d", &count);

  sum = 0;
  num = 1;

  while (num <= count) {
    sum = sum + num;
    num++;
  }

  printf("The sum of the first %d integers is %d\n", count, sum);

  return 0;
}