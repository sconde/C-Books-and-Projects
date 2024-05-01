#include <stdio.h>

int main() {
  char ch;
  int spaces = 0, newlines = 0, others = 0;

  printf("Enter input (terminate with '#'): ");

  while ((ch = getchar()) != '#') {
    if (ch == ' ') {
      spaces++;
    } else if (ch == '\n') {
      newlines++;
    } else {
      others++;
    }
  }

  printf("Number of spaces: %d\n", spaces);
  printf("Number of newlines: %d\n", newlines);
  printf("Number of other characters: %d\n", others);

  return 0;
}