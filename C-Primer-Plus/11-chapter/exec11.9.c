#include <stdio.h>
#include <string.h>

// Function to reverse a string in place
void reverse_string(char *str) {
  int i = 0;
  int j = strlen(str) - 1;

  while (i < j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

int main() {
  char str[100]; // Array to hold input strings

  while (1) {
    printf("Enter a string to reverse (or 'quit' to exit): ");
    fgets(str, sizeof(str), stdin);

    // Check if the user wants to quit
    if (strncmp(str, "quit", 4) == 0) {
      break;
    }

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    reverse_string(str); // Reverse the string
    printf("Reversed string: %s\n", str);
  }

  return 0;
}
