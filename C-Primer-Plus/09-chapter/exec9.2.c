#include <stdio.h>

void chline(char ch, int i, int j) {
  int col;

  for (col = 1; col < i; col++) {
    printf(" ");
  }

  for (; col <= j; col++) {
    printf("%c", ch);
  }

  printf("\n");
}

int main() {
  chline('*', 3, 7);
  chline('#', 1, 5);
  chline('@', 2, 4);

  return 0;
}