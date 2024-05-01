#include <stdbool.h>
#include <stdio.h>

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }

  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

void displayPrimes(int n) {
  printf("Prime numbers smaller than or equal to %d:\n", n);

  for (int i = 2; i <= n; i++) {
    if (isPrime(i)) {
      printf("%d ", i);
    }
  }

  printf("\n");
}

int main() {
  int num;

  printf("Enter a positive integer: ");
  scanf("%d", &num);

  displayPrimes(num);

  return 0;
}