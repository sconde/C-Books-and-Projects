#include <stdio.h>
#include <string.h>

// Function that mimics the behavior of strncpy
char *mystrncpy(char *s1, const char *s2, size_t n) {
  size_t i;
  for (i = 0; i < n && s2[i] != '\0'; i++) {
    s1[i] = s2[i];
  }
  for (; i < n; i++) {
    s1[i] = '\0';
  }
  return s1;
}

int main() {
  char dest[100]; // Destination string array
  char src[100];  // Source string array
  size_t num;

  while (1) {
    printf("Enter source string (or 'quit' to exit): ");
    fgets(src, sizeof(src), stdin);

    // Check if the user wants to quit
    if (strncmp(src, "quit\n", 5) == 0) {
      break;
    }

    // Remove newline character from fgets input
    src[strcspn(src, "\n")] = '\0';

    printf("Enter number of characters to copy: ");
    scanf("%zu", &num);
    // Clear the newline character left in the input buffer
    while (getchar() != '\n')
      ;

    mystrncpy(dest, src, num);

    // Output the destination string with visual aids for null characters
    printf("Copied string: '");
    for (size_t i = 0; i < num; i++) {
      if (dest[i] == '\0') {
        printf("\\0");
      } else {
        putchar(dest[i]);
      }
    }
    printf("'\n");
  }

  return 0;
}
