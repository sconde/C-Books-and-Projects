#include <stdio.h>

// Reads the first word from a line of input into an array up to a specified
// length and discards the rest of the line
void read_first_word(char *array, int max_chars) {
  int ch, index = 0;

  // Skip leading whitespace
  while ((ch = getchar()) != EOF && (ch == ' ' || ch == '\t' || ch == '\n'))
    ;

  // Read the word, respecting the maximum character limit
  while (ch != EOF && ch != ' ' && ch != '\t' && ch != '\n' &&
         index < max_chars - 1) {
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
  char myWord[50]; // Array to hold the first word
  int max_length =
      sizeof(myWord) / sizeof(myWord[0]); // Maximum number of characters that
                                          // can be read into the array

  printf("Enter a line of text (max %d characters for the first word):\n",
         max_length - 1);
  read_first_word(myWord, max_length);

  printf("The first word is: \"%s\"\n", myWord);

  return 0;
}
