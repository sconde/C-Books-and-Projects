#include <stdio.h>

enum { ARRAY_SIZE = 26 };

int main() {
  char lowercase[ARRAY_SIZE];
  int i = 0;

  // Store the lowercase letters in the array
  for (i = 0; i < ARRAY_SIZE; i++) {
    lowercase[i] = (char)('a' + i);
  }

  // Display the contents of the array
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%c ", lowercase[i]);
  }

  return 0;
}