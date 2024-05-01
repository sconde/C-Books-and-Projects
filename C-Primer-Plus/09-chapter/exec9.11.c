#include <stdio.h>

int fibonacci(int n) {
  int first = 0, second = 1, next, i;

  if (n == 0)
    return first;

  for (i = 2; i <= n; i++) {
    next = first + second;
    first = second;
    second = next;
  }

  return second;
}

int main() {
  int n;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  printf("Fibonacci series up to %d terms:\n", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }

  return 0;
}