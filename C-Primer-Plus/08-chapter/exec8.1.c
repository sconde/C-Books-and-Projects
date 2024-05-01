#include <stdio.h>

int main() {
  int count = 0;
  char ch;

  while ((ch = getchar()) != EOF) {
    count++;
  }

  printf("Number of characters: %d\n", count);

  return 0;
}