#include <stdio.h>

int fetch_chars(char *array, int n) {
  int ch, count = 0;

  while (count < n && (ch = getchar()) != EOF) {
    array[count++] = ch;
  }

  return count; // Return the number of characters actually read
}

int main() {
  int n = 10;       // Number of characters to read
  char myArray[10]; // Array to hold the characters

  printf("Enter text (fetching %d characters): ", n);
  int numRead = fetch_chars(myArray, n);

  printf("\nRead %d characters: ", numRead);
  for (int i = 0; i < numRead; i++) {
    putchar(myArray[i]);
  }
  printf("\n");

  return 0;
}
