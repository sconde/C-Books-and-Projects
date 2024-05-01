#include <stdio.h>

int main() {
  int n = 1;     // Number of characters to print in a row
  char ch = 'A'; // Starting character

  for (int i = 1; i <= 6; i++) { // There are 6 rows as per the pattern given
    for (int j = 1; j <= n; j++) {
      printf("%c", ch);
      ch++; // Move to the next character
    }
    printf("\n");
    n++; // Increase the number of characters for the next row
  }
  printf("\n");
  return 0;
}
