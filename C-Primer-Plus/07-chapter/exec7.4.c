#include <stdio.h>

int main() {
  char ch;
  int substitutions = 0;

  printf("Enter some text (# to quit):\n");

  while ((ch = getchar()) != '#') {
    if (ch == '.') {
      putchar('!');
      substitutions++;
    } else if (ch == '!') {
      putchar('!');
      putchar('!');
      substitutions++;
    } else {
      putchar(ch);
    }
  }

  printf("\nNumber of substitutions made: %d\n", substitutions);

  return 0;
}