#include <stdio.h>

int main() {
  int c;
  int count = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      printf("'\\n' %d ", c);
    } else if (c == '\t') {
      printf("'\\t' %d ", c);
    } else if (c < 32) {
      // Control characters (non-printable)
      printf("'^%c' %d ", c + 64, c);
    } else if (c == 32) {
      // Space character
      printf("' ' %d ", c);
    } else {
      // Printable characters
      printf("'%c' %d ", c, c);
    }

    count++;
    if (count % 10 == 0) {
      printf("\n");
    }

    if (c == '\n') {
      count = 0; // Reset count after a newline for fresh line
    }
  }

  return 0;
}
