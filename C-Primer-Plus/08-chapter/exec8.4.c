#include <ctype.h>
#include <stdio.h>

int main() {
  int character;
  int wordCount = 0;
  int letterCount = 0;
  int inWord = 0;

  printf("Enter some text: ");

  while ((character = getchar()) != EOF) {
    if (isalpha(character)) {
      letterCount++;
      if (!inWord) {
        inWord = 1;
        wordCount++;
      }
    } else {
      inWord = 0;
    }
  }

  double averageLetters = (double)letterCount / wordCount;

  printf("Average number of letters per word: %.2f\n", averageLetters);

  return 0;
}