#include <stdio.h>

int fetch_chars_modified(char *array, int n) {
  int ch, count = 0;

  while (count < n && (ch = getchar()) != EOF) {
    array[count++] = ch;
    if (ch == ' ' || ch == '\t' || ch == '\n') {
      break; // Stop reading if a blank, tab, or newline is encountered
    }
  }

  return count; // Return the number of characters actually read
}

int main() {
  int n = 10; // Number of characters to read or until a space, tab, or newline
  char myArray[10]; // Array to hold the characters

  printf(
      "Enter text (stopping at %d characters or at a space, tab, or newline): ",
      n);
  int numRead = fetch_chars_modified(myArray, n);

  printf("\nRead %d characters: ", numRead);
  for (int i = 0; i < numRead; i++) {
    putchar(myArray[i]);
  }
  printf("\n");

  return 0;
}
