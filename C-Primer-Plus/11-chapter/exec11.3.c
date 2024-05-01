#include <stdio.h>

// Reads the first word from a line of input into an array and discards the rest
// of the line
void read_first_word(char *array, int max_length) {
  int ch, index = 0;

  // Skip leading whitespace
  while ((ch = getchar()) != EOF && (ch == ' ' || ch == '\t' || ch == '\n'))
    ;

  // Read the word
  while (ch != EOF && ch != ' ' && ch != '\t' && ch != '\n' &&
         index < max_length - 1) {
    array[index++] = ch;
    ch = getchar();
  }
  array[index] = '\0'; // Null-terminate the string

  // Discard the rest of the line
  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

int main() {
  char myWord[100]; // Array to hold the first word

  printf("Enter a line of text:\n");
  read_first_word(myWord, 100);

  printf("The first word is: \"%s\"\n", myWord);

  return 0;
}
