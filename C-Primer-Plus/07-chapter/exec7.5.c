#include <stdio.h>

int main() {
  char ch;
  int substitutions = 0;

  printf("Enter a string (terminate with #): ");

  while ((ch = getchar()) != '#') {
    switch (ch) {
    case '.':
      putchar('!');
      substitutions++;
      break;
    case '!':
      putchar('!');
      putchar('!');
      substitutions++;
      break;
    default:
      putchar(ch);
      break;
    }
  }

  printf("\nNumber of substitutions: %d\n", substitutions);

  return 0;
}