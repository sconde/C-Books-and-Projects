#include <ctype.h>
#include <stdio.h>

int main() {
  int ch;
  int uppercaseCount = 0;
  int lowercaseCount = 0;
  int otherCount = 0;

  printf("Enter a stream of characters (Ctrl+D to end):\n");

  while ((ch = getchar()) != EOF) {
    if (isupper(ch)) {
      uppercaseCount++;
    } else if (islower(ch)) {
      lowercaseCount++;
    } else {
      otherCount++;
    }
  }

  printf("Number of uppercase letters: %d\n", uppercaseCount);
  printf("Number of lowercase letters: %d\n", lowercaseCount);
  printf("Number of other characters: %d\n", otherCount);

  return 0;
}