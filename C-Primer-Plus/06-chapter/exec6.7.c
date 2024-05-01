#include <stdio.h>
#include <string.h> // Include for strlen()

int main() {
  char word[100]; // Character array to store the word

  printf("Enter a word: ");
  scanf("%s", word); // Read a single word into the array

  int length = strlen(word); // Get the length of the word

  printf("The word backwards is: ");
  for (int i = length - 1; i >= 0; i--) {
    putchar(word[i]); // Print each character in reverse order
  }
  printf("\n");

  return 0;
}
