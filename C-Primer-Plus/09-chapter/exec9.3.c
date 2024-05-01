#include <stdio.h>

void printCharacter(char ch, int numChars, int numLines) {
  for (int i = 0; i < numLines; i++) {
    for (int j = 0; j < numChars; j++) {
      printf("%c", ch);
    }
    printf("\n");
  }
}

int main() {
  char character;
  int numChars, numLines;

  printf("Enter a character: ");
  scanf("%c", &character);

  printf("Enter the number of characters per line: ");
  scanf("%d", &numChars);

  printf("Enter the number of lines: ");
  scanf("%d", &numLines);

  printCharacter(character, numChars, numLines);

  return 0;
}