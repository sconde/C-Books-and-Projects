#include <stdio.h>

int main() {
  char lowercase[26];
  int i;

  // Store the lowercase letters in the array
  for (i = 0; i < 26; i++) {
    lowercase[i] = 'a' + i;
  }

  // Display the contents of the array
  for (i = 0; i < 26; i++) {
    printf("%c ", lowercase[i]);
  }

  return 0;
}