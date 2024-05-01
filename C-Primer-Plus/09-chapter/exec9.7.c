#include <stdio.h>

int getAlphabeticalPosition(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    if (c >= 'a' && c <= 'z') {
      return c - 'a' + 1;
    } else {
      return c - 'A' + 1;
    }
  }
  return -1;
}

int main() {
  char c;
  while ((c = getchar()) != EOF) {
    if (getAlphabeticalPosition(c) != -1) {
      printf(
          "'%c' is a letter. Its numerical position in the alphabet is %d.\n",
          c, getAlphabeticalPosition(c));
    } else {
      printf("'%c' is not a letter.\n", c);
    }
  }
  return 0;
}