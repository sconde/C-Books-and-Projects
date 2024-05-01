#include <stdio.h>

int main() {
  char ch;
  int count = 0;

  printf("Enter input (terminate with #):\n");

  while ((ch = getchar()) != '#') {
    printf("%c - %d\t", ch, ch);
    count++;

    if (count % 8 == 0) {
      printf("\n");
    }
  }

  return 0;
}