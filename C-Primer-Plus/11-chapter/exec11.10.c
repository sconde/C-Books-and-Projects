#include <stdio.h>
// #include <string.h>

// Function to remove all spaces from a string
void remove_spaces(char *str) {
  char *out = str; // Pointer to the next write position in the string
  for (; *str != '\0'; str++) {
    if (*str != ' ') {
      *out++ = *str; // Only copy non-space characters
    }
  }
  *out = '\0'; // Null-terminate the modified string
}

int main() {
  char str[100]; // Array to hold input strings

  printf("Enter strings, an empty line to exit:\n");
  while (fgets(str, sizeof(str), stdin)) {
    // Check for empty line (just a newline character)
    if (str[0] == '\n') {
      break;
    }

    remove_spaces(str); // Remove spaces from the string
    printf("String without spaces: '%s'\n", str);
  }

  return 0;
}
