#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Function that checks if a character is within a string
bool is_within(const char *str, char c) {
  while (*str != '\0') { // Loop through the string until the end
    if (*str == c) {
      return true; // Return true if the character is found
    }
    str++; // Move to the next character
  }
  return false; // Return false if the character is not found
}

int main() {
  char str[100];
  char ch;
  bool found;

  while (1) {
    printf("Enter a string (or 'quit' to exit): ");
    fgets(str, sizeof(str), stdin); // Read a line from stdin

    // Check if the user wants to quit
    if (strncmp(str, "quit\n", 5) == 0) {
      break; // Break the loop if 'quit' is entered
    }

    printf("Enter a character to find: ");
    scanf("%c", &ch);
    // Clear the newline character left in the input buffer
    while (getchar() != '\n')
      ;

    found = is_within(str, ch);
    if (found) {
      printf("Character '%c' is within the string.\n", ch);
    } else {
      printf("Character '%c' is not within the string.\n", ch);
    }
  }

  return 0;
}
