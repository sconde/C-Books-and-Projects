#include <stdio.h>

int main() {
  int num;

  printf("Enter an integer: ");
  scanf("%d", &num);

  for (int i = num; i <= num + 10; i++) {
    printf("%d ", i);
  }

  return 0;
}