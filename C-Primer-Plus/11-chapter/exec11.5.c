#include <stdio.h>
#include <string.h>

// Function that searches for the first occurrence of a character in a string
char *my_strchr(const char *str, int c) {
  while (*str != '\0') { // Continue until the end of the string
    if (*str == (char)c) {
      return (char *)str; // Return the pointer to the found character
    }
    str++; // Move to the next character
  }
  return NULL; // Return NULL if the character is not found
}

int main() {
  char str[100];
  char ch;
  char *found;

  while (1) {
    printf("Enter a string (or 'quit' to exit): ");
    fgets(str, sizeof(str), stdin); // Read a line from stdin
    // Check for the 'quit' command
    if (strncmp(str, "quit\n", 5) == 0) {
      break; // Exit the loop if user types "quit"
    }

    printf("Enter a character to find: ");
    scanf("%c", &ch);
    // Clear the newline character left in the input buffer
    while (getchar() != '\n')
      ;

    found = my_strchr(str, ch);
    if (found != NULL) {
      printf("Character '%c' found at position: %ld\n", ch, found - str);
    } else {
      printf("Character '%c' not found in the string.\n", ch);
    }
  }

  return 0;
}
