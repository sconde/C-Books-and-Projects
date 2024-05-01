#include <stdio.h>

int main() {
  char start = 'F';
  for (int i = 0; i <= (start - 'A'); i++) {
    for (int j = 0; j <= i; j++) {
      printf("%c", start - j);
    }
    printf("\n");
  }
  return 0;
}
