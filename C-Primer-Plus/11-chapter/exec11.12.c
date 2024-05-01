#include <ctype.h>
#include <stdio.h>

int main() {
  int c; // Variable to hold input characters
  int numWords = 0, numUpper = 0, numLower = 0, numPunct = 0, numDigits = 0;
  int inWord = 0; // Flag to track whether we are inside a word

  printf("Enter text (Ctrl+D to end):\n");

  while ((c = getchar()) != EOF) {
    if (isupper(c)) {
      numUpper++;
    }
    if (islower(c)) {
      numLower++;
    }
    if (isdigit(c)) {
      numDigits++;
    }
    if (ispunct(c)) {
      numPunct++;
    }
    if (isspace(c) || ispunct(c)) {
      if (inWord) {
        numWords++;
        inWord = 0;
      }
    } else {
      inWord = 1;
    }
  }

  // If EOF is reached and the last character was part of a word
  if (inWord) {
    numWords++;
  }

  printf("\nSummary:\n");
  printf("Words: %d\n", numWords);
  printf("Uppercase Letters: %d\n", numUpper);
  printf("Lowercase Letters: %d\n", numLower);
  printf("Punctuation Characters: %d\n", numPunct);
  printf("Digits: %d\n", numDigits);

  return 0;
}
